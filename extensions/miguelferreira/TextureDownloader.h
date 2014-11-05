/****************************************************************************
 Copyright (c) 2014 Miguel Ferreira
 
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

#ifndef __TextureDownloader__
#define __TextureDownloader__

#include "extensions/miguelferreira/DownloaderExtended.h"

namespace cocos2d { namespace extension { namespace mf {


    class TextureDownloadHandler {
        
        friend class TextureDownloader;
        
    public:
        void cancel();
    private:
        std::weak_ptr<DownloaderExtended::DownloadHandler> _download;
        std::string _imageFileName;
    };
    
class CC_EX_DLL TextureDownloader : public Ref
{
    
public:
    
    std::weak_ptr<TextureDownloadHandler> downloadTextureAsync(const std::string& imageUrl,const std::function<void(bool success, std::string imagePath)>& callback);
    
    bool init();
    
    static TextureDownloader* getInstance();
    
private:
    
    std::shared_ptr<DownloaderExtended> _downloader;
    std::unordered_map<std::string, std::function<void(bool success)>> _callbacks;
    std::string imagesFolder;
    
};

}}}
#endif /* defined(__TextureDownloader__) */
