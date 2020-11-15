#ifndef ACTIVATIONPOLICYSETTER_H
#define ACTIVATIONPOLICYSETTER_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

enum class ActivationPolicy{
    Regular,
    Accessory,
    Prohibited,
};

void setActivationPolicy(ActivationPolicy policy);
#endif // ACTIVATIONPOLICYSETTER_H
