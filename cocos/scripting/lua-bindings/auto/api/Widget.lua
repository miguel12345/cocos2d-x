
--------------------------------
-- @module Widget
-- @extend ProtectedNode,LayoutParameterProtocol
-- @parent_module ccui

--------------------------------
-- Gets the Virtual Renderer of widget.<br>
-- For example, a button's Virtual Renderer is it's texture renderer.<br>
-- return Node pointer.
-- @function [parent=#Widget] getVirtualRenderer 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- 
-- @function [parent=#Widget] getCustomSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- 
-- @function [parent=#Widget] setActionTag 
-- @param self
-- @param #int tag
        
--------------------------------
-- brief Specify widget to swallow touches or not<br>
-- since v3.3
-- @function [parent=#Widget] setSwallowTouches 
-- @param self
-- @param #bool swallow
        
--------------------------------
-- Changes the current size percent dimension enum that affects<br>
-- how are the percentage values transformed into absolute values.<br>
-- param sizePercentDimension SizePercentSourceDimension
-- @function [parent=#Widget] setSizePercentSourceDimension 
-- @param self
-- @param #int sizePercentDimension
        
--------------------------------
-- Gets the position type of the widget<br>
-- see PositionType<br>
-- return type  the position type of widget
-- @function [parent=#Widget] getPositionType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- Changes widget visibility<br>
-- - Hidden: will be considered in the layout process<br>
-- but will not be renderered<br>
-- - Collapsed: will not be considered in the layout<br>
-- process nor rendered<br>
-- - Visible: will be considered in the layout process<br>
-- and will be renderered<br>
-- param Visibility the visibility of the widget
-- @function [parent=#Widget] setVisibility 
-- @param self
-- @param #int 
        
--------------------------------
-- Determines if the widget is enabled<br>
-- return true if the widget is enabled, false if the widget is disabled.
-- @function [parent=#Widget] isEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- When a widget is in a layout, you could call this method to get the next focused widget within a specified direction. <br>
-- If the widget is not in a layout, it will return itself<br>
-- param dir the direction to look for the next focused widget in a layout<br>
-- param current  the current focused widget<br>
-- return the next focused widget in a layout
-- @function [parent=#Widget] findNextFocusedWidget 
-- @param self
-- @param #int direction
-- @param #ccui.Widget current
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- param focus  pass true to let the widget get focus or pass false to let the widget lose focus<br>
-- return void
-- @function [parent=#Widget] setFocused 
-- @param self
-- @param #bool focus
        
--------------------------------
-- Sets if the widget will ignore layout. This<br>
-- is a sign to the layout manager that this widget<br>
-- should not be taken into account in the layout process.<br>
-- Note The call to this method does not request the parent<br>
-- to do a layout.<br>
-- param ignoreLayout Bool
-- @function [parent=#Widget] setIgnoreLayout 
-- @param self
-- @param #bool ignoreLayout
        
--------------------------------
-- Changes the current propagate to children attribute.<br>
-- If it is set to true, all touch events callbacks are propagated to its<br>
-- widget children. <br>
-- This DOES NOT propagate touch interceptions. This only affect the methods<br>
-- pushDownEvent()/moveEvent()/releaseUpEvent()/cancelUpEvent() and calls <br>
-- the same method on all of its children.<br>
-- param isPropagate bool
-- @function [parent=#Widget] setPropagateTouchEventsToChildren 
-- @param self
-- @param #bool isPropagate
        
--------------------------------
-- 
-- @function [parent=#Widget] getWidgetParent 
-- @param self
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- Gets LayoutParameter of widget.<br>
-- see LayoutParameter<br>
-- param type  Relative or Linear<br>
-- return LayoutParameter
-- @function [parent=#Widget] getLayoutParameter 
-- @param self
-- @return LayoutParameter#LayoutParameter ret (return value: ccui.LayoutParameter)
        
--------------------------------
-- Determines if the widget is bright<br>
-- return true if the widget is bright, false if the widget is dark.
-- @function [parent=#Widget] isBright 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] getCurrentFocusedWidget 
-- @param self
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- Changes the minimum size of the widget<br>
-- A negative value in one of the dimensions<br>
-- means that there is no minimum value restriction<br>
-- param maxSize that is the widget minimum allowed size
-- @function [parent=#Widget] setMinSize 
-- @param self
-- @param #size_table minSize
        
--------------------------------
-- Gets the size type of widget.<br>
-- see SizeType<br>
-- param type that is widget's size type
-- @function [parent=#Widget] getSizeType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#Widget] getReportToParentSizeChanged 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] getCallbackType 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- Gets the percent (x,y) of the widget in OpenGL coordinates<br>
-- see setPosition(const Vec2&)<br>
-- return The percent (x,y) of the widget in OpenGL coordinates
-- @function [parent=#Widget] getPositionPercent 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- Set a click event handler to the widget
-- @function [parent=#Widget] addClickEventListener 
-- @param self
-- @param #function callback
        
--------------------------------
-- Returns the flag which indicates whether the widget is flipped horizontally or not.<br>
-- It only flips the texture of the widget, and not the texture of the widget's children.<br>
-- Also, flipping the texture doesn't alter the anchorPoint.<br>
-- If you want to flip the anchorPoint too, and/or to flip the children too use:<br>
-- widget->setScaleX(sprite->getScaleX() * -1);<br>
-- return true if the widget is flipped horizaontally, false otherwise.
-- @function [parent=#Widget] isFlippedX 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Return the flag which indicates whether the widget is flipped vertically or not.<br>
-- It only flips the texture of the widget, and not the texture of the widget's children.<br>
-- Also, flipping the texture doesn't alter the anchorPoint.<br>
-- If you want to flip the anchorPoint too, and/or to flip the children too use:<br>
-- widget->setScaleY(widget->getScaleY() * -1);<br>
-- return true if the widget is flipped vertically, flase otherwise.
-- @function [parent=#Widget] isFlippedY 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] isClippingParentContainsPoint 
-- @param self
-- @param #vec2_table pt
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] setIgnoreFollowingTouchMoved 
-- @param self
-- @param #bool ignoreFollowingTouchMoved
        
--------------------------------
-- Gets the size type of widget for the height dimension.<br>
-- see SizeType<br>
-- param type that is widget's size type
-- @function [parent=#Widget] getHeightSizeType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- Returns size percent of widget<br>
-- return size percent
-- @function [parent=#Widget] getSizePercent 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#Widget] getTouchEndPosition 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#Widget] getLayoutSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- Changes the position type of the widget<br>
-- see PositionType<br>
-- param type  the position type of widget
-- @function [parent=#Widget] setPositionType 
-- @param self
-- @param #int type
        
--------------------------------
-- 
-- @function [parent=#Widget] getContentSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- Request the widget to update its size and position<br>
-- the next time they are needed. Since this function<br>
-- only sets a flag, we can call it many times without<br>
-- incurring performance penalties
-- @function [parent=#Widget] requestUpdateSizeAndPosition 
-- @param self
        
--------------------------------
-- Determines if the widget is highlighted<br>
-- return true if the widget is highlighted, false if the widget is not hignlighted .
-- @function [parent=#Widget] isHighlighted 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- callbackName getter and setter.
-- @function [parent=#Widget] setCallbackName 
-- @param self
-- @param #string callbackName
        
--------------------------------
-- Determines if the widget is touch enabled<br>
-- return true if the widget is touch enabled, false if the widget is touch disabled.
-- @function [parent=#Widget] isTouchEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Sets whether the widget is touch enabled<br>
-- The default value is false, a widget is default to touch disabled<br>
-- param visible   true if the widget is touch enabled, false if the widget is touch disabled.
-- @function [parent=#Widget] setTouchEnabled 
-- @param self
-- @param #bool enabled
        
--------------------------------
-- Returns the current _propagateTouchEventsToChildren attribute<br>
-- return bool
-- @function [parent=#Widget] isPropagateTouchEventsToChildren 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] getRightBoundary 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Sets a LayoutParameter to widget.<br>
-- see LayoutParameter<br>
-- param LayoutParameter pointer<br>
-- param type  Relative or Linear
-- @function [parent=#Widget] setLayoutParameter 
-- @param self
-- @param #ccui.LayoutParameter parameter
        
--------------------------------
-- param enable pass true/false to enable/disable the focus ability of a widget<br>
-- return void
-- @function [parent=#Widget] setFocusEnabled 
-- @param self
-- @param #bool enable
        
--------------------------------
-- 
-- @function [parent=#Widget] getTouchMovePosition 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- Changes the size type of widget.<br>
-- see SizeType<br>
-- param type that is widget's size type
-- @function [parent=#Widget] setSizeTypes 
-- @param self
-- @param #int widthType
-- @param #int heightType
        
--------------------------------
-- Gets the size type of widget for the width dimension.<br>
-- see SizeType<br>
-- param type that is widget's size type
-- @function [parent=#Widget] getWidthSizeType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- return  whether the widget is focused or not
-- @function [parent=#Widget] isFocused 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- If an outside entity retrieves the layout parameter with getLayoutParameter<br>
-- and then applies some changes to it, it MUST call this method<br>
-- in order to ensure proper behavior.<br>
-- Please make sure that the layout parameter has indeed changed to prevent<br>
-- CPU waste (since this method will provoke a layout of the parent<br>
-- element)
-- @function [parent=#Widget] layoutParameterChanged 
-- @param self
        
--------------------------------
-- brief Allow widget touch events to propagate to its parents. Set false will disable propagation<br>
-- since v3.3
-- @function [parent=#Widget] setPropagateTouchEvents 
-- @param self
-- @param #bool isPropagate
        
--------------------------------
-- return true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
-- @function [parent=#Widget] isUnifySizeEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Set the percent(x,y) of the widget in OpenGL coordinates<br>
-- param percent  The percent (x,y) of the widget in OpenGL coordinates
-- @function [parent=#Widget] setPositionPercent 
-- @param self
-- @param #vec2_table percent
        
--------------------------------
-- Sets whether the widget is hilighted<br>
-- The default value is false, a widget is default to not hilighted<br>
-- param hilight   true if the widget is hilighted, false if the widget is not hilighted.
-- @function [parent=#Widget] setHighlighted 
-- @param self
-- @param #bool hilight
        
--------------------------------
-- 
-- @function [parent=#Widget] getVirtualRendererSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- Set a event handler to the widget in order to use cocostudio editor and framework
-- @function [parent=#Widget] addCCSEventListener 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#Widget] getTopBoundary 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Note: when you set _ignoreSize to true, no matther you call setContentSize or not, <br>
-- the widget size is always equal to the return value of the member function getVirtualRendererSize.<br>
-- param ignore, set member variabl _ignoreSize to ignore
-- @function [parent=#Widget] ignoreContentAdaptWithSize 
-- @param self
-- @param #bool ignore
        
--------------------------------
-- 
-- @function [parent=#Widget] getTouchBeganPosition 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- Sets whether the widget should be flipped vertically or not.<br>
-- param bFlippedY true if the widget should be flipped vertically, flase otherwise.
-- @function [parent=#Widget] setFlippedY 
-- @param self
-- @param #bool flippedY
        
--------------------------------
-- Sets whether the widget is enabled<br>
-- true if the widget is enabled, widget may be touched , false if the widget is disabled, widget cannot be touched.<br>
-- The default value is true, a widget is default to enabled<br>
-- param enabled
-- @function [parent=#Widget] setEnabled 
-- @param self
-- @param #bool enabled
        
--------------------------------
-- To set the bright style of widget.<br>
-- see BrightStyle<br>
-- param style   BrightStyle::NORMAL means the widget is in normal state, BrightStyle::HIGHLIGHT means the widget is in highlight state.
-- @function [parent=#Widget] setBrightStyle 
-- @param self
-- @param #int style
        
--------------------------------
-- when a widget calls this method, it will get focus immediately.
-- @function [parent=#Widget] requestFocus 
-- @param self
        
--------------------------------
-- param enable Unify Size of a widget<br>
-- return void
-- @function [parent=#Widget] setUnifySizeEnabled 
-- @param self
-- @param #bool enable
        
--------------------------------
-- Sets whether this widget should report to its parent<br>
-- the change of its size. If you want the layout to<br>
-- always remain correct, this should be set to true. If<br>
-- you don't mind the incorrectness of the layout <br>
-- and want performance this should be set to false.<br>
-- The default value is true<br>
-- It is recommended that you set this to false only <br>
-- when you need to update the content size continously,<br>
-- for example by using ResizeTo action<br>
-- param reportToParentSizeChanged reportToParentSizeChanged
-- @function [parent=#Widget] setReportToParentSizeChanged 
-- @param self
-- @param #bool reportToParentSizeChanged
        
--------------------------------
-- Returns the accumulated size of this widget's content<br>
-- Subclass can and should override this if they have a custom<br>
-- way of calculating the accumulated size<br>
-- return Size
-- @function [parent=#Widget] getWrapContentSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- Checks a point if is in widget's space<br>
-- param point<br>
-- return true if the point is in widget's space, flase otherwise.
-- @function [parent=#Widget] hitTest 
-- @param self
-- @param #vec2_table pt
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Gets the current SizePercentSourceDimension<br>
-- return SizePercentSourceDimension
-- @function [parent=#Widget] getSizePercentSourceDimension 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- callbackType getter and setter.
-- @function [parent=#Widget] setCallbackType 
-- @param self
-- @param #string callbackType
        
--------------------------------
-- Changes the size that is widget's size<br>
-- param size that is widget's size
-- @function [parent=#Widget] setSizeValues 
-- @param self
-- @param #size_table values
        
--------------------------------
-- 
-- @function [parent=#Widget] addTouchEventListener 
-- @param self
-- @param #function callback
        
--------------------------------
-- Changes the percent that is widget's percent size<br>
-- param percent that is widget's percent size
-- @function [parent=#Widget] setSizePercent 
-- @param self
-- @param #vec2_table percent
        
--------------------------------
-- 
-- @function [parent=#Widget] getLeftBoundary 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Sets whether the widget should be flipped horizontally or not.<br>
-- param bFlippedX true if the widget should be flipped horizaontally, false otherwise.
-- @function [parent=#Widget] setFlippedX 
-- @param self
-- @param #bool flippedX
        
--------------------------------
-- return true represent the widget could accept focus, false represent the widget couldn't accept focus
-- @function [parent=#Widget] isFocusEnabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Query whether the widget ignores user deinfed content size or not<br>
-- return bool
-- @function [parent=#Widget] isIgnoreContentAdaptWithSize 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Return whether the widget is swallowing touch or not<br>
-- since v3.3
-- @function [parent=#Widget] isSwallowTouches 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] getDebugDraw 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Widget] getActionTag 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- Changes the maximum size of the widget<br>
-- A negative value in one of the dimensions<br>
-- means that there is no maximum value restriction<br>
-- param maxSize that is the widget maximum allowed size
-- @function [parent=#Widget] setMaxSize 
-- @param self
-- @param #size_table maxSize
        
--------------------------------
-- Gets world position of widget.<br>
-- return world position of widget.
-- @function [parent=#Widget] getWorldPosition 
-- @param self
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- 
-- @function [parent=#Widget] clone 
-- @param self
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- 
-- @function [parent=#Widget] getBottomBoundary 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Return whether the widget is propagate touch events to its parents or not<br>
-- since v3.3
-- @function [parent=#Widget] isPropagateTouchEvents 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Gets IngoreLayout attribute. This<br>
-- is a sign to the layout manager that this widget<br>
-- should not be taken into account in the layout process
-- @function [parent=#Widget] getIgnoreLayout 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Sets whether the widget is bright<br>
-- The default value is true, a widget is default to bright<br>
-- param visible   true if the widget is bright, false if the widget is dark.
-- @function [parent=#Widget] setBright 
-- @param self
-- @param #bool bright
        
--------------------------------
-- 
-- @function [parent=#Widget] getCallbackName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- Changes the size type of widget.<br>
-- see SizeType<br>
-- param type that is widget's size type
-- @function [parent=#Widget] setSizeType 
-- @param self
-- @param #int type
        
--------------------------------
-- 
-- @function [parent=#Widget] setDebugDraw 
-- @param self
-- @param #bool debugDraw
        
--------------------------------
-- Get widget visibility<br>
-- return the visibility of the widget
-- @function [parent=#Widget] getVisibility 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#Widget] enableDpadNavigation 
-- @param self
-- @param #bool enable
        
--------------------------------
-- Allocates and initializes a widget.
-- @function [parent=#Widget] create 
-- @param self
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- 
-- @function [parent=#Widget] setScaleY 
-- @param self
-- @param #float scaleY
        
--------------------------------
-- 
-- @function [parent=#Widget] setScaleX 
-- @param self
-- @param #float scaleX
        
--------------------------------
-- 
-- @function [parent=#Widget] getScaleY 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#Widget] getScaleX 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Returns the "class name" of widget.
-- @function [parent=#Widget] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @overload self, float, float         
-- @overload self, float         
-- @function [parent=#Widget] setScale
-- @param self
-- @param #float scalex
-- @param #float scaley

--------------------------------
-- Changes the position (x,y) of the widget in OpenGL coordinates<br>
-- Usually we use p(x,y) to compose Vec2 object.<br>
-- The original point (0,0) is at the left-bottom corner of screen.<br>
-- param position  The position (x,y) of the widget in OpenGL coordinates
-- @function [parent=#Widget] setPosition 
-- @param self
-- @param #vec2_table pos
        
--------------------------------
-- 
-- @function [parent=#Widget] setContentSize 
-- @param self
-- @param #size_table contentSize
        
--------------------------------
-- 
-- @function [parent=#Widget] getScale 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Default constructor
-- @function [parent=#Widget] Widget 
-- @param self
        
return nil
