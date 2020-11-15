#include "systemTray.h"

SystemTray::SystemTray() {
//    QWidgetAction * quitAction = new QWidgetAction(nullptr);
//    quitAction->setMenuRole(QAction::QuitRole);
//    QObject::connect(quitAction, &QAction::triggered, qApp, qApp->exit);

    trayIconMenu = new QMenu(nullptr);

    QAction* preferencesAction = trayIconMenu->addAction("Preferences...");
    preferencesAction->setShortcut(QKeySequence::Preferences);
    QObject::connect(preferencesAction, &QAction::triggered, qApp, qApp->quit);
    trayIconMenu->addAction(preferencesAction);

    trayIconMenu->addSeparator();

    QAction* quitAction = trayIconMenu->addAction(QString("Quit ") + qAppName());
    quitAction->setShortcut(QKeySequence::Quit);
    QObject::connect(quitAction, &QAction::triggered, qApp, qApp->quit);
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(QIcon(":/images/icon.png"), nullptr);
    trayIcon->setContextMenu(trayIconMenu);

    trayIcon->show();
}
