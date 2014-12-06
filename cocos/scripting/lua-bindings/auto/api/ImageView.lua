
--------------------------------
-- @module ImageView
-- @extend Widget
-- @parent_module ccui

--------------------------------
-- Returns the current image file name. You can change the current image<br>
-- by calling loadTexture.<br>
-- If no image has been assigned it this will return an empty string<br>
-- see loadTexture<br>
-- return current image file name
-- @function [parent=#ImageView] getImageFileName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- Load texture for imageview.<br>
-- param fileName   file name of texture.<br>
-- param texType    @see TextureResType
-- @function [parent=#ImageView] loadTexture 
-- @param self
-- @param #string fileName
-- @param #int texType
        
--------------------------------
-- Changes image view content mode.<br>
-- Content mode will be used to determine how<br>
-- should the underlying image renderer be scaled<br>
-- according to the ImageView size.<br>
-- Note: This will be ignored if _ignoreSize or _9scale are enabled     <br>
-- param contentMode content mode variable
-- @function [parent=#ImageView] setContentMode 
-- @param self
-- @param #int contentMode
        
--------------------------------
-- Sets if imageview is using scale9 renderer.<br>
-- param able true that using scale9 renderer, false otherwise.
-- @function [parent=#ImageView] setScale9Enabled 
-- @param self
-- @param #bool able
        
--------------------------------
-- Updates the texture rect of the ImageView in points.<br>
-- It will call setTextureRect:rotated:untrimmedSize with rotated = NO, and utrimmedSize = rect.size.
-- @function [parent=#ImageView] setTextureRect 
-- @param self
-- @param #rect_table rect
        
--------------------------------
-- Sets capinsets for imageview, if imageview is using scale9 renderer.<br>
-- param capInsets    capinsets for imageview
-- @function [parent=#ImageView] setCapInsets 
-- @param self
-- @param #rect_table capInsets
        
--------------------------------
-- 
-- @function [parent=#ImageView] getCapInsets 
-- @param self
-- @return rect_table#rect_table ret (return value: rect_table)
        
--------------------------------
-- 
-- @function [parent=#ImageView] isScale9Enabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Returns the image view content mode.<br>
-- The default value is ScaleToFit
-- @function [parent=#ImageView] getContentMode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, string, int         
-- @overload self         
-- @function [parent=#ImageView] create
-- @param self
-- @param #string imageFileName
-- @param #int texType
-- @return ImageView#ImageView ret (return value: ccui.ImageView)

--------------------------------
-- 
-- @function [parent=#ImageView] createInstance 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#ImageView] getVirtualRenderer 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- Returns the "class name" of widget.
-- @function [parent=#ImageView] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ImageView] getVirtualRendererSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- 
-- @function [parent=#ImageView] ignoreContentAdaptWithSize 
-- @param self
-- @param #bool ignore
        
--------------------------------
-- Default constructor
-- @function [parent=#ImageView] ImageView 
-- @param self
        
return nil
