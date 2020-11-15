#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include <functional>
#include <QtDebug>

#ifdef Q_OS_MACOS
#include "activationPolicySetter.h"
#endif

#include "deviceEventManager.h"
#include "systemTray.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(HIDListener);

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }

    app.setQuitOnLastWindowClosed(false);

    DeviceEventManager::DeviceEventCallback newDevice = [](){qDebug() << "KEYBROAD FOUND";};
    DeviceEventManager::DeviceEventCallback goneDevice = [](){qDebug() << "KEYBROAD LOST :C";};
    DeviceEventManager dem(0xfeed, 0, 0xFF60, 0x61, newDevice, goneDevice);

    #ifdef Q_OS_MACOS
    setActivationPolicy(ActivationPolicy::Accessory);
    #endif

    SystemTray systemTray;
    return app.exec();
}


#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
