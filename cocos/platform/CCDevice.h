/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
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

#ifndef __CCDEVICE_H__
#define __CCDEVICE_H__

#include "platform/CCPlatformMacros.h"
#include "base/ccMacros.h"
#include "base/CCData.h"

NS_CC_BEGIN

struct FontDefinition;

class CC_DLL Device
{
public:
    enum class TextAlign
    {
        CENTER        = 0x33, ///< Horizontal center and vertical center.
        TOP           = 0x13, ///< Horizontal center and vertical top.
        TOP_RIGHT     = 0x12, ///< Horizontal right and vertical top.
        RIGHT         = 0x32, ///< Horizontal right and vertical center.
        BOTTOM_RIGHT = 0x22, ///< Horizontal right and vertical bottom.
        BOTTOM        = 0x23, ///< Horizontal center and vertical bottom.
        BOTTOM_LEFT  = 0x21, ///< Horizontal left and vertical bottom.
        LEFT          = 0x31, ///< Horizontal left and vertical center.
        TOP_LEFT      = 0x11, ///< Horizontal left and vertical top.
    };
    
    enum class Orientation
    {
        UNSPECIFIED = 0, //No orientation is specified, the device is allowed to choose the orientation it wants
        PORTRAIT = 1,   //The device is forced to be in the portrait orientation and can not leave that state
        LANDSCAPE = 2   //The device is forced to be in the portrait orientation and can not leave that state
    };
    
    /**
     *  Gets the DPI of device
     *  @return The DPI of device.
     */
    static int getDPI();
    
    /**
     * To enable or disable accelerometer.
     */
    static void setAccelerometerEnabled(bool isEnabled);
    /**
     *  Sets the interval of accelerometer.
     */
    static void setAccelerometerInterval(float interval);

    static Data getTextureDataForText(const char * text, const FontDefinition& textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha);
    
    static void setKeepScreenOn(bool value);
    
    /**
        This method returns the screen size for the current device
        in inches.
        It only works on iOS and Android for now
        @return The screen size in inches (e.g 7.0, 10.0, etc)
     **/
    static float getScreenSizeInches() ;
    
    /**
        Locks the device to a given orientation.
        The orientation can be landscape, portrait or unknown.
        Setting the orientation to uknown has the same effect of calling
        unlockDeviceOrientation
        This will only have effect on iOS and Android.
     
        If you wish to unlock the device orientation, so that it changes
        when the user rotates the device call unlockDeviceOrientation
        @see unlockDeviceOrientation
     **/
    static void lockDeviceOrientation(Orientation desiredOrientation);
    
    /**
        Unlocks the device orientation. This means that the device will
        be free to change orientation as it sees fit.
        This will only have effect on iOS and Android.
     **/
    static void unlockDeviceOrientation();
    
    /**
        Returns the current locked orientation.
        This doesn't return the current device's orientation.
        It simply returns the last orientation that was locked
        by calling lockDeviceOrientation or unlockDeviceOrientation.
     
        Since the default value for the orientation is unspecified,
        this is the value that will be returned if there were no previous
        calls to lockDeviceOrientation or unlockDeviceOrientation
     
        @see lockDeviceOrientation, unlockDeviceOrientation
     **/
    static Orientation getDeviceLockedOrientation();
    
    /**
     *  Returns the logical density of the display. This is a scaling factor 
        for the Density Independent Pixel unit, where one DIP is one pixel on
        an approximately 160 dpi screen(for example a 240x320, 1.5"x2" screen),
        providing the baseline of the system's display. Thus on a 160dpi screen
        this density value will be 1; on a 120 dpi screen it would be .75; etc.
     *
     *  @return float DIP scaling factor
     */
    static float getDIPScalingFactor() { return (Device::getDPI() / 160.0f);}

private:
    CC_DISALLOW_IMPLICIT_CONSTRUCTORS(Device);
};


NS_CC_END

#endif /* __CCDEVICE_H__ */
