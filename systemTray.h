#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#ifndef QT_NO_SYSTEMTRAYICON

#include <QCoreApplication>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QObject>
#include <QWidgetAction>
#include <QDebug>

#include <QMenu>

QT_BEGIN_NAMESPACE
class QMenu;
class QCoreApplication;
class QAction;
class QObject;
class QWidgetAction;
QT_END_NAMESPACE

class SystemTray {
    public:
        SystemTray();
    private:
        QSystemTrayIcon *trayIcon;
        QMenu *trayIconMenu;
};

#endif // QT_NO_SYSTEMTRAYICON
#endif // SYSTEMTRAY_H
