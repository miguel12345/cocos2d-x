/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "platform/CCPlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#include "UIWebViewImpl-mac.h"
#include "renderer/CCRenderer.h"
#include "base/CCDirector.h"
#include "platform/CCGLView.h"
#include "platform/CCFileUtils.h"
#include "ui/UIWebView.h"
#import <WebKit/WebKit.h>

@interface UIWebViewWrapper : NSObject
@property (nonatomic) std::function<bool(std::string url)> shouldStartLoading;
@property (nonatomic) std::function<void(std::string url)> didFinishLoading;
@property (nonatomic) std::function<void(std::string url)> didFailLoading;
@property (nonatomic) std::function<void(std::string url)> onJsCallback;

@property(nonatomic, readonly, getter=canGoBack) BOOL canGoBack;
@property(nonatomic, readonly, getter=canGoForward) BOOL canGoForward;

+ (instancetype)webViewWrapper;

- (void)setVisible:(bool)visible;

- (void)setFrameWithX:(float)x y:(float)y width:(float)width height:(float)height;

- (void)setJavascriptInterfaceScheme:(const std::string &)scheme;

- (void)loadData:(const std::string &)data MIMEType:(const std::string &)MIMEType textEncodingName:(const std::string &)encodingName baseURL:(const std::string &)baseURL;

- (void)loadHTMLString:(const std::string &)string baseURL:(const std::string &)baseURL;

- (void)loadUrl:(const std::string &)urlString;

- (void)loadFile:(const std::string &)filePath;

- (void)stopLoading;

- (void)reload;

- (void)evaluateJS:(const std::string &)js;

- (void)goBack;

- (void)goForward;

- (void)setScalesPageToFit:(const bool)scalesPageToFit;

- (void)handleSchemeCaptured:(NSURLRequest*) request;

@end


@interface NSURLProtocolInterceptScheme : NSURLProtocol<NSURLConnectionDelegate>
@property (nonatomic, strong) NSURLConnection *connection;
+(void) setDelegate:(id) delegate;

@end

@implementation NSURLProtocolInterceptScheme

static id _delegate = nil;

+(void) setDelegate:(id) delegate {
    _delegate = delegate;
}

+ (BOOL) canInitWithRequest:(NSURLRequest*)request
{
    if (!_delegate) {
        return NO;
    }
    
    if (![NSThread isMainThread]) {
        return NO;
    }
    
    NSString* captureScheme = [_delegate jsScheme];
    
    if ([captureScheme isEqualToString:[[request URL] scheme]]) {
        [_delegate handleSchemeCaptured:request];
        
        return YES;
    }
    
    return NO;
}

+ (NSURLRequest *)canonicalRequestForRequest:(NSURLRequest *)request {
    return request;
}

+ (BOOL)requestIsCacheEquivalent:(NSURLRequest *)a toRequest:(NSURLRequest *)b {
    return [super requestIsCacheEquivalent:a toRequest:b];
}

- (void)startLoading {
    self.connection = [NSURLConnection connectionWithRequest:self.request delegate:self];
}

- (void)stopLoading {
    [self.connection cancel];
    self.connection = nil;
}


@end

@interface NSWindowAutoResizable : NSWindow

-(void) startListeningForParentResize;
-(void) stopListeningForParentResize;

@end

@implementation NSWindowAutoResizable

-(void) startListeningForParentResize {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(parentWindowDidResize:) name:NSWindowDidResizeNotification object:self.parentWindow];
}

-(void) parentWindowDidResize:(NSNotification*) notification {
    
    CGRect frame = CGRectMake(self.parentWindow.frame.origin.x,self.parentWindow.frame.origin.y, ((NSView*)self.parentWindow.contentView).frame.size.width, ((NSView*)self.parentWindow.contentView).frame.size.height);
    [self setFrame:frame display:YES];
    [self setFrameOrigin:NSMakePoint(self.parentWindow.frame.origin.x,self.parentWindow.frame.origin.y)];
    [self viewsNeedDisplay];
}

-(void)stopListeningForParentResize {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowDidResizeNotification object:self.parentWindow];
}

@end

@interface UIWebViewWrapper ()/* <WebResourceLoadDelegate,
WebFrameLoadDelegate, WebPolicyDelegate> */
@property(nonatomic, retain) WebView *uiWebView;
@property(nonatomic, retain) NSWindowAutoResizable *uiWebViewWindow;
@property(nonatomic, copy) NSString *jsScheme;
@property(nonatomic) bool handledSchemeInJSEvaluation;
@end

@implementation UIWebViewWrapper {
    
}

+ (instancetype)webViewWrapper {
    return [[[self alloc] init] autorelease];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.uiWebView = nil;
        self.shouldStartLoading = nullptr;
        self.didFinishLoading = nullptr;
        self.didFailLoading = nullptr;
        self.handledSchemeInJSEvaluation = NO;
    }
    return self;
}

- (void)dealloc {
    self.uiWebView.frameLoadDelegate = nil;
    self.uiWebView.policyDelegate = nil;
    self.uiWebView.resourceLoadDelegate = nil;
    [[self.uiWebView mainFrame] loadHTMLString:nil baseURL:nil];
    [self.uiWebViewWindow stopListeningForParentResize];
    [[[NSApplication sharedApplication] mainWindow] removeChildWindow:self.uiWebViewWindow];
    self.uiWebViewWindow = nil;
    self.uiWebView = nil;
    self.jsScheme = nil;
    [NSURLProtocolInterceptScheme setDelegate:self];
    [NSURLProtocol unregisterClass:[NSURLProtocolInterceptScheme class]];
    [super dealloc];
}

- (void)setupWebView {
    
    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    NSWindow* appMainWindow = glView->getCocoaWindow();

    if (!self.uiWebView) {
        
        self.uiWebView = [[[WebView alloc] init] autorelease];
        self.uiWebView.frameLoadDelegate = self;
        self.uiWebView.policyDelegate = self;
        self.uiWebView.resourceLoadDelegate = self;
        
        
        CGRect wRect = appMainWindow.frame;
        NSView *contentView  = appMainWindow.contentView;
        CGRect cRect = contentView.frame;
        
        CGRect rect = CGRectMake(wRect.origin.x, wRect.origin.y, cRect.size.width, cRect.size.height);
        self.uiWebViewWindow = [[[NSWindowAutoResizable alloc]initWithContentRect:rect
                                                            styleMask:NSBorderlessWindowMask
                                                              backing:NSBackingStoreBuffered
                                                                defer:NO] autorelease];
        self.uiWebViewWindow.backgroundColor = [NSColor clearColor];
        [self.uiWebViewWindow setOpaque:NO];
        self.uiWebViewWindow.contentView = self.uiWebView;
        self.uiWebView.frame = CGRectMake(0, 0, 0, 0); //reset frame because previous line sets it to full screen
    }
    if (!self.uiWebViewWindow.parentWindow) {
        [appMainWindow addChildWindow:self.uiWebViewWindow ordered:NSWindowAbove];
        [self.uiWebViewWindow startListeningForParentResize];
    }
}

- (void)setVisible:(bool)visible {
    self.uiWebView.hidden = !visible;
}

- (void)setFrameWithX:(float)x y:(float)y width:(float)width height:(float)height {
    if (!self.uiWebView) {[self setupWebView];}
    CGRect newFrame = CGRectMake(x, y, width, height);
    if (!CGRectEqualToRect(self.uiWebView.frame, newFrame)) {
        self.uiWebView.frame = CGRectMake(x, y, width, height);
    }
}

- (void)setJavascriptInterfaceScheme:(const std::string &)scheme {
    [NSURLProtocolInterceptScheme setDelegate:self];
    [NSURLProtocol registerClass:[NSURLProtocolInterceptScheme class]];
    self.jsScheme = @(scheme.c_str());
}

- (void)loadData:(const std::string &)data MIMEType:(const std::string &)MIMEType textEncodingName:(const std::string &)encodingName baseURL:(const std::string &)baseURL {
    [[self.uiWebView mainFrame] loadData:[NSData dataWithBytes:data.c_str() length:data.length()]
                    MIMEType:@(MIMEType.c_str())
            textEncodingName:@(encodingName.c_str())
                     baseURL:[NSURL URLWithString:@(baseURL.c_str())]];
}

- (void)loadHTMLString:(const std::string &)string baseURL:(const std::string &)baseURL {
    [[self.uiWebView mainFrame] loadHTMLString:@(string.c_str()) baseURL:[NSURL URLWithString:@(baseURL.c_str())]];
}

- (void)loadUrl:(const std::string &)urlString {
    if (!self.uiWebView) {[self setupWebView];}
    NSURL *url = [NSURL URLWithString:@(urlString.c_str())];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [[self.uiWebView mainFrame] loadRequest:request];
}

- (void)loadFile:(const std::string &)filePath {
    if (!self.uiWebView) {[self setupWebView];}
    NSURL *url = [NSURL fileURLWithPath:@(filePath.c_str())];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [[self.uiWebView mainFrame] loadRequest:request];
}

- (void)stopLoading {
    [[self.uiWebView mainFrame] stopLoading];
}

- (void)reload {
    [[self.uiWebView mainFrame] reload];
}

- (BOOL)canGoForward {
    return self.uiWebView.canGoForward;
}

- (BOOL)canGoBack {
    return self.uiWebView.canGoBack;
}

- (void)goBack {
    [self.uiWebView goBack];
}

- (void)goForward {
    [self.uiWebView goForward];
}

- (void)evaluateJS:(const std::string &)js {
    self.handledSchemeInJSEvaluation = NO;
    if (!self.uiWebView) {[self setupWebView];}
    [self.uiWebView stringByEvaluatingJavaScriptFromString:@(js.c_str())];
    self.handledSchemeInJSEvaluation = NO;
}

- (void)setScalesPageToFit:(const bool)scalesPageToFit {
    //TODO
//    self.uiWebView.mainFrame.scalesPageToFit = scalesPageToFit;
}

- (void)handleSchemeCaptured:(NSURLRequest*) request {
    if (self.handledSchemeInJSEvaluation) {
        return;
    }
    self.handledSchemeInJSEvaluation = YES;
    NSString *url = [[request URL] absoluteString];
    self.onJsCallback([url UTF8String]);
}


- (NSURLRequest*) webView:(WebView*)sender
                 resource:(id)identifier
          willSendRequest:(NSURLRequest*)request
         redirectResponse:(NSURLResponse*)redirectResponse
           fromDataSource:(WebDataSource*)dataSource
{
    NSString* url = [[request URL] absoluteString];
    if (self.shouldStartLoading && url) {
        return self.shouldStartLoading([url UTF8String])?request:nil;
    }
    return request;
}

- (void)webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame {
    if (frame == [self.uiWebView mainFrame] &&self.didFinishLoading) {
        NSString *url = [[[[frame dataSource] request] URL] absoluteString];
        self.didFinishLoading([url UTF8String]);
    }
}

- (void)webView:(WebView *)sender didFailLoadWithError:(NSError *)error forFrame:(WebFrame *)frame {
    if (frame == [self.uiWebView mainFrame]) {
        if (self.didFailLoading) {
            NSString *url = error.userInfo[NSURLErrorFailingURLStringErrorKey];
            if (url) {
                self.didFailLoading([url UTF8String]);
            }
        }
    }
}

@end



namespace cocos2d {
namespace experimental {
    namespace ui{

WebViewImpl::WebViewImpl(WebView *webView)
        : _uiWebViewWrapper([UIWebViewWrapper webViewWrapper]),
        _webView(webView) {
    [_uiWebViewWrapper retain];
            
    _uiWebViewWrapper.shouldStartLoading = [this](std::string url) {
        if (this->_webView->_onShouldStartLoading) {
            return this->_webView->_onShouldStartLoading(this->_webView, url);
        }
        return true;
    };
    _uiWebViewWrapper.didFinishLoading = [this](std::string url) {
        if (this->_webView->_onDidFinishLoading) {
            this->_webView->_onDidFinishLoading(this->_webView, url);
        }
    };
    _uiWebViewWrapper.didFailLoading = [this](std::string url) {
        if (this->_webView->_onDidFailLoading) {
            this->_webView->_onDidFailLoading(this->_webView, url);
        }
    };
    _uiWebViewWrapper.onJsCallback = [this](std::string url) {
        if (this->_webView->_onJSCallback) {
            this->_webView->_onJSCallback(this->_webView, url);
        }
    };
}

WebViewImpl::~WebViewImpl(){
    
    _uiWebViewWrapper.shouldStartLoading = nullptr;
    _uiWebViewWrapper.didFinishLoading = nullptr;
    _uiWebViewWrapper.didFailLoading = nullptr;
    _uiWebViewWrapper.onJsCallback = nullptr;
    [_uiWebViewWrapper release];
    _uiWebViewWrapper = nullptr;
}

void WebViewImpl::setJavascriptInterfaceScheme(const std::string &scheme) {
    [_uiWebViewWrapper setJavascriptInterfaceScheme:scheme];
}

void WebViewImpl::loadData(const Data &data,
                           const std::string &MIMEType,
                           const std::string &encoding,
                           const std::string &baseURL) {
    
    std::string dataString(reinterpret_cast<char *>(data.getBytes()), static_cast<unsigned int>(data.getSize()));
    [_uiWebViewWrapper loadData:dataString MIMEType:MIMEType textEncodingName:encoding baseURL:baseURL];
}

void WebViewImpl::loadHTMLString(const std::string &string, const std::string &baseURL) {
    [_uiWebViewWrapper loadHTMLString:string baseURL:baseURL];
}

void WebViewImpl::loadURL(const std::string &url) {
    [_uiWebViewWrapper loadUrl:url];
}

void WebViewImpl::loadFile(const std::string &fileName) {
    auto fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(fileName);
    [_uiWebViewWrapper loadFile:fullPath];
}

void WebViewImpl::stopLoading() {
    [_uiWebViewWrapper stopLoading];
}

void WebViewImpl::reload() {
    [_uiWebViewWrapper reload];
}

bool WebViewImpl::canGoBack() {
    return _uiWebViewWrapper.canGoBack;
}

bool WebViewImpl::canGoForward() {
    return _uiWebViewWrapper.canGoForward;
}

void WebViewImpl::goBack() {
    [_uiWebViewWrapper goBack];
}

void WebViewImpl::goForward() {
    [_uiWebViewWrapper goForward];
}

void WebViewImpl::evaluateJS(const std::string &js) {
    [_uiWebViewWrapper evaluateJS:js];
}

void WebViewImpl::setScalesPageToFit(const bool scalesPageToFit) {
    [_uiWebViewWrapper setScalesPageToFit:scalesPageToFit];
}

void WebViewImpl::draw(cocos2d::Renderer *renderer, cocos2d::Mat4 const &transform, uint32_t flags) {
    if (flags & cocos2d::Node::FLAGS_TRANSFORM_DIRTY) {
        
        auto direcrot = cocos2d::Director::getInstance();
        auto glView = direcrot->getOpenGLView();
        auto frameSize = glView->getFrameSize();
        
        NSWindow* appMainWindow = glView->getCocoaWindow();
        
        auto scaleFactor = [appMainWindow backingScaleFactor];

        auto winSize = direcrot->getWinSize();

        auto leftBottom = this->_webView->convertToWorldSpace(cocos2d::Vec2::ZERO);
        auto rightTop = this->_webView->convertToWorldSpace(cocos2d::Vec2(this->_webView->getContentSize().width, this->_webView->getContentSize().height));

        auto x = (frameSize.width / 2 + (leftBottom.x - winSize.width / 2) * glView->getScaleX()) / scaleFactor;
        auto y = (frameSize.height / 2 - (rightTop.y - winSize.height / 2) * glView->getScaleY()) / scaleFactor;
        auto width = (rightTop.x - leftBottom.x) * glView->getScaleX() / scaleFactor;
        auto height = (rightTop.y - leftBottom.y) * glView->getScaleY() / scaleFactor;
        
        [_uiWebViewWrapper setFrameWithX:x
                                      y:y
                                  width:width
                                 height:height];
    }
}

void WebViewImpl::setVisible(bool visible){
    [_uiWebViewWrapper setVisible:visible];
}
        
    } // namespace ui
} // namespace experimental
} //namespace cocos2d

#endif // CC_TARGET_PLATFORM == CC_PLATFORM_IOS
