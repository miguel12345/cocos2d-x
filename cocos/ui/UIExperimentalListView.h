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


#ifndef __UIExperimentalListView_H__
#define __UIExperimentalListView_H__

#include "ui/UIScrollView.h"

NS_CC_BEGIN

namespace experimental{
namespace ui{
    
class ExperimentalListViewDataSource : public Ref
{
public:
    static ExperimentalListViewDataSource* create();
    
    virtual ~ExperimentalListViewDataSource();
    
public:
    std::function<int()> numElements;
    std::function<cocos2d::ui::Widget*(int,cocos2d::ui::Widget*)> elementForIndex;
    virtual ExperimentalListViewDataSource* clone();
    bool isValid();
    
private:
    ExperimentalListViewDataSource();
    bool init();
};
    
typedef enum
{
    ExperimentalListView_ONSELECTEDITEM_START,
    ExperimentalListView_ONSELECTEDITEM_END
}ExperimentalListViewEventType;

typedef void (Ref::*SEL_ExperimentalListViewEvent)(Ref*,ExperimentalListViewEventType);
#define ExperimentalListVieweventselector(_SELECTOR) (SEL_ExperimentalListViewEvent)(&_SELECTOR)

    
class ExperimentalListView : public ::cocos2d::ui::ScrollView
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
    
    typedef std::function<void(Ref*, EventType)> ccExperimentalListViewCallback;
    
    /**
     * Default constructor
     */
    ExperimentalListView();
    
    /**
     * Default destructor
     */
    virtual ~ExperimentalListView();
    
    /**
     * Allocates and initializes.
     */
    static ExperimentalListView* create();
    
    /**
     * Sets a item model for ExperimentalListView
     *
     * A model will be cloned for adding default item.
     *
     * @param model  item model for ExperimentalListView
     */
    void setItemModel(Widget* model);
    
    /**
     * Push back a default item(create by a cloned model) into ExperimentalListView.
     */
    void pushBackDefaultItem();
    
    /**
     * Insert a default item(create by a cloned model) into ExperimentalListView.
     */
    void insertDefaultItem(ssize_t index);
    
    /**
     * Push back custom item into ExperimentalListView.
     */
    void pushBackCustomItem(Widget* item);
    
    /**
     * Insert custom item into ExperimentalListView.
     */
    void insertCustomItem(Widget* item, ssize_t index);
    
    /**
     *  Removes the last item of ExperimentalListView.
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
     * Changes the gravity of ExperimentalListView.
     * @see ExperimentalListViewGravity
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
    
    CC_DEPRECATED_ATTRIBUTE void addEventListenerExperimentalListView(Ref* target, SEL_ExperimentalListViewEvent selector);
    void addEventListener(const ccExperimentalListViewCallback& callback);
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
    
    void setDataSource(ExperimentalListViewDataSource* dataSource);
    ExperimentalListViewDataSource* getDataSource() const;
    
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
    
    Ref*       _ExperimentalListViewEventListener;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif
    SEL_ExperimentalListViewEvent    _ExperimentalListViewEventSelector;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif
    ccExperimentalListViewCallback _eventCallback;
    
    ExperimentalListViewDataSource* _dataSource;
    Vector<Widget*> _cachedWidgets;
};

}
}
NS_CC_END

#endif /* defined(__ExperimentalListView__) */
