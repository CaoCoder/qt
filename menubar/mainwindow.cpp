#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单栏
    QMenuBar* menubar = menuBar();
    //将菜单栏放入窗口中
    this->setMenuBar(menubar);

    //创建菜单
    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("构建");

    //添加菜单到菜单栏
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);


    //创建菜单项
    QAction* act1 = new QAction("open");
    QAction* act2 = new QAction("close");
    QAction* act3 = new QAction("create");

    //将菜单项添加到菜单上
    menu1->addAction(act1);
    menu1->addAction(act2);
    menu1->addAction(act3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

