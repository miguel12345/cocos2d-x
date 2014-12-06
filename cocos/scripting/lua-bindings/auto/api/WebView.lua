
--------------------------------
-- @module WebView
-- @extend Widget
-- @parent_module ccexp

--------------------------------
-- Loads the given URL.<br>
-- param url content URL
-- @function [parent=#WebView] loadURL 
-- @param self
-- @param #string url
        
--------------------------------
-- Gets whether this WebView has a back history item.<br>
-- return web view has a back history item.
-- @function [parent=#WebView] canGoBack 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Sets the main page content and base URL.<br>
-- param string The content for the main page.<br>
-- param baseURL The base URL for the content.
-- @function [parent=#WebView] loadHTMLString 
-- @param self
-- @param #string string
-- @param #string baseURL
        
--------------------------------
-- Call before a web view begins loading.<br>
-- param sender The web view that is about to load new content.<br>
-- param url content URL.<br>
-- return YES if the web view should begin loading content; otherwise, NO .
-- @function [parent=#WebView] setOnShouldStartLoading 
-- @param self
-- @param #function callback
        
--------------------------------
-- Goes forward in the history.
-- @function [parent=#WebView] goForward 
-- @param self
        
--------------------------------
-- Goes back in the history.
-- @function [parent=#WebView] goBack 
-- @param self
        
--------------------------------
-- Set javascript interface scheme.<br>
-- see #onJsCallback
-- @function [parent=#WebView] setJavascriptInterfaceScheme 
-- @param self
-- @param #string scheme
        
--------------------------------
-- evaluates JavaScript in the context of the currently displayed page
-- @function [parent=#WebView] evaluateJS 
-- @param self
-- @param #string js
        
--------------------------------
-- 
-- @function [parent=#WebView] getOnJSCallback 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- Reloads the current URL.
-- @function [parent=#WebView] reload 
-- @param self
        
--------------------------------
-- Set WebView should support zooming. The default value is false.
-- @function [parent=#WebView] setScalesPageToFit 
-- @param self
-- @param #bool scalesPageToFit
        
--------------------------------
-- Gets whether this WebView has a forward history item.<br>
-- return web view has a forward history item.
-- @function [parent=#WebView] canGoForward 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#WebView] getOnShouldStartLoading 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- Loads the given fileName.<br>
-- param fileName content fileName
-- @function [parent=#WebView] loadFile 
-- @param self
-- @param #string fileName
        
--------------------------------
-- Stops the current load.
-- @function [parent=#WebView] stopLoading 
-- @param self
        
--------------------------------
-- Call after a web view finishes loading.<br>
-- param sender The web view that has finished loading.<br>
-- param url content URL.
-- @function [parent=#WebView] setOnDidFinishLoading 
-- @param self
-- @param #function callback
        
--------------------------------
-- Call if a web view failed to load content.<br>
-- param sender The web view that has failed loading.<br>
-- param url content URL.
-- @function [parent=#WebView] setOnDidFailLoading 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#WebView] getOnDidFinishLoading 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- 
-- @function [parent=#WebView] getOnDidFailLoading 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- Allocates and initializes a WebView.
-- @function [parent=#WebView] create 
-- @param self
-- @return experimental::ui::WebView#experimental::ui::WebView ret (return value: cc.experimental::ui::WebView)
        
--------------------------------
-- 
-- @function [parent=#WebView] draw 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table transform
-- @param #unsigned int flags
        
--------------------------------
-- 
-- @function [parent=#WebView] setVisible 
-- @param self
-- @param #bool visible
        
return nil
