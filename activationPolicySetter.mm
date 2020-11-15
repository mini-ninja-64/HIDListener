#include <activationPolicySetter.h>

void setActivationPolicy(ACTIVATIONPOLICY policy){
    switch(policy){
        case ACTIVATIONPOLICY::REGULAR:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyRegular];
            break;
        case ACTIVATIONPOLICY::ACCESSORY:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyAccessory];
            break;
        case ACTIVATIONPOLICY::PROHIBITED:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyProhibited];
            break;
    }
}
