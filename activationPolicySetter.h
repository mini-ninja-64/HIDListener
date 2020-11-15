#ifndef ACTIVATIONPOLICYSETTER_H
#define ACTIVATIONPOLICYSETTER_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

enum class ACTIVATIONPOLICY{
    REGULAR,
    ACCESSORY,
    PROHIBITED,
};

void setActivationPolicy(ACTIVATIONPOLICY policy);
#endif // ACTIVATIONPOLICYSETTER_H
