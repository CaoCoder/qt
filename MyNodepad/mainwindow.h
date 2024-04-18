#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QList>
#include <QTextEdit>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QUrl>
#include <string>
#include <QActionGroup>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//自己加的函数
public:
    void Init();

private:
    //自己加的菜单变量
    QMenu* file;
    QMenu* edit;
    QMenu* format;
    QMenu* view;
    QMenu* help;
    //给每个menu添加action
    QAction* file_new;
    QAction* file_open;
    QAction* file_save;
    QAction* file_saveas;//另列为
    QAction* file_pset;//页面设置
    QAction* file_print;//打印
    QAction* file_exit;//退出
    //编辑的acition
    QAction* edit_undo;
    QAction* edit_cut;
    QAction* edit_copy;
    QAction* edit_past;
    QAction* edit_del;
    QAction* edit_bing;
    QAction* edit_find;
    QAction* edit_find_n;
    QAction* edit_replace;
    QAction* edit_goto;
    QAction* edit_all;
    QAction* edit_date;
    //格式
    QAction *form_autoline;
    QAction *form_font;
    QAction *form_color;

    //查看
    QMenu* menuChild;
    QAction *zoomin;//放大
    QAction *zoomout;//缩小
    QAction *view_status;
    //帮助
    QAction *help_csdn;
    QAction *help_about;

    //建立toolBar
    QToolBar* tbar;



    //statusbar
    QStatusBar* stbar;//状态栏
    QLabel* lb_fileinfo;
    QLabel* lb_time;


    QTabWidget* TW;

    //定义QList容器
    QList<QTextEdit*> Lst;  //list里面都是textedit

    //textedit的id和name
    int ID;
    QString filename;//

    //状态栏显示时间
    QDateTime myTime;//时间
    QTimer* timer;


private slots:
    void Flush_time();//刷新时间
    void New_Edit();//新建文件
    void File_Open();//打开文件
    void Del_Tab(int index);//删除Tab
    void Click(int index);
    void File_Save();
    void Unreal_Fun();

    void Set_Color();
    void Set_Font();

    void Zoom();


    void GoCsdn();
    void About();








};
#endif // MAINWINDOW_H
