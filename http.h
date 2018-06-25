#ifndef HTTP_H
#define HTTP_H
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

class HttpAPI : public QObject
{
    Q_OBJECT

public:
    HttpAPI();
    ~HttpAPI();
    void get(const QString url);
    void post(const QString url, const QByteArray &data);

protected:
    QString srcPath;
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;
    virtual void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) = 0;

public slots:
    void serviceRequestFinished(QNetworkReply *reply);
};

#endif // HTTP_H
