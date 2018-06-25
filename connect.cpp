#include "connect.h"
#include <QFile>
#include <QList>
#include <QNetworkCookie>
#include <QDataStream>

void Connect::requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode)
{
    cookie = networkAccessManager.cookieJar()->cookiesForUrl(srcPath);
}

QList<QNetworkCookie> Connect::getCookies()
{
    return cookie;
}

void DownloadImgCode::get(const QString url, QList<QNetworkCookie> cookie)
{
    srcPath = url;
    //…Ë÷√cookie
    QVariant var;
    var.setValue(cookie);
    httpRequest.setUrl(QUrl(url));
    httpRequest.setHeader(QNetworkRequest::CookieHeader, var);
    httpRequest.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; LCTE; rv:11.0) like Gecko");
    networkAccessManager.get(httpRequest);

}


void DownloadImgCode::requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode)
{
    QFile file("code.jpg");
    file.open(QIODevice::ReadWrite);
    QDataStream out(&file);
    out << data;
    file.close();
}
