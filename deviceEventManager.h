#ifndef DEVICEEVENTMANAGER_H
#define DEVICEEVENTMANAGER_H

#include <functional>

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#import <IOKit/hid/IOHidManager.h>
#import <IOKit/hid/IOHIDKeys.h>
#endif

class DeviceEventManager {
    public:
        typedef std::function<void()> DeviceEventCallback;

        DeviceEventManager(int vendorId, int productId, int usagePage, int usageId, DeviceEventCallback &deviceAddition, DeviceEventCallback &deviceRemoval);
        ~DeviceEventManager();
    private:
        DeviceEventCallback m_deviceAddition;
        DeviceEventCallback m_deviceRemoval;

    #ifdef __OBJC__
        IOHIDManagerRef managerReference;
    #endif
};

#endif // DEVICEEVENTMANAGER_H
