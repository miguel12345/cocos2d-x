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

#ifndef __UILABEL_H__
#define __UILABEL_H__

#include "ui/UIWidget.h"
#include "ui/GUIExport.h"

NS_CC_BEGIN

class Label;

namespace ui {

/**
 *  For creating a system font or a TTF font Text
 *@js 
 *@lua NA
 */
class CC_GUI_DLL Text : public Widget
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
    enum class Type
    {
        SYSTEM,
        TTF
    };
    
    enum class FontSizeType
    {
        ABSOLUTE,
        PERCENTAGE
    };
    
    enum class FontSizePercentageSource
    {
        NONE,
        WIDTH,
        HEIGHT
    };
    
    /**
     * Default constructor
     */
    Text();

    /**
     * Default destructor
     */
    virtual ~Text();

    /**
     * Allocates and initializes.
     */
    static Text* create();
    
    /**
     *  create a Text object with textContent, fontName and fontSize
     *  the fontName could be a system font name or a TTF file path.
     *  Usage:  Text *text = Text::create("Hello", "Arial", 20);  //create a system font UIText
     *          Text *text = Text::create("Hello", "xxx\xxx.ttf", 20); //create a TTF font UIText
     */
    static Text* create(const std::string& textContent,
                        const std::string& fontName,
                        int fontSize);

    /**
     * Changes the string value of label.
     *
     * @param text  string value.
     */
    CC_DEPRECATED_ATTRIBUTE void setText(const std::string& text){this->setString(text);}
    void setString(const std::string& text);

    /**
     * Gets the string value of label.
     *
     * @return string value.
     */
    CC_DEPRECATED_ATTRIBUTE const std::string& getStringValue(){ return this->getString();}
    const std::string& getString()const;

    /**
     * Gets the string length of the label.
     * Note: This length will be larger than the raw string length,
     * if you want to get the raw string length, you should call this->getString().size() instead
     *
     * @return  string length.
     */
    ssize_t getStringLength()const;

    /**
     * Sets the font size of label.
     *
     * @param size font size.
     */
    void setFontSize(int size);

    int getFontSize()const;

    /**
     * Sets the font name of label.
     *  If you are trying to use a system font, you could just pass a font name
     * If you are trying to use a TTF, you should pass a file path to the TTF file
     * Usage:  Text *text = Text::create("Hello", "Arial", 20);  //create a system font UIText
     *         text->setFontName("Marfelt");  // it will change the font  to  system font no matter the previous font type is TTF or system font
     *         text->setFontName("xxxx/xxx.ttf"); //it will change the font  to TTF font no matter the previous font type is TTF or system font
     * @param name font name.
     */
    void setFontName(const std::string& name);

    const std::string& getFontName()const;
    
    Type getType() const;

    /**
     * Sets the touch scale enabled of label.
     *
     * @param enabled touch scale enabled of label.
     */
    void setTouchScaleChangeEnabled(bool enabled);

    /**
     * Gets the touch scale enabled of label.
     *
     * @return  touch scale enabled of label.
     */
    bool isTouchScaleChangeEnabled()const;

    //override "getVirtualRendererSize" method of widget.
    virtual Size getVirtualRendererSize() const override;

    //override "getVirtualRenderer" method of widget.
    virtual Node* getVirtualRenderer() override;

    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;

    /**
     * Set the rendering size of the text, you should call this method
     * along with calling `ignoreContentAdaptWithSize(false)`, otherwise the text area
     * size is caculated by the real size of the text content
     * @param size   The text rendering area size
     *
     */
    void setTextAreaSize(const Size &size);

    const Size& getTextAreaSize()const;

    void setTextHorizontalAlignment(TextHAlignment alignment);

    TextHAlignment getTextHorizontalAlignment()const;

    void setTextVerticalAlignment(TextVAlignment alignment);

    TextVAlignment getTextVerticalAlignment()const;
    
    void setTextColor(const Color4B color);
    
    const Color4B& getTextColor() const;
    
    /**
     * Enable shadow for the label
     *
     * @todo support blur for shadow effect
     */
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK,const Size &offset = Size(2,-2), int blurRadius = 0);
    
    /**
     * Enable outline for the label
     * It only works on IOS and Android when you use System fonts
     */ 
    void enableOutline(const Color4B& outlineColor,int outlineSize = 1);
    
    /** only support for TTF */
    void enableGlow(const Color4B& glowColor);
    
    /** disable shadow/outline/glow rendering */
    void disableEffect();
    
    /**
     *  Sets if the text element should scale the label renderer
     *  with its content size
     *
     *  @param adaptLabelScaleWithContentSize Whether to scale label renderer
     */
    void setAdaptLabelScaleWithContentSize(bool adaptLabelScaleWithContentSize);
    
    
    /**
     *  Returns adaptLabelScaleWithContentSize variable
     *
     *  @return adaptLabelScaleWithContentSize variable
     */
    bool getAdaptLabelScaleWithContentSize();
    
    /**
     *  Sets if line breaks without space
     *
     *  @param lineBreakWithoutSpace Variable to determine if line
     *          breaks without space
     */
    void setLineBreakWithoutSpace(bool lineBreakWithoutSpace);
    
    /**
     *  Returns line break variable
     *
     *  @return line break variable
     */
    bool getLineBreakWithoutSpace();
    
    /**
     *  Sets if the text should resize the font size automatically
     *  to fit its size
     */
    void setAdaptFontSizeToFit(bool adaptFontSizeToFit);
    
    /**
     *  Returns adaptFontSizeToFit variable
     *
     */
    bool getAdaptFontSizeToFit();
    
    
    /**
     * TODO
     *
     * @param size font size.
     */
    void setFontSizePercentage(float percentage, FontSizePercentageSource percentageSource = FontSizePercentageSource::HEIGHT);
    float getFontSizePercentage();
    
    void setFontSizeType(FontSizeType fontSizeType);
    FontSizeType getFontSizeType();
    
CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;
    virtual bool init(const std::string& textContent,
                      const std::string& fontName,
                      int fontSize);

protected:
    virtual void initRenderer() override;
    virtual void onPressStateChangedToNormal() override;
    virtual void onPressStateChangedToPressed() override;
    virtual void onPressStateChangedToDisabled() override;
    virtual void onSizeChanged(const Size& oldSize) override;
   
    void labelScaleChangedWithSize();
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
    virtual void adaptRenderers() override;
    
    /**
     *  This method calucates and returns the perfect font size for a string with
        a given font to fit inside the given area.
     
        This method expects that the renderer already has a ttf config with valid size.
    
        It also expects that the renderer already has the string that will be displayed
     
        Note that the constraint area might be partially unspecified
        by having a dimension with a negative value.
        For example, if areaSize.height < 0 then the height will not be
        taken into account when calculating the font size constraint. This means
        that the caller should take this into consideration by, for example,
        changing it's content size to match the rendererer's
     *
     *  @return An integer representing the font size
     */
    int calculateFontSizeToFit(const Size& constraintAreaSize);
    
    virtual void updateSizeAndPosition() override;
    
    void updateRendererTTFConfig();
    
protected:
    bool _touchScaleChangeEnabled;
    float _normalScaleValueX;
    float _normalScaleValueY;
    std::string _fontName;
    int _fontSize;
    float _onSelectedScaleOffset;
    Label* _labelRenderer;
    bool _labelRendererAdaptDirty;
    bool _ttfConfigDirty;
    Type _type;
    bool _adaptLabelScaleWithContentSize;
    bool _lineBreakWithoutSpace;
    bool _adaptFontSizeToFit;
    std::unordered_map<std::string, Size> _fontLetterSizeCache;
    Size _invalidFontLetterSize;
    FontSizeType _fontSizeType;
    FontSizePercentageSource _fontSizePercentageSource;
    float _fontSizePercentage;
};

}

NS_CC_END

#endif /* defined(__CocoGUI__Label__) */
