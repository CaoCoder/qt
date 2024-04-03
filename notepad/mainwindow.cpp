#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <fstream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("我的记事本");

    //创建菜单栏
    QMenuBar* menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    //创建菜单
    QMenu* menu = new QMenu("文件");
    menuBar->addMenu(menu);

    //创建菜单项
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("加载");
    menu->addAction(action1);
    menu->addAction(action2);

    //创建中央控件
    edit = new QTextEdit(this);
    this->setCentralWidget(edit);
    edit->setPlaceholderText("此处编写文本内容");

    //链接信号槽
    connect(action1,&QAction::triggered, this, &MainWindow::save);
    connect(action2,&QAction::triggered, this, &MainWindow::load);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    //弹出对话框，选择写入文件的路径
    QFileDialog* dialog = new QFileDialog(this);
    QString fileName = dialog->getSaveFileName(this, "保存文件", "C:/Users/Admin/Desktop");
    qDebug() << "fileName:" << fileName;

    //写入文件
    std::ofstream file(fileName.toStdString().c_str());
    if(!file.is_open())
    {
        qDebug() << "文件保存失败!";
        return;
    }
    const QString& text = edit->toPlainText();//获取文件内容
    file << text.toStdString();//写入文件
    file.close();
}

void MainWindow::load()
{
    //弹出对话框，选择写入文件的路径
    QFileDialog* dialog = new QFileDialog(this);
    QString fileName = dialog->getOpenFileName(this, "加载文件", "C:/Users/Admin/Desktop");
    qDebug() << "fileName:" << fileName;

    //读取文件
    std::ifstream file(fileName.toStdString().c_str());
    if(!file.is_open())
    {
        qDebug() << "文件加载失败!";
        return;
    }
    std::string content;
    std::string line;
    while(std::getline(file, line))
    {
        content += line;
        content += "\n";
    }
    file.close();

    //显示到界面上
    QString text = QString::fromStdString(content);
    edit->setPlainText(text);
}

