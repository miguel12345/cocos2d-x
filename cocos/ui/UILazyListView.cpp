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

#include "ui/UIExperimentalListView.h"
#include "ui/UIHelper.h"
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"

NS_CC_BEGIN
namespace experimental {
namespace ui {
    
    using namespace cocos2d::ui;
    
    
    ExperimentalListViewDataSource::ExperimentalListViewDataSource()
    : numElements(nullptr)
    , elementForIndex(nullptr)
    {
    }
    
    ExperimentalListViewDataSource::~ExperimentalListViewDataSource()
    {
        CCLOGINFO("In the destructor of ExperimentalListViewDataSource, %p", this);
    }
    
    bool ExperimentalListViewDataSource::init()
    {
        return true;
    }

    ExperimentalListViewDataSource* ExperimentalListViewDataSource::create()
    {
        auto ret = new ExperimentalListViewDataSource();
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
    
    ExperimentalListViewDataSource* ExperimentalListViewDataSource::clone()
    {
        auto ret = new ExperimentalListViewDataSource();
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
    
    bool ExperimentalListViewDataSource::isValid() {
        return elementForIndex != nullptr && numElements != nullptr;
    }

    
IMPLEMENT_CLASS_GUI_INFO(ExperimentalListView)

ExperimentalListView::ExperimentalListView():
_model(nullptr),
_gravity(Gravity::CENTER_VERTICAL),
_itemsMargin(0.0f),
_ExperimentalListViewEventListener(nullptr),
_ExperimentalListViewEventSelector(nullptr),
_curSelectedIndex(0),
_refreshViewDirty(true),
_eventCallback(nullptr),
_dataSource(nullptr),
_firstVisibleElementIndex(0)
{
    this->setTouchEnabled(true);
}

ExperimentalListView::~ExperimentalListView()
{
    _ExperimentalListViewEventListener = nullptr;
    _ExperimentalListViewEventSelector = nullptr;
    _items.clear();
    CC_SAFE_RELEASE(_model);
}

ExperimentalListView* ExperimentalListView::create()
{
    ExperimentalListView* widget = new ExperimentalListView();
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool ExperimentalListView::init()
{
    if (ScrollView::init())
    {
        setLayoutType(Type::VERTICAL);
        return true;
    }
    return false;
}

void ExperimentalListView::setItemModel(Widget *model)
{
    if (!model)
    {
        return;
    }
    CC_SAFE_RELEASE_NULL(_model);
    _model = model;
    CC_SAFE_RETAIN(_model);
}

void ExperimentalListView::updateInnerContainerSize()
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

void ExperimentalListView::remedyLayoutParameter(Widget *item)
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

void ExperimentalListView::pushBackDefaultItem()
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

void ExperimentalListView::insertDefaultItem(ssize_t index)
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


void ExperimentalListView::pushBackCustomItem(Widget* item)
{
    remedyLayoutParameter(item);
    addChild(item);
    _refreshViewDirty = true;
}
    
void ExperimentalListView::addChild(cocos2d::Node *child, int zOrder, int tag)
{
    ScrollView::addChild(child, zOrder, tag);

    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget)
    {
        _items.pushBack(widget);
    }
}
    
void ExperimentalListView::addChild(cocos2d::Node *child)
{
    ExperimentalListView::addChild(child, child->getLocalZOrder(), child->getName());
}

void ExperimentalListView::addChild(cocos2d::Node *child, int zOrder)
{
    ExperimentalListView::addChild(child, zOrder, child->getName());
}
 
void ExperimentalListView::addChild(Node* child, int zOrder, const std::string &name)
{
    ScrollView::addChild(child, zOrder, name);
    
    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget)
    {
        _items.pushBack(widget);
    }
}
    
void ExperimentalListView::removeChild(cocos2d::Node *child, bool cleaup)
{
    Widget* widget = dynamic_cast<Widget*>(child);
    if (widget) {
        _items.eraseObject(widget);
    }
   
    ScrollView::removeChild(child, cleaup);
}
    
void ExperimentalListView::removeAllChildren()
{
    this->removeAllChildrenWithCleanup(true);
}
    
void ExperimentalListView::removeAllChildrenWithCleanup(bool cleanup)
{
    ScrollView::removeAllChildrenWithCleanup(cleanup);
    _items.clear();
}

void ExperimentalListView::insertCustomItem(Widget* item, ssize_t index)
{
    _items.insert(index, item);
    ScrollView::addChild(item);

    remedyLayoutParameter(item);
    _refreshViewDirty = true;
}

void ExperimentalListView::removeItem(ssize_t index)
{
    Widget* item = getItem(index);
    if (!item)
    {
        return;
    }
    removeChild(item, true);
    
    _refreshViewDirty = true;
}

void ExperimentalListView::removeLastItem()
{
    removeItem(_items.size() -1);
}
    
void ExperimentalListView::removeAllItems()
{
    removeAllChildren();
}

Widget* ExperimentalListView::getItem(ssize_t index)const
{
    if (index < 0 || index >= _items.size())
    {
        return nullptr;
    }
    return _items.at(index);
}

Vector<Widget*>& ExperimentalListView::getItems()
{
    return _items;
}

ssize_t ExperimentalListView::getIndex(Widget *item) const
{
    if (!item)
    {
        return -1;
    }
    return _items.getIndex(item);
}

void ExperimentalListView::setGravity(Gravity gravity)
{
    if (_gravity == gravity)
    {
        return;
    }
    _gravity = gravity;
    _refreshViewDirty = true;
}

void ExperimentalListView::setItemsMargin(float margin)
{
    if (_itemsMargin == margin)
    {
        return;
    }
    _itemsMargin = margin;
    _refreshViewDirty = true;
}
    
float ExperimentalListView::getItemsMargin()const
{
    return _itemsMargin;
}

void ExperimentalListView::setDirection(Direction dir)
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
    
void ExperimentalListView::requestRefreshView()
{
    _refreshViewDirty = true;
}

void ExperimentalListView::refreshView()
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
    
void ExperimentalListView::doLayout()
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
    
void ExperimentalListView::addEventListenerExperimentalListView(Ref *target, SEL_ExperimentalListViewEvent selector)
{
    _ExperimentalListViewEventListener = target;
    _ExperimentalListViewEventSelector = selector;
}

    
void ExperimentalListView::addEventListener(const ccExperimentalListViewCallback& callback)
{
    _eventCallback = callback;
}
    
void ExperimentalListView::selectedItemEvent(TouchEventType event)
{
    switch (event)
    {
        case TouchEventType::BEGAN:
        {
            if (_ExperimentalListViewEventListener && _ExperimentalListViewEventSelector)
            {
                (_ExperimentalListViewEventListener->*_ExperimentalListViewEventSelector)(this, ExperimentalListView_ONSELECTEDITEM_START);
            }
            if (_eventCallback) {
                _eventCallback(this,EventType::ON_SELECTED_ITEM_START);
            }
        }
        break;
        default:
        {
            if (_ExperimentalListViewEventListener && _ExperimentalListViewEventSelector)
            {
                (_ExperimentalListViewEventListener->*_ExperimentalListViewEventSelector)(this, ExperimentalListView_ONSELECTEDITEM_END);
            }
            if (_eventCallback) {
                _eventCallback(this, EventType::ON_SELECTED_ITEM_END);
            }
        }
        break;
    }

}
    
void ExperimentalListView::interceptTouchEvent(TouchEventType event, Widget *sender, Touch* touch)
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
    
ssize_t ExperimentalListView::getCurSelectedIndex() const
{
    return _curSelectedIndex;
}

void ExperimentalListView::onSizeChanged()
{
    ScrollView::onSizeChanged();
    _refreshViewDirty = true;
}

std::string ExperimentalListView::getDescription() const
{
    return "ExperimentalListView";
}

Widget* ExperimentalListView::createCloneInstance()
{
    return ExperimentalListView::create();
}

void ExperimentalListView::copyClonedWidgetChildren(Widget* model)
{
    auto& arrayItems = static_cast<ExperimentalListView*>(model)->getItems();
    for (auto& item : arrayItems)
    {
        pushBackCustomItem(item->clone());
    }
}

void ExperimentalListView::copySpecialProperties(Widget *widget)
{
    ExperimentalListView* ExperimentalListViewEx = dynamic_cast<ExperimentalListView*>(widget);
    if (ExperimentalListViewEx)
    {
        ScrollView::copySpecialProperties(widget);
        setItemModel(ExperimentalListViewEx->_model);
        setItemsMargin(ExperimentalListViewEx->_itemsMargin);
        setGravity(ExperimentalListViewEx->_gravity);
        setDataSource(ExperimentalListViewEx->getDataSource());
        _ExperimentalListViewEventListener = ExperimentalListViewEx->_ExperimentalListViewEventListener;
        _ExperimentalListViewEventSelector = ExperimentalListViewEx->_ExperimentalListViewEventSelector;
        _eventCallback = ExperimentalListViewEx->_eventCallback;
    }
}

void ExperimentalListView::moveChildren(float offsetX, float offsetY)  {
    ScrollView::moveChildren(offsetX,offsetY);
    std::pair<int, int> visibleIndexRange = calcVisibleIndexRange();
    std::pair<int, int> syncResult = syncVisibleElements(visibleIndexRange.first,visibleIndexRange.second);
    adjustPadding(syncResult);
}
    
    
    std::pair<int, int> ExperimentalListView::calcVisibleIndexRange() const {
    
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
    
    Rect ExperimentalListView::getVisibleBoundingBox() const {
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

    std::pair<int, int> ExperimentalListView::syncVisibleElements(int firstVisibileElementIndex , int lastVisibileElementIndex ) {
        
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
    
    void ExperimentalListView::adjustPadding(std::pair<int, int> syncResult) {
        
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
    
    void ExperimentalListView::setDataSource(ExperimentalListViewDataSource* dataSource) {
        CC_SAFE_RELEASE_NULL(_dataSource);
        _dataSource = dataSource;
        CC_SAFE_RETAIN(_dataSource);
    }
    
    ExperimentalListViewDataSource* ExperimentalListView::getDataSource() const {
        return _dataSource;
    }
    
}
}
NS_CC_END
