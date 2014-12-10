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

#include "ui/UIText.h"
#include "2d/CCLabel.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN

namespace ui {

static const int LABEL_RENDERER_Z = (-1);
    
IMPLEMENT_CLASS_GUI_INFO(Text)

Text::Text():
_touchScaleChangeEnabled(false),
_normalScaleValueX(1.0f),
_normalScaleValueY(1.0f),
_fontName("Thonburi"),
_fontSize(10),
_onSelectedScaleOffset(0.5),
_labelRenderer(nullptr),
_labelRendererAdaptDirty(true),
_type(Type::SYSTEM),
_adaptLabelScaleWithContentSize(true),
_lineBreakWithoutSpace(false),
_adaptFontSizeToFit(false),
_invalidFontLetterSize(Size(-1,-1))
{
}

Text::~Text()
{
    
}

Text* Text::create()
{
    Text* widget = new (std::nothrow) Text();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool Text::init()
{
    if (Widget::init())
    {
        return true;
    }
    return false;
}
    
Text* Text::create(const std::string &textContent, const std::string &fontName, int fontSize)
{
    Text *text = new (std::nothrow) Text;
    if (text && text->init(textContent, fontName, fontSize)) {
        text->autorelease();
        return text;
    }
    CC_SAFE_DELETE(text);
    return nullptr;
}
    
bool Text::init(const std::string &textContent, const std::string &fontName, int fontSize)
{
    bool ret = true;
    do {
        if (!Widget::init()) {
            ret = false;
            break;
        }
        this->setString(textContent);
        this->setFontName(fontName);
        this->setFontSize(fontSize);
    } while (0);
    return ret;
}

void Text::initRenderer()
{
    _labelRenderer = Label::create();
    addProtectedChild(_labelRenderer, LABEL_RENDERER_Z, -1);
}

    
void Text::setString(const std::string &text)
{
    _labelRenderer->setString(text);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
const std::string& Text::getString() const
{
    return _labelRenderer->getString();
}

ssize_t Text::getStringLength()const
{
    return _labelRenderer->getStringLength();
}

void Text::setFontSize(int size)
{
    if (_type == Type::SYSTEM) {
        _labelRenderer->setSystemFontSize(size);
    }
    else{
        TTFConfig config = _labelRenderer->getTTFConfig();
        config.fontSize = size;
        _labelRenderer->setTTFConfig(config);
    }
    _fontSize = size;
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
int Text::getFontSize()const
{
    return _fontSize;
}

void Text::setFontName(const std::string& name)
{
    if(FileUtils::getInstance()->isFileExist(name))
    {
        TTFConfig config = _labelRenderer->getTTFConfig();
        config.fontFilePath = name;
        config.fontSize = _fontSize;
        _labelRenderer->setTTFConfig(config);
        _type = Type::TTF;
    }
    else{
        _labelRenderer->setSystemFontName(name);
        if (_type == Type::TTF)
        {
            _labelRenderer->requestSystemFontRefresh();
        }
        _type = Type::SYSTEM;
    }
    _fontName = name;
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
const std::string& Text::getFontName()const
{
    return _fontName;
}
    
Text::Type Text::getType() const
{
    return _type;
}

void Text::setTextAreaSize(const Size &size)
{
    _labelRenderer->setDimensions(size.width,size.height);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
const Size& Text::getTextAreaSize()const
{
    return _labelRenderer->getDimensions();
}

void Text::setTextHorizontalAlignment(TextHAlignment alignment)
{
    _labelRenderer->setHorizontalAlignment(alignment);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
TextHAlignment Text::getTextHorizontalAlignment()const
{
    return _labelRenderer->getHorizontalAlignment();
}

void Text::setTextVerticalAlignment(TextVAlignment alignment)
{
    _labelRenderer->setVerticalAlignment(alignment);
    updateContentSizeWithTextureSize(_labelRenderer->getContentSize());
    _labelRendererAdaptDirty = true;
}
    
TextVAlignment Text::getTextVerticalAlignment()const
{
    return _labelRenderer->getVerticalAlignment();
}
    
void Text::setTextColor(const Color4B color)
{
    _labelRenderer->setTextColor(color);
}
    
const Color4B& Text::getTextColor() const
{
    return _labelRenderer->getTextColor();
}

void Text::setTouchScaleChangeEnabled(bool enable)
{
    _touchScaleChangeEnabled = enable;
}
    
bool Text::isTouchScaleChangeEnabled()const
{
    return _touchScaleChangeEnabled;
}

void Text::onPressStateChangedToNormal()
{
    if (!_touchScaleChangeEnabled)
    {
        return;
    }
    _labelRenderer->setScaleX(_normalScaleValueX);
    _labelRenderer->setScaleY(_normalScaleValueY);
}

void Text::onPressStateChangedToPressed()
{
    if (!_touchScaleChangeEnabled)
    {
        return;
    }
    _labelRenderer->setScaleX(_normalScaleValueX + _onSelectedScaleOffset);
    _labelRenderer->setScaleY(_normalScaleValueY + _onSelectedScaleOffset);
}

void Text::onPressStateChangedToDisabled()
{
    
}

void Text::updateFlippedX()
{
     if (_flippedX)
    {
        _labelRenderer->setScaleX(-1.0f);
    } 
    else
    {
        _labelRenderer->setScaleX(1.0f);
    }
}
    
void Text::updateFlippedY()
{
    if (_flippedY)
    {
        _labelRenderer->setScaleY(-1.0f);
    } 
    else
    {
        _labelRenderer->setScaleY(1.0f);
    }
}

void Text::onSizeChanged(const Size& oldSize)
{
    Widget::onSizeChanged(oldSize);
    _labelRendererAdaptDirty = true;
}
    
void Text::adaptRenderers()
{
    if (_labelRendererAdaptDirty)
    {
        labelScaleChangedWithSize();
        _labelRendererAdaptDirty = false;
    }
}

Size Text::getVirtualRendererSize() const
{
    return _labelRenderer->getContentSize();
}

Node* Text::getVirtualRenderer()
{
    return _labelRenderer;
}

void Text::labelScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _labelRenderer->setDimensions(0,0);
        _labelRenderer->setScale(1.0f);
        _normalScaleValueX = _normalScaleValueY = 1.0f;
    }
    else if (_adaptFontSizeToFit)
    {
        setFontSize(calculateFontSizeToFit(_contentSize));
        
        /*  At this point we have to check if we have an unspecified (<0) content size dimension.
            If so, we must adapt our content size to wrap the label renderer's content.
            After setContentSize, we force _labelRendererAdaptDirty to false because we known that we don't
            need to adapt the renderer again due to this change of the content size */
        
        if (_contentSize.height<0) {
            setContentSize(Size(_contentSize.width,_labelRenderer->getContentSize().height));
            _labelRendererAdaptDirty = false;
        }
        else if(_contentSize.width<0) {
            setContentSize(Size(_labelRenderer->getContentSize().width,_contentSize.height));
            _labelRendererAdaptDirty = false;
        }
    }
    else {
        _labelRenderer->setScale(1.0f);
        _labelRenderer->setDimensions(_contentSize.width,_contentSize.height);
        Size textureSize = _labelRenderer->getContentSize();
        _normalScaleValueX = _normalScaleValueY = 1.0f;
        
        if (_adaptLabelScaleWithContentSize) {
            if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
            {
                _labelRenderer->setScale(1.0f);
                return;
            }
            
            float scaleX = _contentSize.width / textureSize.width;
            float scaleY = _contentSize.height / textureSize.height;
            _labelRenderer->setScaleX(scaleX);
            _labelRenderer->setScaleY(scaleY);
            _normalScaleValueX = scaleX;
            _normalScaleValueY = scaleY;
        }
        else {
            setContentSize(textureSize);
        }
    }
    
    _labelRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

std::string Text::getDescription() const
{
    return "Label";
}
    

    
void Text::enableShadow(const Color4B& shadowColor,const Size &offset, int blurRadius) {
    _labelRenderer->enableShadow(shadowColor, offset, blurRadius);
}

void Text::enableOutline(const Color4B& outlineColor,int outlineSize) {
    _labelRenderer->enableOutline(outlineColor, outlineSize);
}
    
void Text::enableGlow(const Color4B& glowColor) {
    if (_type == Type::TTF)
        _labelRenderer->enableGlow(glowColor);
}

void Text::disableEffect() {
    _labelRenderer->disableEffect();
}

Widget* Text::createCloneInstance()
{
    return Text::create();
}

void Text::copySpecialProperties(Widget *widget)
{
    Text* label = dynamic_cast<Text*>(widget);
    if (label)
    {
        setFontName(label->_fontName);
        setFontSize(label->getFontSize());
        setString(label->getString());
        setTouchScaleChangeEnabled(label->_touchScaleChangeEnabled);
        setTextHorizontalAlignment(label->_labelRenderer->getHorizontalAlignment());
        setTextVerticalAlignment(label->_labelRenderer->getVerticalAlignment());
        setTextAreaSize(label->_labelRenderer->getDimensions());
        setAdaptFontSizeToFit(label->getAdaptFontSizeToFit());
        setLineBreakWithoutSpace(label->getLineBreakWithoutSpace());
        setAdaptLabelScaleWithContentSize(label->getAdaptLabelScaleWithContentSize());
    }
}
    
void Text::setAdaptLabelScaleWithContentSize(bool adaptLabelScaleWithContentSize) {
    if (adaptLabelScaleWithContentSize != _adaptLabelScaleWithContentSize) {
        _adaptLabelScaleWithContentSize = adaptLabelScaleWithContentSize;
        _labelRendererAdaptDirty = true;
    }
}

bool Text::getAdaptLabelScaleWithContentSize() {
    return _adaptLabelScaleWithContentSize;
}

void Text::setLineBreakWithoutSpace(bool lineBreakWithoutSpace){
    if (lineBreakWithoutSpace != _lineBreakWithoutSpace) {
        _labelRendererAdaptDirty = true;
        _lineBreakWithoutSpace = lineBreakWithoutSpace;
        _labelRenderer->setLineBreakWithoutSpace(_lineBreakWithoutSpace);
    }
}

bool Text::getLineBreakWithoutSpace() {
    return _lineBreakWithoutSpace;
}

void Text::setAdaptFontSizeToFit(bool adaptFontSizeToFit) {
    if (adaptFontSizeToFit != _adaptFontSizeToFit) {
        _adaptFontSizeToFit = adaptFontSizeToFit;
        _labelRendererAdaptDirty = true;
    }
}

bool Text::getAdaptFontSizeToFit() {
    return _adaptLabelScaleWithContentSize;
}

int Text::calculateFontSizeToFit(const Size& areaSize) {
    
    float areaSizeWidth = areaSize.width;
    float areaSizeHeight = areaSize.height;
    TTFConfig config = _labelRenderer->getTTFConfig();
    
    CCASSERT(areaSizeWidth>=0 || areaSizeHeight>=0, "At least one of the constraint area dimensions must be positive");
    CCASSERT(config.fontSize>0, "The renderer must have a valid font size at this point");

    //We use the current ttf config as the reference size
    int referenceFontSize = config.fontSize;
    
    //Now we calculate the resulting renderer content size for that font size
    Size rendererContentSize = _labelRenderer->Node::getContentSize();
    
    //Then we have all the information to calculate the best font size
    //for the string to fit perfectly inside the constraint area
    if (areaSize.width>=0) {
        int fontSizeToFitWidth = floor((areaSizeWidth * referenceFontSize) / rendererContentSize.width);
        
        float finalHeight = ((float)fontSizeToFitWidth / (float)referenceFontSize) * rendererContentSize.height;
        
        if (areaSize.height<0 || finalHeight < areaSize.height) {
            return fontSizeToFitWidth;
        }
    }
    
    int fontSizeToFitHeight = floor((areaSize.height * referenceFontSize) / rendererContentSize.height);
    
    return fontSizeToFitHeight;
}

const Size& Text::getContentSize() const {
    
    if (_labelRendererAdaptDirty)
    {
        const_cast<Text*>(this)->adaptRenderers();
    }
    
    return _contentSize;
}
    
}

NS_CC_END
