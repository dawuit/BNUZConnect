#include "connectManager.h"
#include "connect.h"
#include <QTimer>
#include <QVariant>

//初始化相关链接
const QString ConnectManager::srcPath = "http://enet.10000.gd.cn:10001/zh/zh126/index.jsp?wlanacip=61.145.225.11";
const QString ConnectManager::imgPath = "http://enet.10000.gd.cn:10001/common/image.jsp";
const QString ConnectManager::loginPath = "http://enet.10000.gd.cn:10001/login.do";

ConnectManager::ConnectManager()
{

}

void ConnectManager::getCodeImage()
{
    //请求首页获取Cookie
    Connect connect;
    connect.get(srcPath);
    DownloadImgCode download;
    download.get(imgPath, connect.getCookies());

}

