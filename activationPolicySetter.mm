#include <activationPolicySetter.h>

void setActivationPolicy(ActivationPolicy policy){
    switch(policy){
        case ActivationPolicy::Regular:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyRegular];
            break;
        case ActivationPolicy::Accessory:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyAccessory];
            break;
        case ActivationPolicy::Prohibited:
            [NSApp setActivationPolicy: NSApplicationActivationPolicyProhibited];
            break;
    }
}
