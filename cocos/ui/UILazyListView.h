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


#ifndef __UILazyListView_H__
#define __UILazyListView_H__

#include "ui/UIScrollView.h"

NS_CC_BEGIN

namespace experimental{
namespace ui{
    
class LazyListViewDataSource : public Ref
{
public:
    static LazyListViewDataSource* create();
    
    virtual ~LazyListViewDataSource();
    
public:
    std::function<int()> numElements;
    std::function<cocos2d::ui::Widget*(int,cocos2d::ui::Widget*)> elementForIndex;
    virtual LazyListViewDataSource* clone();
    bool isValid();
    
private:
    LazyListViewDataSource();
    bool init();
};
    
typedef enum
{
    LazyListView_ONSELECTEDITEM_START,
    LazyListView_ONSELECTEDITEM_END
}LazyListViewEventType;

typedef void (Ref::*SEL_LazyListViewEvent)(Ref*,LazyListViewEventType);
#define LazyListVieweventselector(_SELECTOR) (SEL_LazyListViewEvent)(&_SELECTOR)

    
class LazyListView : public ::cocos2d::ui::ScrollView
{
 
    DECLARE_CLASS_GUI_INFO
    
public:
    enum class Gravity
    {
        LEFT,
        RIGHT,
        CENTER_HORIZONTAL,
        TOP,
        BOTTOM,
        CENTER_VERTICAL
    };
    
    enum class EventType
    {
        ON_SELECTED_ITEM_START,
        ON_SELECTED_ITEM_END
    };
    
    typedef std::function<void(Ref*, EventType)> ccLazyListViewCallback;
    
    /**
     * Default constructor
     */
    LazyListView();
    
    /**
     * Default destructor
     */
    virtual ~LazyListView();
    
    /**
     * Allocates and initializes.
     */
    static LazyListView* create();
    
    /**
     * Sets a item model for LazyListView
     *
     * A model will be cloned for adding default item.
     *
     * @param model  item model for LazyListView
     */
    void setItemModel(Widget* model);
    
    /**
     * Push back a default item(create by a cloned model) into LazyListView.
     */
    void pushBackDefaultItem();
    
    /**
     * Insert a default item(create by a cloned model) into LazyListView.
     */
    void insertDefaultItem(ssize_t index);
    
    /**
     * Push back custom item into LazyListView.
     */
    void pushBackCustomItem(Widget* item);
    
    /**
     * Insert custom item into LazyListView.
     */
    void insertCustomItem(Widget* item, ssize_t index);
    
    /**
     *  Removes the last item of LazyListView.
     */
    void removeLastItem();
    
    /**
     * Removes a item whose index is same as the parameter.
     *
     * @param index of item.
     */
    void removeItem(ssize_t index);
    
    void removeAllItems();
    
    /**
     * Returns a item whose index is same as the parameter.
     *
     * @param index of item.
     *
     * @return the item widget.
     */
    Widget* getItem(ssize_t index)const;
    
    /**
     * Returns the item container.
     */
    Vector<Widget*>& getItems();
    
    /**
     * Returns the index of item.
     *
     * @param item  the item which need to be checked.
     *
     * @return the index of item.
     */
    ssize_t getIndex(Widget* item) const;
    
    /**
     * Changes the gravity of LazyListView.
     * @see LazyListViewGravity
     */
    void setGravity(Gravity gravity);
    
    /**
     * Changes the margin between each item.
     *
     * @param margin
     */
    void setItemsMargin(float margin);
    
    float getItemsMargin()const;
    
    virtual void doLayout() override;
    
    virtual void addChild(Node* child)override;
    virtual void addChild(Node * child, int localZOrder)override;
    virtual void addChild(Node* child, int zOrder, int tag) override;
    virtual void addChild(Node* child, int zOrder, const std::string &name) override;
    virtual void removeAllChildren() override;
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;
	virtual void removeChild(Node* child, bool cleaup = true) override;
    
    ssize_t getCurSelectedIndex() const;
    
    CC_DEPRECATED_ATTRIBUTE void addEventListenerLazyListView(Ref* target, SEL_LazyListViewEvent selector);
    void addEventListener(const ccLazyListViewCallback& callback);
    using ScrollView::addEventListener;

    /**
     * Changes scroll direction of scrollview.
     *
     * @see Direction Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll
     *
     * @param dir, set the list view's scroll direction
     */
    virtual void setDirection(Direction dir) override;
    
    virtual std::string getDescription() const override;
    
    void requestRefreshView();
    void refreshView();
    
    virtual void moveChildren(float offsetX, float offsetY) override;
    Rect getVisibleBoundingBox() const;
    std::pair<int, int> syncVisibleElements(int firstVisibileElementIndex, int lastVisibileElementIndex);
    std::pair<int, int> calcVisibleIndexRange() const;
    void adjustPadding(std::pair<int, int> syncResult);
    
    void setDataSource(LazyListViewDataSource* dataSource);
    LazyListViewDataSource* getDataSource() const;
    
CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;
    
protected:
    
    void updateInnerContainerSize();
    void remedyLayoutParameter(Widget* item);
    virtual void onSizeChanged() override;
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
    virtual void copyClonedWidgetChildren(Widget* model) override;
    void selectedItemEvent(TouchEventType event);
    virtual void interceptTouchEvent(Widget::TouchEventType event,Widget* sender,Touch* touch) override;
protected:
    Widget* _model;
    
    Vector<Widget*> _items;
    
    Gravity _gravity;
    
    float _itemsMargin;
    int _firstVisibleElementIndex;
    
    ssize_t _curSelectedIndex;
    bool _refreshViewDirty;
    
    Ref*       _LazyListViewEventListener;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif
    SEL_LazyListViewEvent    _LazyListViewEventSelector;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif
    ccLazyListViewCallback _eventCallback;
    
    LazyListViewDataSource* _dataSource;
    Vector<Widget*> _cachedWidgets;
};

}
}
NS_CC_END

#endif /* defined(__LazyListView__) */
