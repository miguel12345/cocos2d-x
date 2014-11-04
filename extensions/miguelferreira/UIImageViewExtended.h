/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

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

#ifndef __UIImageViewExtended_H__
#define __UIImageViewExtended_H__

#include "ui/UIWidget.h"
#include "ui/GUIExport.h"
#include "extensions/miguelferreira/TextureDownloader.h"

NS_CC_BEGIN

namespace ui {
    class Scale9Sprite;
/**
*   @js NA
*   @lua NA
*/
class CC_GUI_DLL ImageViewExtended : public Widget
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
    /**
     * Default constructor
     */
    ImageViewExtended();

    /**
     * Default destructor
     */
    virtual ~ImageViewExtended();

    /**
     * Allocates and initializes.
     */
    static ImageViewExtended* create();
    
    /**
     * create a  ImageViewExtended 
     *
     * @param imageFileName   file name of texture.
     *
     * @param texType    @see TextureResType
     */
    static ImageViewExtended* create(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL);
    

    static ImageViewExtended* create(const std::string& imageUrl, const std::string& placeholderFileName, TextureResType placeholderTexType = TextureResType::LOCAL);
    
    /**
     * Load texture for ImageViewExtended.
     *
     * @param fileName   file name of texture.
     *
     * @param texType    @see TextureResType
     */
    void loadTexture(const std::string& fileName,TextureResType texType = TextureResType::LOCAL);

    /**
     * Updates the texture rect of the ImageViewExtended in points.
     * It will call setTextureRect:rotated:untrimmedSize with rotated = NO, and utrimmedSize = rect.size.
     */
    void setTextureRect(const Rect& rect);

    /**
     * Sets if ImageViewExtended is using scale9 renderer.
     *
     * @param able true that using scale9 renderer, false otherwise.
     */
    void setScale9Enabled(bool able);

    bool isScale9Enabled()const;

    /**
     * Sets capinsets for ImageViewExtended, if ImageViewExtended is using scale9 renderer.
     *
     * @param capInsets    capinsets for ImageViewExtended
     */
    void setCapInsets(const Rect &capInsets);

    const Rect& getCapInsets()const;

    //override "ignoreContentAdaptWithSize" method of widget.
    virtual void ignoreContentAdaptWithSize(bool ignore) override;

    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;

    virtual Size getVirtualRendererSize() const override;
    virtual Node* getVirtualRenderer() override;
    
    virtual void onExit() override;
    virtual void onEnter() override;
    
    void setKeepAspectRatio(bool keepAspectRatio);
    void updateRemoteImageUrl(std::string imageUrl);
    
CC_CONSTRUCTOR_ACCESS:
    //initializes state of widget.
    virtual bool init() override;
    virtual bool init(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL);
    virtual bool init(const std::string& imageUrl, const std::string& placeholderFileName, TextureResType texType);
    
    

protected:
    virtual void initRenderer() override;
    virtual void onSizeChanged() override;
  
    virtual void updateFlippedX() override;
    virtual void updateFlippedY() override;
    
    virtual void adaptRenderers() override;
    
    void imageTextureScaleChangedWithSize();
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
    
    void onRemoteTextureLoadedFinished(bool success, const std::string& imageFileName);
    void onRemoteTextureReady(const std::string& imageFileName);
    void onRemoteTextureFailed();
    
    std::weak_ptr<extension::TextureDownloader::TextureDownloadHandler> _textureDownloadHandler;
    
protected:
    bool _scale9Enabled;
    bool _prevIgnoreSize;
    Rect _capInsets;
    Scale9Sprite* _imageRenderer;
    std::string _textureFile;
    TextureResType _imageTexType;
    Size _imageTextureSize;
    bool _imageRendererAdaptDirty;
    bool _keepAspectRatio;
    std::string _remoteImageUrl;
};

}

NS_CC_END

#endif /* defined(__CocoGUI__ImageViewExtended__) */
