/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
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

#include "TextureDownloader.h"
#include "cocos2d.h"

using namespace cocos2d::extension::mf;
using namespace cocos2d::extension;

static TextureDownloader *s_SharedTextureDownloader = nullptr;

TextureDownloader* TextureDownloader::getInstance()
{
    if (!s_SharedTextureDownloader)
    {
        s_SharedTextureDownloader = new (std::nothrow) TextureDownloader();
        CCASSERT(s_SharedTextureDownloader, "FATAL: Not enough memory");
        s_SharedTextureDownloader->init();
    }
    
    return s_SharedTextureDownloader;
}


bool TextureDownloader::init() {
    
    imagesFolder = FileUtils::getInstance()->getWritablePath()+"cache_images/";
    FileUtils::getInstance()->createDirectory(imagesFolder);
    
    _downloader = std::make_shared<DownloaderExtended>();
    
    _downloader->setSuccessCallback([this](const std::string & imageUrl, const std::string &, const std::string &){
        if (_callbacks[imageUrl]) {
            _callbacks[imageUrl](true);
        }
    });
    
    _downloader->setErrorCallback([this](const DownloaderExtended::Error & error){
        
        const std::string imageUrl = error.url;
        
        if (_callbacks[imageUrl]) {
            _callbacks[imageUrl](false);
        }
    });
        
    
    return true;
}

void TextureDownloader::TextureDownloadHandler::cancel() {
    
    if (!_download.expired()) {
        _download.lock()->cancel();
    }
    
    Director::getInstance()->getTextureCache()->unbindImageAsync(_imageFileName);
}

std::weak_ptr<TextureDownloader::TextureDownloadHandler> TextureDownloader::downloadTextureAsync(const std::string& imageUrl,const std::function<void(bool success,std::string imagePath)>& callback) {
    
    std::string imageLocalPath = imagesFolder;
    std::string fileName = std::string(imageUrl.begin()+imageUrl.rfind("/")+1,imageUrl.end());
    imageLocalPath += fileName;
    
    std::shared_ptr<TextureDownloader::TextureDownloadHandler> textDownloadHandler = std::make_shared<TextureDownloader::TextureDownloadHandler>();
    
    _callbacks[imageUrl] = [this,callback,imageUrl,imageLocalPath,textDownloadHandler](bool success) {
        
        if (!success) {
            callback(success,"");
        }
        else {
            Director::getInstance()->getTextureCache()->addImageAsync(imageLocalPath,[this,callback,imageLocalPath](Texture2D* text){
                callback(text!=nullptr,imageLocalPath);
            });
        }
        
        
        _callbacks.erase(imageUrl);
    };
    
    auto dowloadHandler = _downloader->downloadAsync(imageUrl, imageLocalPath);
    
    textDownloadHandler->_download = dowloadHandler;
    textDownloadHandler->_imageFileName = imageLocalPath;
    
    return textDownloadHandler;
    
}