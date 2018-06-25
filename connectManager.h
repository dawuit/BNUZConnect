#ifndef CONNECTMANAGER_H
#define CONNECTMANAGER_H
#include <QObject>


class ConnectManager : QObject
{
     Q_OBJECT
private:
    static const QString srcPath;
    static const QString imgPath;
    static const QString loginPath;

public:
    ConnectManager();
    void getCodeImage();

};

#endif // CONNECTMANAGER_H
