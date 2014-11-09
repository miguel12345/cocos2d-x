
#include "DownloaderLua.h"

NS_CC_EXT_BEGIN

DownloaderLua* DownloaderLua::create() {
    
    DownloaderLua* ret = new DownloaderLua();
    if (ret)
    {
        ret->init();
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}


bool DownloaderLua::init() {
    _downloader = std::make_shared<Downloader>();
    
    _downloader->setErrorCallback([this](const Downloader::Error & error) {
        _downloadHandler.cancelled.reset();
        if (_onError) {
            _onError(error);
        }
    });
    
    _downloader->setSuccessCallback([this](const std::string& url, const std::string& path, const std::string& customId) {
        _downloadHandler.cancelled.reset();
        if (_onSuccess) {
            _onSuccess(url,path,customId);
        }
    });
    
    _downloader->setProgressCallback([this](double total, double downloaded, const std::string &url, const std::string &customId) {
        
        if (_onProgress) {
            _onProgress(total,downloaded,url,customId);
        }
    });
    
    return true;
}


void DownloaderLua::downloadAsync(const std::string &srcUrl, const std::string &storagePath) {
    
    _downloadHandler = _downloader->downloadAsync(srcUrl, storagePath);
    
}

void DownloaderLua::cancelDownload() {
    
    std::atomic<bool>* cancel = _downloadHandler.cancelled.get();
    if (cancel) {
        cancel->store(true);
    }
}

NS_CC_EXT_END