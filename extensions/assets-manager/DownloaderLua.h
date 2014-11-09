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

#ifndef __DownloaderLua__
#define __DownloaderLua__

#include "Downloader.h"
#include "extensions/ExtensionMacros.h"
#include "extensions/ExtensionExport.h"

NS_CC_EXT_BEGIN

class CC_EX_DLL DownloaderLua : public Ref
{
public:
    
    typedef std::function<void(double, double, const std::string &, const std::string &)> ProgressCallback;
    typedef std::function<void(const Downloader::Error &)> ErrorCallback;
    typedef std::function<void(const std::string &, const std::string &, const std::string &)> SuccessCallback;
    
    void setProgressCallback(const ProgressCallback &callback) { _onProgress = callback; };

    void setErrorCallback(const ErrorCallback &callback) { _onError = callback; };

    void setSuccessCallback(const SuccessCallback &callback) { _onSuccess = callback; };

    
    static DownloaderLua* create();
    void downloadAsync(const std::string &srcUrl, const std::string &storagePath);
    void cancelDownload();
    
private:
    bool init();

    std::shared_ptr<Downloader> _downloader;
    DownloadHandler _downloadHandler;
    ProgressCallback _onProgress;
    ErrorCallback _onError;
    SuccessCallback _onSuccess;
};

NS_CC_EXT_END

#endif /* defined(__DownloaderLua__) */
