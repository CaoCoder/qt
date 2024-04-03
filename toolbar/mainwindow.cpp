#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QToolBar>
#include <QLabel>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置状态栏
    QStatusBar* stbar = statusBar();
    //讲状态栏设置到窗口中
    setStatusBar(stbar);

    //状态栏显示实时消息
//    stbar->showMessage("hello", 2000);

    //状态栏显示永久消息
    QLabel* label = new QLabel("提示消息", this);
    stbar->addWidget(label);

    //右侧提示信息
    QLabel* label2 = new QLabel("右侧提示消息", this);
    stbar->addPermanentWidget(label2);


    //浮动窗口
    QDockWidget* dockwidget = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockwidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

