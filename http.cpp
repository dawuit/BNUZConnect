#include "http.h"

 HttpAPI:: HttpAPI()
{
    QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));

}

 HttpAPI::~ HttpAPI()
{
    networkAccessManager.disconnect();
}

void  HttpAPI::get(const QString url)
{
    srcPath = url;
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.get(httpRequest);
}

void HttpAPI::post(const QString url, const QByteArray &data)
{
    srcPath = url;
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.post(httpRequest, data);
}

void HttpAPI::serviceRequestFinished(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(reply->error() == QNetworkReply::NoError)
    {
        requestFinished(reply, reply->readAll(), statusCode);
    } else
    {
        requestFinished(reply, "", statusCode);
    }

    reply->deleteLater();
}
