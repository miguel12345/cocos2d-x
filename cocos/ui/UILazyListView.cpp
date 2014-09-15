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

#include "ui/UILazyListView.h"
#include "ui/UIHelper.h"
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"

NS_CC_BEGIN
namespace experimental {
namespace ui {
    
    using namespace cocos2d::ui;
    
    
    LazyListViewDataSource::LazyListViewDataSource()
    : numElements(nullptr)
    , elementForIndex(nullptr)
    {
    }
    
    LazyListViewDataSource::~LazyListViewDataSource()
    {
        CCLOGINFO("In the destructor of LazyListViewDataSource, %p", this);
    }
    
    bool LazyListViewDataSource::init()
    {
        return true;
    }

    LazyListViewDataSource* LazyListViewDataSource::create()
    {
        auto ret = new LazyListViewDataSource();
        if (ret && ret->init())
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(ret);
        }
        return ret;
    }
    
    LazyListViewDataSource* LazyListViewDataSource::clone()
    {
        auto ret = new LazyListViewDataSource();
        if (ret && ret->init())
        {
            ret->autorelease();
            
            ret->numElements = numElements;
            ret->elementForIndex = elementForIndex;
        }
        else
        {
            CC_SAFE_DELETE(ret);
        }
        return ret;
    }
    
    bool LazyListViewDataSource::isValid() {
        return elementForIndex != nullptr && numElements != nullptr;
    }

    
IMPLEMENT_CLASS_GUI_INFO(LazyListView)

LazyListView::LazyListView():
_model(nullptr),
_gravity(Gravity::CENTER_VERTICAL),
_itemsMargin(0.0f),
_LazyListViewEventListener(nullptr),
_LazyListViewEventSelector(nullptr),
_curSelectedIndex(0),
_refreshViewDirty(true),
_eventCallback(nullptr),
_dataSource(nullptr),
_firstVisibleElementIndex(0)
{
    this->setTouchEnabled(true);
}

LazyListView::~LazyListView()
{
    _LazyListViewEventListener = nullptr;
    _LazyListViewEventSelector = nullptr;
    _items.clear();
    CC_SAFE_RELEASE(_model);
}

LazyListView* LazyListView::create()
{
    LazyListView* widget = new LazyListView();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool LazyListView::init()
{
    if (ScrollView::init())
    {
        setLayoutType(Type::VERTICAL);
        return true;
    }
    return false;
}

void LazyListView::setItemModel(Widget *model)
{
    if (!model)
    {
        return;
    }
    CC_SAFE_RELEASE_NULL(_model);
    _model = model;
    CC_SAFE_RETAIN(_model);
}

void LazyListView::updateInnerContainerSize()
{
    switch (_direction)
    {
        case Direction::VERTICAL:
        {
            size_t length = _dataSource->numElements();
            float totalHeight = length>0?((length ) * _itemsMargin):0;
            setInnerContainerSize(Size(_contentSize.width, totalHeight + _dataSource->numElements() * _model->getContentSize().height));
            break;
        }
        case Direction::HORIZONTAL:
        {
            size_t length = _dataSource->numElements();
            float totalWidth = length>0?((length ) * _itemsMargin):0;
            setInnerContainerSize(Size(totalWidth + _dataSource->numElements() * _model->getContentSize().width, _contentSize.height));
            break;
        }
        default:
            break;
    }
}

void LazyListView::remedyLayoutParameter(Widget *item)
{
    if (!item)
    {
        return;
    }
    switch (_direction) {
        case Direction::VERTICAL:
        {
            LinearLayoutParameter* llp = (LinearLayoutParameter*)(item->getLayoutParameter());
            if (!llp)
            {
                LinearLayoutParameter* defaultLp = LinearLayoutParameter::create();
                switch (_gravity) {
                    case Gravity::LEFT:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
                        break;
                    case Gravity::RIGHT:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
                        break;
                    case Gravity::CENTER_HORIZONTAL:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
                        break;
                    default:
                        break;
                }
                defaultLp->setMargin(Margin(0.0f, _itemsMargin, 0.0f, 0.0f));

                item->setLayoutParameter(defaultLp);
            }
            else
            {
                llp->setMargin(Margin(0.0f, _itemsMargin, 0.0f, 0.0f));

                switch (_gravity) {
                    case Gravity::LEFT:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
                        break;
                    case Gravity::RIGHT:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
                        break;
                    case Gravity::CENTER_HORIZONTAL:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
                        break;
                    default:
                        break;
                }
            }
            break;
        }
        case Direction::HORIZONTAL:
        {
            LinearLayoutParameter* llp = (LinearLayoutParameter*)(item->getLayoutParameter());
            if (!llp)
            {
                LinearLayoutParameter* defaultLp = LinearLayoutParameter::create();
                switch (_gravity) {
                    case Gravity::TOP:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::TOP);
                        break;
                    case Gravity::BOTTOM:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::BOTTOM);
                        break;
                    case Gravity::CENTER_VERTICAL:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
                        break;
                    default:
                        break;
                }
                defaultLp->setMargin(Margin(_itemsMargin, 0.0f, 0.0f, 0.0f));

                item->setLayoutParameter(defaultLp);
            }
            else
            {
                llp->setMargin(Margin(_itemsMargin, 0.0f, 0.0f, 0.0f));

                switch (_gravity) {
                    case Gravity::TOP:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::TOP);
                        break;
                    case Gravity::BOTTOM:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::BOTTOM);
                        break;
                    case Gravity::CENTER_VERTICAL:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
                        break;
                    default:
                        break;
                }
            }
            break;
        }
        default:
            break;
    }
    
}

void LazyListView::pushBackDefaultItem()
{
    if (!_model)
    {
        return;
    }
    Widget* newItem = _model->clone();
    remedyLayoutParameter(newItem);
    addChild(newItem);
    _refreshViewDirty = true;
}

void LazyListView::insertDefaultItem(ssize_t index)
{
    if (!_model)
    {
        return;
    }
    Widget* newItem = _model->clone();
    
    _items.insert(index, newItem);
    ScrollView::addChild(newItem);

    remedyLayoutParameter(newItem);
    
    _refreshViewDirty = true;
}


void LazyListView::pushBackCustomItem(Widget* item)
{
    remedyLayoutParameter(item);
    addChild(item);
    _refreshViewDirty = true;
}
    
void LazyListView::addChild(cocos2d::Node *child, int zOrder, int tag)
{
    ScrollView::addChild(child, zOrder, tag);

    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget)
    {
        _items.pushBack(widget);
    }
}
    
void LazyListView::addChild(cocos2d::Node *child)
{
    LazyListView::addChild(child, child->getLocalZOrder(), child->getName());
}

void LazyListView::addChild(cocos2d::Node *child, int zOrder)
{
    LazyListView::addChild(child, zOrder, child->getName());
}
 
void LazyListView::addChild(Node* child, int zOrder, const std::string &name)
{
    ScrollView::addChild(child, zOrder, name);
    
    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget)
    {
        _items.pushBack(widget);
    }
}
    
void LazyListView::removeChild(cocos2d::Node *child, bool cleaup)
{
    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget) {
        _items.eraseObject(widget);
    }
   
    ScrollView::removeChild(child, cleaup);
}
    
void LazyListView::removeAllChildren()
{
    this->removeAllChildrenWithCleanup(true);
}
    
void LazyListView::removeAllChildrenWithCleanup(bool cleanup)
{
    ScrollView::removeAllChildrenWithCleanup(cleanup);
    _items.clear();
}

void LazyListView::insertCustomItem(Widget* item, ssize_t index)
{
    _items.insert(index, item);
    ScrollView::addChild(item);

    remedyLayoutParameter(item);
    _refreshViewDirty = true;
}

void LazyListView::removeItem(ssize_t index)
{
    Widget* item = getItem(index);
    if (!item)
    {
        return;
    }
    removeChild(item, true);
    
    _refreshViewDirty = true;
}

void LazyListView::removeLastItem()
{
    removeItem(_items.size() -1);
}
    
void LazyListView::removeAllItems()
{
    removeAllChildren();
}

Widget* LazyListView::getItem(ssize_t index)const
{
    if (index < 0 || index >= _items.size())
    {
        return nullptr;
    }
    return _items.at(index);
}

Vector<Widget*>& LazyListView::getItems()
{
    return _items;
}

ssize_t LazyListView::getIndex(Widget *item) const
{
    if (!item)
    {
        return -1;
    }
    return _items.getIndex(item);
}

void LazyListView::setGravity(Gravity gravity)
{
    if (_gravity == gravity)
    {
        return;
    }
    _gravity = gravity;
    _refreshViewDirty = true;
}

void LazyListView::setItemsMargin(float margin)
{
    if (_itemsMargin == margin)
    {
        return;
    }
    _itemsMargin = margin;
    _refreshViewDirty = true;
}
    
float LazyListView::getItemsMargin()const
{
    return _itemsMargin;
}

void LazyListView::setDirection(Direction dir)
{
    switch (dir)
    {
        case Direction::VERTICAL:
            setLayoutType(Type::VERTICAL);
            break;
        case Direction::HORIZONTAL:
            setLayoutType(Type::HORIZONTAL);
            break;
        case Direction::BOTH:
            return;
        default:
            return;
            break;
    }
    ScrollView::setDirection(dir);
}
    
void LazyListView::requestRefreshView()
{
    _refreshViewDirty = true;
}

void LazyListView::refreshView()
{
    ssize_t length = _items.size();
    for (int i=0; i<length; i++)
    {
        Widget* item = _items.at(i);
        item->setLocalZOrder(i);
        remedyLayoutParameter(item);
    }
    updateInnerContainerSize();
}
    
void LazyListView::doLayout()
{
    Layout::doLayout();
    
    if (_refreshViewDirty)
    {
        refreshView();
        _refreshViewDirty = false;
    }
    
    if (_direction == Direction::HORIZONTAL) {
        scrollChildren(0, 0); //force redraw
    }
}
    
void LazyListView::addEventListenerLazyListView(Ref *target, SEL_LazyListViewEvent selector)
{
    _LazyListViewEventListener = target;
    _LazyListViewEventSelector = selector;
}

    
void LazyListView::addEventListener(const ccLazyListViewCallback& callback)
{
    _eventCallback = callback;
}
    
void LazyListView::selectedItemEvent(TouchEventType event)
{
    switch (event)
    {
        case TouchEventType::BEGAN:
        {
            if (_LazyListViewEventListener && _LazyListViewEventSelector)
            {
                (_LazyListViewEventListener->*_LazyListViewEventSelector)(this, LazyListView_ONSELECTEDITEM_START);
            }
            if (_eventCallback) {
                _eventCallback(this,EventType::ON_SELECTED_ITEM_START);
            }
        }
        break;
        default:
        {
            if (_LazyListViewEventListener && _LazyListViewEventSelector)
            {
                (_LazyListViewEventListener->*_LazyListViewEventSelector)(this, LazyListView_ONSELECTEDITEM_END);
            }
            if (_eventCallback) {
                _eventCallback(this, EventType::ON_SELECTED_ITEM_END);
            }
        }
        break;
    }

}
    
void LazyListView::interceptTouchEvent(TouchEventType event, Widget *sender, Touch* touch)
{
    ScrollView::interceptTouchEvent(event, sender, touch);
    if (event != TouchEventType::MOVED)
    {
        Widget* parent = sender;
        while (parent)
        {
            if (parent && parent->getParent() == _innerContainer)
            {
                _curSelectedIndex = getIndex(parent);
                break;
            }
            parent = dynamic_cast<Widget*>(parent->getParent());
        }
        if (sender->isHighlighted()) {
            selectedItemEvent(event);
        }
    }
}
    
ssize_t LazyListView::getCurSelectedIndex() const
{
    return _curSelectedIndex;
}

void LazyListView::onSizeChanged()
{
    ScrollView::onSizeChanged();
    _refreshViewDirty = true;
}

std::string LazyListView::getDescription() const
{
    return "LazyListView";
}

Widget* LazyListView::createCloneInstance()
{
    return LazyListView::create();
}

void LazyListView::copyClonedWidgetChildren(Widget* model)
{
    auto& arrayItems = static_cast<LazyListView*>(model)->getItems();
    for (auto& item : arrayItems)
    {
        pushBackCustomItem(item->clone());
    }
}

void LazyListView::copySpecialProperties(Widget *widget)
{
    LazyListView* LazyListViewEx = dynamic_cast<LazyListView*>(widget);
    if (LazyListViewEx)
    {
        ScrollView::copySpecialProperties(widget);
        setItemModel(LazyListViewEx->_model);
        setItemsMargin(LazyListViewEx->_itemsMargin);
        setGravity(LazyListViewEx->_gravity);
        setDataSource(LazyListViewEx->getDataSource());
        _LazyListViewEventListener = LazyListViewEx->_LazyListViewEventListener;
        _LazyListViewEventSelector = LazyListViewEx->_LazyListViewEventSelector;
        _eventCallback = LazyListViewEx->_eventCallback;
    }
}

void LazyListView::moveChildren(float offsetX, float offsetY)  {
    ScrollView::moveChildren(offsetX,offsetY);
    std::pair<int, int> visibleIndexRange = calcVisibleIndexRange();
    std::pair<int, int> syncResult = syncVisibleElements(visibleIndexRange.first,visibleIndexRange.second);
    adjustPadding(syncResult);
}
    
    
    std::pair<int, int> LazyListView::calcVisibleIndexRange() const {
    
        Rect visibleBoundingBox = getVisibleBoundingBox();
        
        switch (_direction) {
            case Direction::VERTICAL:{
                float yMin = _innerContainer->getContentSize().height + visibleBoundingBox.origin.y - visibleBoundingBox.size.height;
                float yMax = yMin + visibleBoundingBox.size.height;
                
                int firstVisibileElementIndex = floor(yMin / (_model->getContentSize().height + _itemsMargin));
                int lastVisibileElementIndex = floor(yMax / (_model->getContentSize().height + _itemsMargin));
                return std::pair<int, int>(firstVisibileElementIndex,lastVisibileElementIndex);
            }
                break;
            case Direction::HORIZONTAL: {
                float xMin = -visibleBoundingBox.origin.x;
                float xMax = xMin + visibleBoundingBox.size.width;
                
                int firstVisibileElementIndex = floor(xMin / (_model->getContentSize().width + _itemsMargin));
                int lastVisibileElementIndex = floor(xMax / (_model->getContentSize().width + _itemsMargin));
                return std::pair<int, int>(firstVisibileElementIndex,lastVisibileElementIndex);
            }
                break;
            default:
                CCASSERT(false, "Unsupported direction");
                break;
                
        }
        
        CCASSERT(false, "");
    }
    
    Rect LazyListView::getVisibleBoundingBox() const {
        switch (_direction) {
            case Direction::VERTICAL:
                return Rect(0, _innerContainer->getPosition().y, _contentSize.width, getContentSize().height);
                break;
            case Direction::HORIZONTAL:
                return Rect(_innerContainer->getPosition().x, 0, getContentSize().width , _contentSize.height);
                break;
            default:
                CCASSERT(false, "Unsupported direction");
                break;

        }
        
        CCASSERT(false, "");
    }

    std::pair<int, int> LazyListView::syncVisibleElements(int firstVisibileElementIndex , int lastVisibileElementIndex ) {
        
        std::pair<int, int> syncResult;
        
        if (_items.size() == 0) {
            _firstVisibleElementIndex = 0;
        }
        
        /* First, we remove all the items to fill the cache vector as much as possible */
        
        while (_firstVisibleElementIndex < firstVisibileElementIndex) {
            _cachedWidgets.pushBack(_items.at(0));
            removeChild(_items.at(0));
            syncResult.first++;
            _firstVisibleElementIndex ++;
        }
        
        int _lastVisibileElementIndex = _firstVisibleElementIndex + _items.size() - 1;
        
        while (_lastVisibileElementIndex > lastVisibileElementIndex) {
            _cachedWidgets.pushBack(_items.at(_items.size()-1));
            removeLastItem();
            _lastVisibileElementIndex--;
        }
        
        /* Then we we fill the empty spots in the vector, using the cached widgets as a base for the delegate to change */
        
        while (_firstVisibleElementIndex > firstVisibileElementIndex) {
            insertCustomItem(_dataSource->elementForIndex(--_firstVisibleElementIndex,_cachedWidgets.size()>0?_cachedWidgets.back():_model->clone()), 0);
            syncResult.second++;
            if (_cachedWidgets.size()>0) {
                _cachedWidgets.popBack();
            }
        }
        
        
        while (_lastVisibileElementIndex < lastVisibileElementIndex) {
            pushBackCustomItem(_dataSource->elementForIndex(++_lastVisibileElementIndex,_cachedWidgets.size()>0?_cachedWidgets.back():_model->clone()));
            if (_cachedWidgets.size()>0) {
                _cachedWidgets.popBack();
            }
        }
        
        
        /* Sync result holds the number of top removals/insertions */
        
        return syncResult;
    }
    
    void LazyListView::adjustPadding(std::pair<int, int> syncResult) {
        
        Padding curPadding = getPadding();
        int topRemovals = syncResult.first;
        int topInsertions = syncResult.second;
        
        switch (_direction) {
            case ScrollView::Direction::VERTICAL:
                curPadding.top += (topRemovals*(_model->getContentSize().height + _itemsMargin)) - (topInsertions*(_model->getContentSize().height + _itemsMargin));
                break;
            case ScrollView::Direction::HORIZONTAL:
                curPadding.left += (topRemovals*(_model->getContentSize().width + _itemsMargin)) - (topInsertions*(_model->getContentSize().width + _itemsMargin));
                break;
            default:
                CCASSERT(false, "Unsupported direction");
                break;
                
        }
        setPadding(curPadding);
    }
    
    void LazyListView::setDataSource(LazyListViewDataSource* dataSource) {
        CC_SAFE_RELEASE_NULL(_dataSource);
        _dataSource = dataSource;
        CC_SAFE_RETAIN(_dataSource);
    }
    
    LazyListViewDataSource* LazyListView::getDataSource() const {
        return _dataSource;
    }
    
}
}
NS_CC_END
