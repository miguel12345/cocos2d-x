
--------------------------------
-- @module ImageViewExtended
-- @extend Widget
-- @parent_module mf

--------------------------------
-- 
-- @function [parent=#ImageViewExtended] updateRemoteImageUrl 
-- @param self
-- @param #string imageUrl
        
--------------------------------
-- Load texture for ImageViewExtended.<br>
-- param fileName   file name of texture.<br>
-- param texType    @see TextureResType
-- @function [parent=#ImageViewExtended] loadTexture 
-- @param self
-- @param #string fileName
-- @param #int texType
        
--------------------------------
-- Sets if ImageViewExtended is using scale9 renderer.<br>
-- param able true that using scale9 renderer, false otherwise.
-- @function [parent=#ImageViewExtended] setScale9Enabled 
-- @param self
-- @param #bool able
        
--------------------------------
-- Updates the texture rect of the ImageViewExtended in points.<br>
-- It will call setTextureRect:rotated:untrimmedSize with rotated = NO, and utrimmedSize = rect.size.
-- @function [parent=#ImageViewExtended] setTextureRect 
-- @param self
-- @param #rect_table rect
        
--------------------------------
-- Sets capinsets for ImageViewExtended, if ImageViewExtended is using scale9 renderer.<br>
-- param capInsets    capinsets for ImageViewExtended
-- @function [parent=#ImageViewExtended] setCapInsets 
-- @param self
-- @param #rect_table capInsets
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] getCapInsets 
-- @param self
-- @return rect_table#rect_table ret (return value: rect_table)
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] setKeepAspectRatio 
-- @param self
-- @param #bool keepAspectRatio
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] isScale9Enabled 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, string, int         
-- @overload self         
-- @overload self, string, string, int         
-- @function [parent=#ImageViewExtended] create
-- @param self
-- @param #string imageUrl
-- @param #string placeholderFileName
-- @param #int placeholderTexType
-- @return mf::ImageViewExtended#mf::ImageViewExtended ret (return value: cc.mf::ImageViewExtended)

--------------------------------
-- 
-- @function [parent=#ImageViewExtended] createInstance 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] getVirtualRenderer 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] onEnter 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] onExit 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] ignoreContentAdaptWithSize 
-- @param self
-- @param #bool ignore
        
--------------------------------
-- Returns the "class name" of widget.
-- @function [parent=#ImageViewExtended] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ImageViewExtended] getVirtualRendererSize 
-- @param self
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- Default constructor
-- @function [parent=#ImageViewExtended] ImageViewExtended 
-- @param self
        
return nil
