
--------------------------------
-- @module Device
-- @parent_module cc

--------------------------------
-- This method returns the screen size for the current device<br>
-- in inches.<br>
-- It only works on iOS and Android for now<br>
-- return The screen size in inches (e.g 7.0, 10.0, etc)
-- @function [parent=#Device] getScreenSizeInches 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- To enable or disable accelerometer.
-- @function [parent=#Device] setAccelerometerEnabled 
-- @param self
-- @param #bool isEnabled
        
--------------------------------
-- Sets the interval of accelerometer.
-- @function [parent=#Device] setAccelerometerInterval 
-- @param self
-- @param #float interval
        
--------------------------------
-- 
-- @function [parent=#Device] setKeepScreenOn 
-- @param self
-- @param #bool value
        
--------------------------------
-- Gets the DPI of device<br>
-- return The DPI of device.
-- @function [parent=#Device] getDPI 
-- @param self
-- @return int#int ret (return value: int)
        
return nil
