
--------------------------------
-- @module DownloaderExtended
-- @extend enable_shared_from_this<cocos2d::extension::DownloaderExtended>
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#DownloaderExtended] downloadAsync 
-- @param self
-- @param #string srcUrl
-- @param #string storagePath
-- @param #string customId
-- @param #int cacheStrategy
-- @return std::weak_ptr<DownloaderExtended::DownloadHandler>#std::weak_ptr<DownloaderExtended::DownloadHandler> ret (return value: std::weak_ptr<cc.DownloaderExtended::DownloadHandler>)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] getSuccessCallback 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] setErrorCallback 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] getContentSize 
-- @param self
-- @param #string srcUrl
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] setProgressCallback 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] downloadToBufferSync 
-- @param self
-- @param #string srcUrl
-- @param #unsigned char buffer
-- @param #long size
-- @param #string customId
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] getErrorCallback 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] batchDownloadSync 
-- @param self
-- @param #map_table units
-- @param #string batchId
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] getProgressCallback 
-- @param self
-- @return function#function ret (return value: function)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] downloadSync 
-- @param self
-- @param #string srcUrl
-- @param #string storagePath
-- @param #string customId
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] setSuccessCallback 
-- @param self
-- @param #function callback
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] getConnectionTimeout 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] batchDownloadAsync 
-- @param self
-- @param #map_table units
-- @param #string batchId
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] setConnectionTimeout 
-- @param self
-- @param #int timeout
        
--------------------------------
-- 
-- @function [parent=#DownloaderExtended] downloadToBufferAsync 
-- @param self
-- @param #string srcUrl
-- @param #unsigned char buffer
-- @param #long size
-- @param #string customId
        
--------------------------------
-- The default constructor.
-- @function [parent=#DownloaderExtended] DownloaderExtended 
-- @param self
        
return nil
