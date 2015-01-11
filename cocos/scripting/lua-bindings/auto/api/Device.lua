
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
-- Locks the device to a given orientation.<br>
-- The orientation can be landscape, portrait or unknown.<br>
-- Setting the orientation to uknown has the same effect of calling<br>
-- unlockDeviceOrientation<br>
-- This will only have effect on iOS and Android.<br>
-- If you wish to unlock the device orientation, so that it changes<br>
-- when the user rotates the device call unlockDeviceOrientation<br>
-- see unlockDeviceOrientation
-- @function [parent=#Device] lockDeviceOrientation 
-- @param self
-- @param #int desiredOrientation
        
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
        
--------------------------------
-- Returns the logical density of the display. This is a scaling factor <br>
-- for the Density Independent Pixel unit, where one DIP is one pixel on<br>
-- an approximately 160 dpi screen(for example a 240x320, 1.5"x2" screen),<br>
-- providing the baseline of the system's display. Thus on a 160dpi screen<br>
-- this density value will be 1; on a 120 dpi screen it would be .75; etc.<br>
-- return float DIP scaling factor
-- @function [parent=#Device] getDIPScalingFactor 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- Returns the current locked orientation.<br>
-- This doesn't return the current device's orientation.<br>
-- It simply returns the last orientation that was locked<br>
-- by calling lockDeviceOrientation or unlockDeviceOrientation.<br>
-- Since the default value for the orientation is unspecified,<br>
-- this is the value that will be returned if there were no previous<br>
-- calls to lockDeviceOrientation or unlockDeviceOrientation<br>
-- see lockDeviceOrientation, unlockDeviceOrientation
-- @function [parent=#Device] getDeviceLockedOrientation 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- Unlocks the device orientation. This means that the device will<br>
-- be free to change orientation as it sees fit.<br>
-- This will only have effect on iOS and Android.
-- @function [parent=#Device] unlockDeviceOrientation 
-- @param self
        
return nil
