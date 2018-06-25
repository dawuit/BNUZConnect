#ifndef CONNECT_H
#define CONNECT_H
#include "http.h"
#include <QtNetwork/QNetworkCookie>
#include <QList>

/**
 * @brief The Connect class
 */

class Connect : public HttpAPI
{
protected:
    QList<QNetworkCookie> cookie;
    virtual void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode);
public:
    QList<QNetworkCookie> getCookies();
};

/**
 * @brief The DownloadCode class
 */

class DownloadImgCode : public HttpAPI
{
protected:
    virtual void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode);
public:
    void get(const QString url, QList<QNetworkCookie> cookie);
}

#endif // CONNECT_H
