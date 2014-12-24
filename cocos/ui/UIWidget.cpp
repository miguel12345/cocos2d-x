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

#include "ui/UIWidget.h"
#include "ui/UILayout.h"
#include "ui/UIHelper.h"
#include "base/CCEventListenerTouch.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCDirector.h"
#include "base/CCEventFocus.h"
#include "base/CCEventDispatcher.h"
#include "ui/UILayoutComponent.h"
#include "2d/CCDrawNode.h"

NS_CC_BEGIN

namespace ui {
    
class Widget::FocusNavigationController
{
    void enableFocusNavigation(bool flag);
    
    FocusNavigationController():
    _keyboardListener(nullptr),
    _firstFocusedWidget(nullptr),
    _enableFocusNavigation(false),
    _keyboardEventPriority(1)
    {
        //no-op
    }
    ~FocusNavigationController();
protected:
    void setFirstFocsuedWidget(Widget* widget);
    
    void onKeypadKeyPressed(EventKeyboard::KeyCode, Event*);
    
    void addKeyboardEventListener();
    void removeKeyboardEventListener();
    
    friend class Widget;
private:
    EventListenerKeyboard* _keyboardListener ;
    Widget* _firstFocusedWidget ;
    bool _enableFocusNavigation ;
    const int _keyboardEventPriority;
};
    
Widget::FocusNavigationController::~FocusNavigationController()
{
    this->removeKeyboardEventListener();
}

void Widget::FocusNavigationController::onKeypadKeyPressed(EventKeyboard::KeyCode  keyCode, Event *event)
{
    if (_enableFocusNavigation && _firstFocusedWidget)
    {
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_DOWN)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::DOWN, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_UP)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::UP, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_LEFT)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::LEFT, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_RIGHT)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::RIGHT, _firstFocusedWidget);
        }
    }
}

void Widget::FocusNavigationController::enableFocusNavigation(bool flag)
{
    if (_enableFocusNavigation == flag)
        return;
    
    _enableFocusNavigation = flag;
    
    if (flag)
        this->addKeyboardEventListener();
    else
        this->removeKeyboardEventListener();
}

void Widget::FocusNavigationController::setFirstFocsuedWidget(Widget* widget)
{
    _firstFocusedWidget = widget;
}

void Widget::FocusNavigationController::addKeyboardEventListener()
{
    if (nullptr == _keyboardListener)
    {
        _keyboardListener = EventListenerKeyboard::create();
        _keyboardListener->onKeyReleased = CC_CALLBACK_2(Widget::FocusNavigationController::onKeypadKeyPressed, this);
        EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithFixedPriority(_keyboardListener, _keyboardEventPriority);
    }
}

void Widget::FocusNavigationController::removeKeyboardEventListener()
{
    if (nullptr != _keyboardListener)
    {
        EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
        dispatcher->removeEventListener(_keyboardListener);
        _keyboardListener = nullptr;
    }
}

Widget* Widget::_focusedWidget = nullptr;
Widget::FocusNavigationController* Widget::_focusNavigationController = nullptr;
    
Widget::Widget():
_unifySize(false),
_enabled(true),
_bright(true),
_touchEnabled(false),
_highlight(false),
_affectByClipping(false),
_ignoreSize(false),
_propagateTouchEvents(true),
_brightStyle(BrightStyle::NONE),
_sizeType(SizeType::ABSOLUTE),
_positionType(PositionType::ABSOLUTE),
_actionTag(0),
_customSize(Size::ZERO),
_widthSizeType(SizeType::ABSOLUTE),
_heigthSizeType(SizeType::ABSOLUTE),
_sizePercent(Vec2::ZERO),
_positionPercent(Vec2::ZERO),
_hitted(false),
_touchListener(nullptr),
_touchBeganPosition(Vec2::ZERO),
_touchMovePosition(Vec2::ZERO),
_touchEndPosition(Vec2::ZERO),
_flippedX(false),
_flippedY(false),
_layoutParameterType(LayoutParameter::Type::NONE),
_focused(false),
_focusEnabled(true),
_maximumSize(Size(-1., -1.)),
_minimumSize(Size(-1., -1.)),
_visibility(Visibility::VISIBLE),
_touchEventListener(nullptr),
_touchEventSelector(nullptr),
_ignoreLayout(false),
_sizePercentDimension(SizePercentSourceDimension::SAME_DIMENSION),
_propagateTouchEventsToChildren(false),
_ccEventCallback(nullptr),
_callbackType(""),
_callbackName("")
#if MF_ALLOW_WIDGET_DEBUG_DRAW
    ,
_debugDraw(false),
_debugDrawNode(nullptr)
#endif
{
  
}

Widget::~Widget()
{
    this->cleanupWidget();
}

void Widget::cleanupWidget()
{
    //clean up _touchListener
    _eventDispatcher->removeEventListener(_touchListener);
    CC_SAFE_RELEASE_NULL(_touchListener);
    
    //cleanup focused widget and focus navigation controller
    if (_focusedWidget == this)
    {
        //delete
        CC_SAFE_DELETE(_focusNavigationController);
        _focusedWidget = nullptr;
    }
}

Widget* Widget::create()
{
    Widget* widget = new (std::nothrow) Widget();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool Widget::init()
{
    if (ProtectedNode::init())
    {
        initRenderer();
        setBright(true);
        onFocusChanged = CC_CALLBACK_2(Widget::onFocusChange,this);
        onNextFocusedWidget = nullptr;
        this->setAnchorPoint(Vec2(0.5f, 0.5f));

        ignoreContentAdaptWithSize(true);
        
        return true;
    }
    return false;
}

void Widget::onEnter()
{
    updateSizeAndPosition();
    ProtectedNode::onEnter();
}

void Widget::onExit()
{
    unscheduleUpdate();
    ProtectedNode::onExit();
}

void Widget::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    if (_visible || !isVisitableByVisitingCamera())
    {
        adaptRenderers();
        ProtectedNode::visit(renderer, parentTransform, parentFlags);
    }
}

Widget* Widget::getWidgetParent()
{
    return dynamic_cast<Widget*>(getParent());
}

void Widget::setEnabled(bool enabled)
{
    _enabled = enabled;
}
    
void Widget::initRenderer()
{
}
    
LayoutComponent* Widget::getOrCreateLayoutComponent()
{
    auto layoutComponent = this->getComponent(__LAYOUT_COMPONENT_NAME);
    if (nullptr == layoutComponent)
    {
        LayoutComponent *component = LayoutComponent::create();
        this->addComponent(component);
        layoutComponent = component;
    }
    
    return (LayoutComponent*)layoutComponent;
}
   
void Widget::setContentSize(const cocos2d::Size &contentSize)
{
    Size oldSize = _contentSize;
    
    //Prevent unnecessary logic when the same remains the same
    if (_contentSize.equals(contentSize)) {
        return;
    }
    
    ProtectedNode::setContentSize(contentSize);
    
    _customSize = contentSize;
    if (_unifySize)
    {
        //unify Size logic
    }
    else if (_ignoreSize)
    {
        _contentSize = getVirtualRendererSize();
    }
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        Size pSize;
        if (widgetParent)
        {
            pSize = widgetParent->getContentSize();
        }
        else
        {
            pSize = _parent->getContentSize();
        }
        float spx = 0.0f;
        float spy = 0.0f;
        if (pSize.width > 0.0f)
        {
            spx = _customSize.width / pSize.width;
        }
        if (pSize.height > 0.0f)
        {
            spy = _customSize.height / pSize.height;
        }
        _sizePercent = Vec2(spx, spy);
    }
    onSizeChanged(oldSize);
}

void Widget::setSize(const Size &size)
{
    this->setContentSize(size);
}

void Widget::setSizePercent(const Vec2 &percent)
{
    _sizePercent = percent;
    Size cSize = _customSize;
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        Size parentSize = (widgetParent!=nullptr)?widgetParent->getContentSize():_parent->getContentSize();
        
        float widthPercentParentDimensionToUse = _sizePercentDimension==SizePercentSourceDimension::HEIGHT?parentSize.height:parentSize.width;
        float heigthPercentParentDimensionToUse = _sizePercentDimension==SizePercentSourceDimension::WIDTH?parentSize.width:parentSize.height;
        
        cSize = Size(widthPercentParentDimensionToUse* percent.x , heigthPercentParentDimensionToUse * percent.y);

    }
    if (_ignoreSize)
    {
        this->setContentSize(getVirtualRendererSize());
    }
    else
    {
        this->setContentSize(cSize);
    }
    _customSize = cSize;
}
    
void Widget::setSizeValues(const Size &values) {
    
    Size contentSize = Size(0, 0);
    Vec2 sizePercent = Vec2(0, 0);
    
    if (_widthSizeType == SizeType::ABSOLUTE) {
        contentSize.width = values.width;
    }
    else {
        sizePercent.x = values.width;
    }
    
    if (_heigthSizeType == SizeType::ABSOLUTE) {
        contentSize.height = values.height;
    }
    else {
        sizePercent.y = values.height;
    }
    
    _customSize = contentSize;
    _sizePercent = sizePercent;
}
    
void Widget::setSizeTypes(SizeType widthType, SizeType heightType) {
    _widthSizeType = widthType;
    _heigthSizeType = heightType;
}
    
void Widget::setMaxSize(const Size &maxSize) {
    _maximumSize = maxSize;
}
    
void Widget::setMinSize(const Size &minSize) {
    _minimumSize = minSize;
}

void Widget::updateSizeAndPosition()
{
    Size pSize = _parent->getContentSize();
    
    updateSizeAndPosition(pSize);
}
    
void Widget::updateSizeAndPosition(const cocos2d::Size &parentSize)
{
    float contentSizeWidth = 0.0f;
    float contentSizeHeight = 0.0f;
    float sizePercentWidth = 0.0f;
    float sizePercentHeight = 0.0f;
    
    float widthPercentParentDimensionToUse = _sizePercentDimension==SizePercentSourceDimension::HEIGHT?parentSize.height:parentSize.width;
    float heigthPercentParentDimensionToUse = _sizePercentDimension==SizePercentSourceDimension::WIDTH?parentSize.width:parentSize.height;
    
    switch (_widthSizeType)
    {
        case SizeType::ABSOLUTE:
        {
            if (_ignoreSize)
            {
                contentSizeWidth = getVirtualRendererSize().width;
                
            }
            else
            {
                contentSizeWidth = _customSize.width;
                
            }
            
            float spx = 0.0f;
            if (parentSize.width > 0.0f)
            {
                spx = contentSizeWidth / parentSize.width;
            }
            
            sizePercentWidth = spx;
            
            break;
        }
        case SizeType::PERCENT:
        {
            
            Size cSize = Size(widthPercentParentDimensionToUse * _sizePercent.x , heigthPercentParentDimensionToUse * _sizePercent.y);
            if (_ignoreSize)
            {
                contentSizeWidth = getVirtualRendererSize().width;
                
            }
            else
            {
                contentSizeWidth = cSize.width;
                
            }
            sizePercentWidth = _sizePercent.x;

            
            break;
        }
        default:
            break;
    }
    
    switch (_heigthSizeType)
    {
        case SizeType::ABSOLUTE:
        {
            if (_ignoreSize)
            {
                contentSizeHeight = getVirtualRendererSize().height;
                
            }
            else
            {
                contentSizeHeight = _customSize.height;
                
            }
            float spx = 0.0f;
            float spy = 0.0f;
            if (parentSize.width > 0.0f)
            {
                spx = _customSize.width / parentSize.width;
            }
            if (parentSize.height > 0.0f)
            {
                spy = _customSize.height / parentSize.height;
            }
            sizePercentHeight = spy;
            
            break;
        }
        case SizeType::PERCENT:
        {
            Size cSize = Size(widthPercentParentDimensionToUse * _sizePercent.x , heigthPercentParentDimensionToUse * _sizePercent.y);
            if (_ignoreSize)
            {
                contentSizeHeight = getVirtualRendererSize().height;
                
            }
            else
            {
                contentSizeHeight = cSize.height;
                
            }
            
            sizePercentHeight = _sizePercent.y;
            
            break;
        }
        default:
            break;
    }
    
    //restrict size - width
    float maximumWidth =_maximumSize.width;
    if (maximumWidth>0.0f) {
        contentSizeWidth = std::min(maximumWidth,contentSizeWidth);
    }
    
    float minimumWidth =_minimumSize.width;
    if (minimumWidth>0.0f) {
        contentSizeWidth = std::max(minimumWidth,contentSizeWidth);
    }
    
    //restrict size - height
    float maximumHeight =_maximumSize.height;
    if (maximumHeight>0.0f) {
        contentSizeHeight = std::min(maximumHeight,contentSizeHeight);
    }
    
    float minimumHeight =_minimumSize.height;
    if (minimumHeight>0.0f) {
        contentSizeHeight = std::max(minimumHeight,contentSizeHeight);
    }

    _customSize = Size(contentSizeWidth,contentSizeHeight);
    setContentSize(_customSize);
    _sizePercent = Vec2(sizePercentWidth, sizePercentHeight);
    
    //update position & position percent
    Vec2 absPos = getPosition();
    switch (_positionType)
    {
        case PositionType::ABSOLUTE:
        {
            if (parentSize.width <= 0.0f || parentSize.height <= 0.0f)
            {
                _positionPercent = Vec2::ZERO;
            }
            else
            {
                _positionPercent = Vec2(absPos.x / parentSize.width, absPos.y / parentSize.height);
            }
            break;
        }
        case PositionType::PERCENT:
        {
            absPos = Vec2(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
            break;
        }
        default:
            break;
    }
    setPosition(absPos);
}

void Widget::setSizeType(SizeType type)
{
    _sizeType = type;
    _widthSizeType = type;
    _heigthSizeType = type;
}

Widget::SizeType Widget::getSizeType() const
{
    return _sizeType;
}
    
Widget::SizeType Widget::getWidthSizeType() const
{
    return _widthSizeType;
}
    
Widget::SizeType Widget::getHeightSizeType() const
{
    return _heigthSizeType;
}

void Widget::ignoreContentAdaptWithSize(bool ignore)
{
    if (_unifySize)
    {
        this->setContentSize(_customSize);
        return;
    }
    if (_ignoreSize == ignore)
    {
        return;
    }
    _ignoreSize = ignore;
    if (_ignoreSize)
    {
        Size s = getVirtualRendererSize();
        this->setContentSize(s);
    }
    else
    {
        this->setContentSize(_customSize);
    }
}

bool Widget::isIgnoreContentAdaptWithSize() const
{
    return _ignoreSize;
}

const Size& Widget::getSize() const
{
    return this->getContentSize();
}
    
const Size& Widget::getCustomSize() const
{
    return _customSize;
}

const Vec2& Widget::getSizePercent()
{
    return _sizePercent;
}

Vec2 Widget::getWorldPosition()const
{
    return convertToWorldSpace(Vec2(_anchorPoint.x * _contentSize.width, _anchorPoint.y * _contentSize.height));
}

Node* Widget::getVirtualRenderer()
{
    return this;
}

void Widget::onSizeChanged(const Size& oldSize)
{
    Layout* parentLayout = dynamic_cast<Layout*>(getParent());
    if (parentLayout) {
        parentLayout->onChildSizeChanged(this,oldSize);
    }
    
    for (auto& child : getChildren())
    {
        Widget* widgetChild = dynamic_cast<Widget*>(child);
        if (widgetChild)
        {
            widgetChild->updateSizeAndPosition();
        }
    }
}

Size Widget::getVirtualRendererSize() const
{
    return _contentSize;
}
    
void Widget::updateContentSizeWithTextureSize(const cocos2d::Size &size)
{
    if (_unifySize)
    {
        this->setContentSize(size);
        return;
    }
    if (_ignoreSize)
    {
        this->setContentSize(size);
    }
    else
    {
        this->setContentSize(_customSize);
    }
}

void Widget::setTouchEnabled(bool enable)
{
    if (enable == _touchEnabled)
    {
        return;
    }
    _touchEnabled = enable;
    if (_touchEnabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        CC_SAFE_RETAIN(_touchListener);
        _touchListener->setSwallowTouches(true);
        _touchListener->onTouchBegan = CC_CALLBACK_2(Widget::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(Widget::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(Widget::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(Widget::onTouchCancelled, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _eventDispatcher->removeEventListener(_touchListener);
        CC_SAFE_RELEASE_NULL(_touchListener);
    }
}

bool Widget::isTouchEnabled() const
{
    return _touchEnabled;
}

bool Widget::isHighlighted() const
{
    return _highlight;
}

void Widget::setHighlighted(bool hilight)
{
    if (hilight == _highlight)
    {
        return;
    }
    _highlight = hilight;
    if (_bright)
    {
        if (_highlight)
        {
            setBrightStyle(BrightStyle::HIGHLIGHT);
        }
        else
        {
            setBrightStyle(BrightStyle::NORMAL);
        }
    }
    else
    {
        onPressStateChangedToDisabled();
    }
}

void Widget::setBright(bool bright)
{
    _bright = bright;
    if (_bright)
    {
        _brightStyle = BrightStyle::NONE;
        setBrightStyle(BrightStyle::NORMAL);
    }
    else
    {
        onPressStateChangedToDisabled();
    }
}

void Widget::setBrightStyle(BrightStyle style)
{
    if (_brightStyle == style)
    {
        return;
    }
    _brightStyle = style;
    switch (_brightStyle)
    {
        case BrightStyle::NORMAL:
            onPressStateChangedToNormal();
            break;
        case BrightStyle::HIGHLIGHT:
            onPressStateChangedToPressed();
            break;
        default:
            break;
    }
}

void Widget::onPressStateChangedToNormal()
{

}

void Widget::onPressStateChangedToPressed()
{

}

void Widget::onPressStateChangedToDisabled()
{

}
    
void Widget::updateChildrenDisplayedRGBA()
{
    this->setColor(this->getColor());
    this->setOpacity(this->getOpacity());
}

    
Widget* Widget::getAncensterWidget(Node* node)
{
    if (nullptr == node)
    {
        return nullptr;
    }
    
    Node* parent = node->getParent();
    if (nullptr == parent)
    {
        return nullptr;
    }
    Widget* parentWidget = dynamic_cast<Widget*>(parent);
    if (parentWidget)
    {
        return parentWidget;
    }
    else
    {
        return this->getAncensterWidget(parent->getParent());
    }
}
    
bool Widget::isAncestorsVisible(Node* node)
{
    if (nullptr == node)
    {
        return true;
    }
    Node* parent = node->getParent();
    
    if (parent && !parent->isVisible())
    {
        return false;
    }
    return this->isAncestorsVisible(parent);
}
    
bool Widget::isAncestorsEnabled()
{
    Widget* parentWidget = this->getAncensterWidget(this);
    if (parentWidget == nullptr)
    {
        return true;
    }
    if (parentWidget && !parentWidget->isEnabled())
    {
        return false;
    }
    
    return parentWidget->isAncestorsEnabled();
}
    
void Widget::setPropagateTouchEvents(bool isPropagate)
{
    _propagateTouchEvents = isPropagate;
}
    
bool Widget::isPropagateTouchEvents()const
{
    return _propagateTouchEvents;
}
    
void Widget::setSwallowTouches(bool swallow)
{
    if (_touchListener)
    {
        _touchListener->setSwallowTouches(swallow);
    }
}
    
bool Widget::isSwallowTouches()const
{
    if (_touchListener)
    {
        return _touchListener->isSwallowTouches();
    }
    return false;
}

bool Widget::onTouchBegan(Touch *touch, Event *unusedEvent)
{
    _hitted = false;
    if (isVisible() && isEnabled() && isAncestorsEnabled() && isAncestorsVisible(this) )
    {
        _touchBeganPosition = touch->getLocation();
        if(hitTest(_touchBeganPosition) && isClippingParentContainsPoint(_touchBeganPosition))
        {
            _hitted = true;
        }
    }
    if (!_hitted)
    {
        return false;
    }
    setHighlighted(true);
    
    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::BEGAN, this, touch);
    }
  
    pushDownEvent();
    return true;
}
    
void Widget::propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
{
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(event, sender, touch);
    }
}

void Widget::onTouchMoved(Touch *touch, Event *unusedEvent)
{
    _touchMovePosition = touch->getLocation();
    
    setHighlighted(hitTest(_touchMovePosition));
    
    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::MOVED, this, touch);
    }
    
    moveEvent();
}

void Widget::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    _touchEndPosition = touch->getLocation();
    
    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::ENDED, this, touch);
    }
    
    bool highlight = _highlight;
    setHighlighted(false);
    
    if (highlight)
    {
        releaseUpEvent();
    }
    else
    {
        cancelUpEvent();
    }
}

void Widget::onTouchCancelled(Touch *touch, Event *unusedEvent)
{
    setHighlighted(false);
    cancelUpEvent();
}

void Widget::pushDownEvent()
{
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::BEGAN);
    }
    
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_BEGAN);
    }
    
    //propagate to children
    if (_propagateTouchEventsToChildren) {
        for (const auto& child : getChildren()) {
            Widget* childWidget = dynamic_cast<Widget*>(child);
            if (childWidget) {
                childWidget->pushDownEvent();
            }
        }
    }
    
    this->release();
}

void Widget::moveEvent()
{
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::MOVED);
    }
    
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_MOVED);
    }
    this->release();
}

void Widget::releaseUpEvent()
{
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::ENDED);
    }
    
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_ENDED);
    }
    
    if (_clickEventListener) {
        _clickEventListener(this);
    }
    
    //propagate to children
    if (_propagateTouchEventsToChildren) {
        for (const auto& child : getChildren()) {
            Widget* childWidget = dynamic_cast<Widget*>(child);
            if (childWidget) {
                childWidget->releaseUpEvent();
            }
        }
    }
    
    this->release();
}

void Widget::cancelUpEvent()
{
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::CANCELED);
    }
   
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_CANCELED);
    }
    
    //propagate to children
    if (_propagateTouchEventsToChildren) {
        for (const auto& child : getChildren()) {
            Widget* childWidget = dynamic_cast<Widget*>(child);
            if (childWidget) {
                childWidget->cancelUpEvent();
            }
        }
    }
    
    this->release();
}

void Widget::addTouchEventListener(Ref *target, SEL_TouchEvent selector)
{
    _touchEventListener = target;
    _touchEventSelector = selector;
}
    
void Widget::addTouchEventListener(const ccWidgetTouchCallback& callback)
{
    this->_touchEventCallback = callback;
}
    
void Widget::addClickEventListener(const ccWidgetClickCallback &callback)
{
    this->_clickEventListener = callback;
}
    
void Widget::addCCSEventListener(const ccWidgetEventCallback &callback)
{
    this->_ccEventCallback = callback;
}

bool Widget::hitTest(const Vec2 &pt)
{
    Vec2 nsp = convertToNodeSpace(pt);
    Rect bb;
    bb.size = _contentSize;
    if (bb.containsPoint(nsp))
    {
        return true;
    }
    return false;
}

bool Widget::isClippingParentContainsPoint(const Vec2 &pt)
{
    _affectByClipping = false;
    Widget* parent = getWidgetParent();
    Widget* clippingParent = nullptr;
    while (parent)
    {
        Layout* layoutParent = dynamic_cast<Layout*>(parent);
        if (layoutParent)
        {
            if (layoutParent->isClippingEnabled())
            {
                _affectByClipping = true;
                clippingParent = layoutParent;
                break;
            }
        }
        parent = parent->getWidgetParent();
    }

    if (!_affectByClipping)
    {
        return true;
    }


    if (clippingParent)
    {
        bool bRet = false;
        if (clippingParent->hitTest(pt))
        {
            bRet = true;
        }
        if (bRet)
        {
            return clippingParent->isClippingParentContainsPoint(pt);
        }
        return false;
    }
    return true;
}

void Widget::interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, Touch *touch)
{
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(event,sender,touch);
    }

}

void Widget::setPosition(const Vec2 &pos)
{
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        if (widgetParent)
        {
            Size pSize = widgetParent->getContentSize();
            if (pSize.width <= 0.0f || pSize.height <= 0.0f)
            {
                _positionPercent = Vec2::ZERO;
            }
            else
            {
                _positionPercent = Vec2(pos.x / pSize.width, pos.y / pSize.height);
            }
        }
    }
    ProtectedNode::setPosition(pos);
}

void Widget::setPositionPercent(const Vec2 &percent)
{
    _positionPercent = percent;
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        if (widgetParent)
        {
            Size parentSize = widgetParent->getContentSize();
            Vec2 absPos = Vec2(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
            setPosition(absPos);
        }
    }
}

const Vec2& Widget::getPositionPercent()const{
    return _positionPercent;
}

void Widget::setPositionType(PositionType type)
{
    _positionType = type;
}

Widget::PositionType Widget::getPositionType() const
{
    return _positionType;
}

bool Widget::isBright() const
{
    return _bright;
}

bool Widget::isEnabled() const
{
    return _enabled;
}

float Widget::getLeftBoundary() const
{
    return getPosition().x - getAnchorPoint().x * _contentSize.width;
}

float Widget::getBottomBoundary() const
{
    return getPosition().y - getAnchorPoint().y * _contentSize.height;
}

float Widget::getRightBoundary() const
{
    return getLeftBoundary() + _contentSize.width;
}

float Widget::getTopBoundary() const
{
    return getBottomBoundary() + _contentSize.height;
}

const Vec2& Widget::getTouchBeganPosition()const
{
    return _touchBeganPosition;
}

const Vec2& Widget::getTouchMovePosition()const
{
    return _touchMovePosition;
}

const Vec2& Widget::getTouchEndPosition()const
{
    return _touchEndPosition;
}

void Widget::setLayoutParameter(LayoutParameter *parameter)
{
    if (!parameter)
    {
        return;
    }
    
    LayoutParameter* currentLayoutParameter = getLayoutParameter();
    assert(currentLayoutParameter!=parameter);
    if (parameter == currentLayoutParameter) {
        return;
    }
    
    remedyLayoutParameter(parameter);
    
    _layoutParameterDictionary.insert((int)parameter->getLayoutType(), parameter);
    _layoutParameterType = parameter->getLayoutType();
    
    layoutParameterChanged();
}
    
void Widget::layoutParameterChanged() {
    
    //if parent is layout request layout
    Layout* parentLayout = dynamic_cast<Layout*>(getParent());
    if (parentLayout) {
        parentLayout->requestDoLayout();
    }
}

LayoutParameter* Widget::getLayoutParameter()const
{
    return dynamic_cast<LayoutParameter*>(_layoutParameterDictionary.at((int)_layoutParameterType));
}
    
LayoutParameter* Widget::getLayoutParameter(LayoutParameter::Type type)
{
    return dynamic_cast<LayoutParameter*>(_layoutParameterDictionary.at((int)type));
}

std::string Widget::getDescription() const
{
    return "Widget";
}

Widget* Widget::clone()
{
    Widget* clonedWidget = createCloneInstance();
    clonedWidget->copyProperties(this);
    clonedWidget->copyClonedWidgetChildren(this);
    return clonedWidget;
}

Widget* Widget::createCloneInstance()
{
    return Widget::create();
}

void Widget::copyClonedWidgetChildren(Widget* model)
{
    auto& modelChildren = model->getChildren();

    for (auto& subWidget : modelChildren)
    {
        Widget* child = dynamic_cast<Widget*>(subWidget);
        if (child)
        {
            addChild(child->clone());
        }
    }
}

void Widget::copySpecialProperties(Widget* model)
{

}

void Widget::copyProperties(Widget *widget)
{
    setEnabled(widget->isEnabled());
    setVisible(widget->isVisible());
    setBright(widget->isBright());
    setTouchEnabled(widget->isTouchEnabled());
    setLocalZOrder(widget->getLocalZOrder());
    setTag(widget->getTag());
    setName(widget->getName());
    setActionTag(widget->getActionTag());
    _ignoreSize = widget->_ignoreSize;
    this->setContentSize(widget->_contentSize);
    _customSize = widget->_customSize;
    _sizeType = widget->getSizeType();
    _widthSizeType = widget->getWidthSizeType();
    _heigthSizeType = widget->getHeightSizeType();
    _sizePercent = widget->_sizePercent;
    _positionType = widget->_positionType;
    _positionPercent = widget->_positionPercent;
    setPosition(widget->getPosition());
    setAnchorPoint(widget->getAnchorPoint());
    setScaleX(widget->getScaleX());
    setScaleY(widget->getScaleY());
    setRotation(widget->getRotation());
    setRotationSkewX(widget->getRotationSkewX());
    setRotationSkewY(widget->getRotationSkewY());
    setFlippedX(widget->isFlippedX());
    setFlippedY(widget->isFlippedY());
    setColor(widget->getColor());
    setOpacity(widget->getOpacity());
    _touchEventCallback = widget->_touchEventCallback;
    _touchEventListener = widget->_touchEventListener;
    _touchEventSelector = widget->_touchEventSelector;
    _clickEventListener = widget->_clickEventListener;
    _focused = widget->_focused;
    _focusEnabled = widget->_focusEnabled;
    _propagateTouchEvents = widget->_propagateTouchEvents;
    _propagateTouchEventsToChildren = widget->_propagateTouchEventsToChildren;
    
    copySpecialProperties(widget);

    Map<int, LayoutParameter*>& layoutParameterDic = widget->_layoutParameterDictionary;
    for (auto iter = layoutParameterDic.begin(); iter != layoutParameterDic.end(); ++iter)
    {
        setLayoutParameter(iter->second->clone());
    }
}
    
    void Widget::setFlippedX(bool flippedX)
    {
        
        float realScale = this->getScaleX();
        _flippedX = flippedX;
        this->setScaleX(realScale);
    }
    
    void Widget::setFlippedY(bool flippedY)
    {
        float realScale = this->getScaleY();
        _flippedY = flippedY;
        this->setScaleY(realScale);
    }
    
   
    
    void Widget::setScaleX(float scaleX)
    {
        if (_flippedX) {
            scaleX = scaleX * -1;
        }
        Node::setScaleX(scaleX);
    }
    
    void Widget::setScaleY(float scaleY)
    {
        if (_flippedY) {
            scaleY = scaleY * -1;
        }
        Node::setScaleY(scaleY);
    }
    
    void Widget::setScale(float scale)
    {
        this->setScaleX(scale);
        this->setScaleY(scale);
        this->setScaleZ(scale);
    }
    
    void Widget::setScale(float scaleX, float scaleY)
    {
        this->setScaleX(scaleX);
        this->setScaleY(scaleY);
    }
    
    float Widget::getScaleX()const
    {
        float originalScale = Node::getScaleX();
        if (_flippedX)
        {
            originalScale = originalScale * -1.0;
        }
        return originalScale;
    }
    
    float Widget::getScaleY()const
    {
        float originalScale = Node::getScaleY();
        if (_flippedY)
        {
            originalScale = originalScale * -1.0;
        }
        return originalScale;
    }
    
    float Widget::getScale()const
    {
        CCASSERT(this->getScaleX() == this->getScaleY(), "");
        return this->getScaleX();
    }


/*temp action*/
void Widget::setActionTag(int tag)
{
	_actionTag = tag;
}

int Widget::getActionTag()const
{
	return _actionTag;
}
    
void Widget::setFocused(bool focus)
{
    _focused = focus;
    
    //make sure there is only one focusedWidget
    if (focus) {
        _focusedWidget = this;
        if (_focusNavigationController) {
            _focusNavigationController->setFirstFocsuedWidget(this);
        }
    }
    
}

bool Widget::isFocused()const
{
    return _focused;
}

void Widget::setFocusEnabled(bool enable)
{
    _focusEnabled = enable;
}

bool Widget::isFocusEnabled()const
{
    return _focusEnabled;
}

Widget* Widget::findNextFocusedWidget(FocusDirection direction,  Widget* current)
{
    if (nullptr == onNextFocusedWidget || nullptr == onNextFocusedWidget(direction) ) {
        if (this->isFocused() || dynamic_cast<Layout*>(current))
        {
            Node* parent = this->getParent();
            
            Layout* layout = dynamic_cast<Layout*>(parent);
            if (nullptr == layout)
            {
                //the outer layout's default behaviour is : loop focus
                if (dynamic_cast<Layout*>(current))
                {
                    return current->findNextFocusedWidget(direction, current);
                }
                return current;
            }
            else
            {
                Widget *nextWidget = layout->findNextFocusedWidget(direction, current);
                return nextWidget;
            }
        }
        else
        {
            return current;
        }
    }
    else
    {
        Widget *getFocusWidget = onNextFocusedWidget(direction);
        this->dispatchFocusEvent(this, getFocusWidget);
        return getFocusWidget;
    }
}

void Widget::dispatchFocusEvent(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)
{
    //if the widgetLoseFocus doesn't get focus, it will use the previous focused widget instead
    if (widgetLoseFocus && !widgetLoseFocus->isFocused())
    {
        widgetLoseFocus = _focusedWidget;
    }
    
    if (widgetGetFocus != widgetLoseFocus)
    {
        
        if (widgetGetFocus)
        {
            widgetGetFocus->onFocusChanged(widgetLoseFocus, widgetGetFocus);
        }
        
        if (widgetLoseFocus)
        {
            widgetLoseFocus->onFocusChanged(widgetLoseFocus, widgetGetFocus);
        }
        
        EventFocus event(widgetLoseFocus, widgetGetFocus);
        auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->dispatchEvent(&event);
    }
    
}

void Widget::requestFocus()
{
    if (this == _focusedWidget)
    {
        return;
    }
    
    this->dispatchFocusEvent(_focusedWidget, this);
}
    
void Widget::onFocusChange(Widget* widgetLostFocus, Widget* widgetGetFocus)
{
    //only change focus when there is indeed a get&lose happens
    if (widgetLostFocus)
    {
        widgetLostFocus->setFocused(false);
    }
    
    if (widgetGetFocus)
    {
        widgetGetFocus->setFocused(true);
    }
}

Widget* Widget::getCurrentFocusedWidget()const
{
    return _focusedWidget;
}

void Widget::enableDpadNavigation(bool enable)
{
    if (enable)
    {
        if (nullptr == _focusNavigationController)
        {
            _focusNavigationController = new (std::nothrow) FocusNavigationController;
            if (_focusedWidget) {
                _focusNavigationController->setFirstFocsuedWidget(_focusedWidget);
            }
        }
    }
    else
    {
        CC_SAFE_DELETE(_focusNavigationController);
    }
    _focusNavigationController->enableFocusNavigation(enable);
}


bool Widget::isUnifySizeEnabled()const
{
    return _unifySize;
}

void Widget::setUnifySizeEnabled(bool enable)
{
    _unifySize = enable;
}

void Widget::setVisibility(Visibility visibility) {
    
    if (_visibility == visibility) {
        return;
    }
    
    _visibility = visibility;
    
    if (_visibility == Visibility::VISIBLE) {
        setVisible(true);
    }
    else {
        setVisible(false);
    }
    
    LayoutParameter* llp = getLayoutParameter();
    if (llp) {
        remedyLayoutParameter(llp);
    }
    
    //if parent is layout request layout
    Layout* parentLayout = dynamic_cast<Layout*>(getParent());
    if (parentLayout) {
        parentLayout->requestDoLayout();
    }
}

Widget::Visibility Widget::getVisibility() {
    return _visibility;
}
    
void Widget::remedyLayoutParameter(LayoutParameter* parameter) {
    
    if (_visibility == Visibility::COLLAPSED || _ignoreLayout == true) {
        parameter->setCollapsed(true);
    }
    else {
        parameter->setCollapsed(false);
    }
}
void Widget::setDebugDraw(bool debugDraw) {
#if MF_ALLOW_WIDGET_DEBUG_DRAW

    if (_debugDraw != debugDraw) {
        
        _debugDraw = debugDraw;
        
        if (_debugDraw && _debugDrawNode == nullptr) {
            _debugDrawNode = DrawNode::create();
            addChild(_debugDrawNode);
        }
        
        if (!_debugDraw && _debugDrawNode) {
            _debugDrawNode->removeFromParentAndCleanup(true);
            _debugDrawNode = nullptr;
        }
    }
#endif

}

bool Widget::getDebugDraw() {
#if MF_ALLOW_WIDGET_DEBUG_DRAW
    return _debugDraw;
#else
    return false;
#endif
}

#if MF_ALLOW_WIDGET_DEBUG_DRAW
void Widget::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    Node::draw(renderer, transform, flags);
    if (_debugDraw && _debugDrawNode) {
        _debugDrawNode->clear();
        auto size = getContentSize();
        Point vertices[4]=
        {
            Point::ZERO,
            Point(size.width, 0),
            Point(size.width, size.height),
            Point(0, size.height)
        };
        _debugDrawNode->drawPoly(vertices, 4, true, Color4F(1.0, 1.0, 1.0, 1.0));
    }
}
#endif

void Widget::setIgnoreLayout(bool ignoreLayout) {
    
    if (ignoreLayout != _ignoreLayout) {
        _ignoreLayout = ignoreLayout;
        LayoutParameter* llp = getLayoutParameter();
        if (llp) {
            remedyLayoutParameter(llp);
        }

    }
}
    
bool Widget::getIgnoreLayout() const {
    return _ignoreLayout;
}

void Widget::setSizePercentSourceDimension(SizePercentSourceDimension sizePercentDimension) {
    _sizePercentDimension = sizePercentDimension;
}

const Widget::SizePercentSourceDimension& Widget::getSizePercentSourceDimension() {
    return _sizePercentDimension;
}

void Widget::setPropagateTouchEventsToChildren(bool isPropagate)
{
    _propagateTouchEventsToChildren = isPropagate;
}

bool Widget::isPropagateTouchEventsToChildren()const
{
    return _propagateTouchEvents;
}
}
NS_CC_END
