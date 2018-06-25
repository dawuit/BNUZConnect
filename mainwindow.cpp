#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 禁止最大化按钮
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    //设置全局样式
    setStyle();
    connectManager = new ConnectManager();
}


//设置全局样式
void MainWindow::setStyle()
{
    this->ui->pushButton->setStyleSheet("#pushButton{border-style:none;padding:10px;border-radius:5px;color:#E6F8F5;background:#1ABC9C;}"
                                          "#pushButton:hover{color:#FFFFFF;background:#2EE1C1;}"
                                          "#pushButton:pressed{color:#A7EEE6;background:#16A086;}");
    this->ui->pushButton_2->setStyleSheet("#pushButton_2{border-style:none;padding:10px;border-radius:5px;color:#E6F8F5;background:#1ABC9C;}"
                                          "#pushButton_2:hover{color:#FFFFFF;background:#2EE1C1;}"
                                          "#pushButton_2:pressed{color:#A7EEE6;background:#16A086;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     connectManager->getCodeImage();
}
