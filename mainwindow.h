#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connectManager.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setStyle();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ConnectManager * connectManager;
};

#endif // MAINWINDOW_H
