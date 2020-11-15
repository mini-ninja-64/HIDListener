HEADERS       = \
    activationPolicySetter.h \
    deviceEventManager.h \
    systemTray.h
SOURCES       = main.cpp \
                deviceEventManagerMac.mm \
                systemTray.cpp
RESOURCES     = \
    HIDListener.qrc

macx | macos {
    HEADERS += \
    activationPolicySetter.h\
    deviceEventManager.h
    SOURCES += \
    activationPolicySetter.mm
    deviceEventManagerMac.mm

    LIBS += -framework IOKit
}

QT += widgets
requires(qtConfig(combobox))

# install
target.path = /tmp/bin
INSTALLS += target
