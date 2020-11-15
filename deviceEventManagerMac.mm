#include <deviceEventManager.h>

DeviceEventManager::DeviceEventManager(int vendorId, int productId, int usagePage, int usageId, DeviceEventCallback &deviceAddition, DeviceEventCallback &deviceRemoval) {
    m_deviceAddition = deviceAddition;
    m_deviceRemoval = deviceRemoval;


    managerReference = IOHIDManagerCreate(kCFAllocatorDefault, IOOptionBits(kIOHIDOptionsTypeNone));

    NSDictionary *deviceMatchDictionary = @{
        @kIOHIDVendorIDKey : @(vendorId),
        @kIOHIDProductKey : @(productId),
        @kIOHIDDeviceUsagePageKey : @(usagePage),
        @kIOHIDDeviceUsageKey : @(usageId)
    };

    IOHIDDeviceCallback deviceCallbackRunner = [](void *context, IOReturn result, void *sender, IOHIDDeviceRef device){
        DeviceEventManager::DeviceEventCallback * deviceEventCallback = static_cast<DeviceEventCallback*>(context);
        (*deviceEventCallback)();
    };

    IOHIDManagerSetDeviceMatching(managerReference, (__bridge CFDictionaryRef) deviceMatchDictionary);
    IOHIDManagerRegisterDeviceMatchingCallback(managerReference, deviceCallbackRunner, static_cast<void*>(&m_deviceAddition));
    IOHIDManagerRegisterDeviceRemovalCallback(managerReference, deviceCallbackRunner, static_cast<void*>(&m_deviceRemoval));

    IOHIDManagerScheduleWithRunLoop(managerReference, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
    IOHIDManagerOpen(managerReference, IOOptionBits(kIOHIDOptionsTypeNone));
}

DeviceEventManager::~DeviceEventManager(){
    IOHIDManagerClose(managerReference, IOOptionBits(kIOHIDOptionsTypeNone));
}
