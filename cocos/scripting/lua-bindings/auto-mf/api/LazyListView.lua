
--------------------------------
-- @module LazyListView
-- @extend ScrollView
-- @parent_module mf

--------------------------------
-- Changes the gravity of LazyListView.<br>
-- see LazyListViewGravity
-- @function [parent=#LazyListView] setGravity 
-- @param self
-- @param #int gravity
        
--------------------------------
-- Removes the last item of LazyListView.
-- @function [parent=#LazyListView] removeLastItem 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LazyListView] getCurSelectedIndex 
-- @param self
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#LazyListView] getItemsMargin 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#LazyListView] getDataSource 
-- @param self
-- @return mf::LazyListViewDataSource#mf::LazyListViewDataSource ret (return value: cc.mf::LazyListViewDataSource)
        
--------------------------------
-- Returns the index of item.<br>
-- param item  the item which need to be checked.<br>
-- return the index of item.
-- @function [parent=#LazyListView] getIndex 
-- @param self
-- @param #ccui.Widget item
-- @return long#long ret (return value: long)
        
--------------------------------
-- Push back custom item into LazyListView.
-- @function [parent=#LazyListView] pushBackCustomItem 
-- @param self
-- @param #ccui.Widget item
        
--------------------------------
-- Insert a default item(create by a cloned model) into LazyListView.
-- @function [parent=#LazyListView] insertDefaultItem 
-- @param self
-- @param #long index
        
--------------------------------
-- 
-- @function [parent=#LazyListView] addEventListener 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#LazyListView] doLayout 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LazyListView] removeAllItems 
-- @param self
        
--------------------------------
-- Returns the item container.
-- @function [parent=#LazyListView] getItems 
-- @param self
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- Changes the margin between each item.<br>
-- param margin
-- @function [parent=#LazyListView] setItemsMargin 
-- @param self
-- @param #float margin
        
--------------------------------
-- Returns a item whose index is same as the parameter.<br>
-- param index of item.<br>
-- return the item widget.
-- @function [parent=#LazyListView] getItem 
-- @param self
-- @param #long index
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- Removes a item whose index is same as the parameter.<br>
-- param index of item.
-- @function [parent=#LazyListView] removeItem 
-- @param self
-- @param #long index
        
--------------------------------
-- Push back a default item(create by a cloned model) into LazyListView.
-- @function [parent=#LazyListView] pushBackDefaultItem 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LazyListView] refreshView 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LazyListView] setDataSource 
-- @param self
-- @param #cc.mf::LazyListViewDataSource dataSource
        
--------------------------------
-- Sets a item model for LazyListView<br>
-- A model will be cloned for adding default item.<br>
-- param model  item model for LazyListView
-- @function [parent=#LazyListView] setItemModel 
-- @param self
-- @param #ccui.Widget model
        
--------------------------------
-- 
-- @function [parent=#LazyListView] requestRefreshView 
-- @param self
        
--------------------------------
-- Insert custom item into LazyListView.
-- @function [parent=#LazyListView] insertCustomItem 
-- @param self
-- @param #ccui.Widget item
-- @param #long index
        
--------------------------------
-- Allocates and initializes.
-- @function [parent=#LazyListView] create 
-- @param self
-- @return mf::LazyListView#mf::LazyListView ret (return value: cc.mf::LazyListView)
        
--------------------------------
-- 
-- @function [parent=#LazyListView] createInstance 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- @overload self, cc.Node, int         
-- @overload self, cc.Node         
-- @overload self, cc.Node, int, int         
-- @overload self, cc.Node, int, string         
-- @function [parent=#LazyListView] addChild
-- @param self
-- @param #cc.Node child
-- @param #int zOrder
-- @param #string name

--------------------------------
-- Changes scroll direction of scrollview.<br>
-- see Direction Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll<br>
-- param dir, set the list view's scroll direction
-- @function [parent=#LazyListView] setDirection 
-- @param self
-- @param #int dir
        
--------------------------------
-- 
-- @function [parent=#LazyListView] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#LazyListView] removeAllChildrenWithCleanup 
-- @param self
-- @param #bool cleanup
        
--------------------------------
-- 
-- @function [parent=#LazyListView] removeAllChildren 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LazyListView] removeChild 
-- @param self
-- @param #cc.Node child
-- @param #bool cleaup
        
--------------------------------
-- Default constructor
-- @function [parent=#LazyListView] LazyListView 
-- @param self
        
return nil
