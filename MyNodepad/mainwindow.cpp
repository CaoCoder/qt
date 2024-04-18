#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置窗口属性
    this->setMinimumSize(680, 480);
    this->setWindowIcon(QIcon(":/icon/icon.png"));
    this->setWindowTitle("记事本");

    Init();//c初始化主窗口

    this->New_Edit();//启动后先调用

    //连接文件菜单的几个aciton
    connect(this->file_new, &QAction::triggered, this, &MainWindow::New_Edit);
    connect(file_open, &QAction::triggered, this, &MainWindow::File_Open);
    connect(TW, &QTabWidget::tabCloseRequested, this, &MainWindow::Del_Tab);
    connect(TW, &QTabWidget::tabBarClicked, this, &MainWindow::Click);//定位点击位置
    connect(file_save, &QAction::triggered, this, &MainWindow::File_Save);
    connect(file_saveas, &QAction::triggered, this, &MainWindow::File_Save);
    connect(file_print, &QAction::triggered, this, &MainWindow::Unreal_Fun);
    connect(file_pset, &QAction::triggered, this, &MainWindow::Unreal_Fun);
    connect(file_exit, &QAction::triggered, this, &MainWindow::close);//关闭，close是自带的槽函数
    //编辑连接
        //全选
    connect(this->edit_all, &QAction::triggered, this->Lst.at(this->TW->currentIndex()), [this]() {
        this->Lst.at(this->TW->currentIndex())->selectAll();
    });
        //undo撤销
    connect(edit_undo, &QAction::triggered, this->Lst.at(this->TW->currentIndex()),[this](){
        this->Lst.at(this->TW->currentIndex())->undo();
    });
        //剪切
    connect(edit_cut, &QAction::triggered, this->Lst.at(this->TW->currentIndex()),[this](){
        this->Lst.at(this->TW->currentIndex())->cut();
    });
        //复制
    connect(edit_copy, &QAction::triggered, this->Lst.at(this->TW->currentIndex()),[this](){
        this->Lst.at(this->TW->currentIndex())->copy();
    });
    //监听文字是否被选中
    connect(Lst.at(this->TW->currentIndex()), &QTextEdit::selectionChanged,[=](){
        //如果选中信号发送，将action重新设置为可点击
        edit_copy->setEnabled(!Lst.at(this->TW->currentIndex())->textCursor().selectedText().isEmpty());
        edit_cut->setEnabled(!Lst.at(this->TW->currentIndex())->textCursor().selectedText().isEmpty());
        edit_del->setEnabled(!Lst.at(this->TW->currentIndex())->textCursor().selectedText().isEmpty());
    });

        //粘贴
    connect(edit_past, &QAction::triggered, this->Lst.at(this->TW->currentIndex()),[this](){
        this->Lst.at(this->TW->currentIndex())->paste();
    });
        //删除
    connect(edit_del, &QAction::triggered, this->Lst.at(this->TW->currentIndex()),[this](){
        //textcursor返回光标位置和选中范围，然后用removSelectedText删除
        this->Lst.at(this->TW->currentIndex())->textCursor().removeSelectedText();
    });


    //格式
    connect(form_color,&QAction::triggered, this, &MainWindow::Set_Color);
    connect(form_font, &QAction::triggered, this, &MainWindow::Set_Font);
    //查看
    connect(zoomin, &QAction::triggered, this, &MainWindow::Zoom);//放大
    connect(zoomout, &QAction::triggered,[=](){
        QFont font = Lst.at(TW->currentIndex())->font();
        int fontSize = font.pointSize();
        if (fontSize > 10) {
            font.setPointSize(fontSize - 2);
            Lst.at(TW->currentIndex())->setFont(font);
        }
    });//缩小
    //帮助
    connect(help_csdn, &QAction::triggered, this, &MainWindow::GoCsdn);
    connect(help_about,&QAction::triggered, this, &MainWindow::About);

    //刷新时间
    connect(this->timer, &QTimer::timeout, this, &MainWindow::Flush_time);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    //添加menu
    file = menuBar()->addMenu("文件(&F)");
    edit = menuBar()->addMenu("编辑(&E)");
    format = menuBar()->addMenu("格式(&O)");
    view = menuBar()->addMenu("查看(&V)");
    help = menuBar()->addMenu("帮助(&H)");
    //添加action
    file_new = new QAction(QIcon(":/icon/icon.png"),"新建(&N)         Ctrl+N");//创建action
    file->addAction(file_new);//添加到file菜单
    file_open = new QAction(QIcon(":/icon/icon.png"),"打开(&O)         Ctrl+O");
    file->addAction(file_open);
    file_save = new QAction(QIcon(":/icon/icon.png"),"保存(&S)         Ctrl+S");
    this->file_save->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));//设置快捷键
    file->addAction(file_save);
    file_saveas = new QAction(QIcon(":/icon/icon.png"),"另列为(&A)         Ctrl+A");
    file->addAction(file_saveas);
    file_pset = new QAction(QIcon(":/icon/icon.png"),"页面设置(&U)");
    file->addAction(file_pset);
    file_print = new QAction(QIcon(":/icon/icon.png"),"打印(&P)         Ctrl+P");
    file->addAction(file_print);
     file->addSeparator();//添加分割线
    file_exit = new QAction(QIcon(":/icon/icon.png"),"退出(&X)");
    file->addAction(file_exit);

    //添加编辑的action
    edit_undo = new QAction(QIcon(":/icon/icon.png"), "撤销(&U)         Ctrl+Z");
    edit->addAction(edit_undo);
     edit->addSeparator();//分割线
    edit_cut = new QAction(QIcon(":/icon/icon.png"), "剪切(&Y)         Ctrl+X");
        edit_cut->setEnabled(false);//默认设置为不可剪切
    edit->addAction(edit_cut);

    edit_copy = new QAction(QIcon(":/icon/icon.png"), "复制(&C)         Ctrl+C");
    edit_copy->setEnabled(false);//默认设置为不可复制
    edit->addAction(edit_copy);

    edit_past = new QAction(QIcon(":/icon/icon.png"), "粘贴(&P)         Ctrl+V");
    edit->addAction(edit_past);
    edit_del = new QAction(QIcon(":/icon/icon.png"), "删除(&L)         Del");
     edit_del->setEnabled(false);//默认设置为不可删除
    edit->addAction(edit_del);

    edit->addSeparator();//分割线
    edit_bing = new QAction(QIcon(":/icon/icon.png"), "bing搜索(&E)       Ctrl+E");
    edit->addAction(edit_bing);
    edit_find = new QAction(QIcon(":/icon/icon.png"), "查找(&F)         Ctrl+F");
    edit->addAction(edit_find);
    edit_find_n = new QAction(QIcon(":/icon/icon.png"), "查找下一个(&N)         F3");
    edit->addAction(edit_find_n);
    edit_replace = new QAction(QIcon(":/icon/icon.png"), "替换(&R)         Ctrl+H");
    edit->addAction(edit_replace);
    edit_goto = new QAction(QIcon(":/icon/icon.png"), "转到(&G)         Ctrl+G");
    edit->addAction(edit_goto);
    edit->addSeparator();//分割线
    edit_all = new QAction(QIcon(":/icon/icon.png"), "全选(&A)         Ctrl+A");
    edit->addAction(edit_all);
    edit_date = new QAction(QIcon(":/icon/icon.png"), "时间/日期(&D)         F5");
    edit->addAction(edit_date);

    //添加格式的action
    form_autoline = new QAction(QIcon(":/icon/icon.png"), "自动换行(&W)");
    format->addAction(form_autoline);
    form_font = new QAction(QIcon(":/icon/icon.png"), "字体(&F)");
    format->addAction(form_font);
    form_color = new QAction(QIcon(":/icon/icon.png"), "颜色");
    format->addAction(form_color);
    //添加查看的action
    menuChild = new QMenu("缩放(&Z)");//添加子菜单
    zoomin = new QAction(QIcon(":/icon/icon.png"), "放大  Ctrl");
    zoomin->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Plus));
    zoomout = new QAction(QIcon(":/icon/icon.png"), "缩小");
    view->addMenu(menuChild);
    menuChild->addAction(zoomin);
    menuChild->addAction(zoomout);

    view_status = new QAction(QIcon(":/icon/icon.png"), "状态栏(S)");
    view->addAction(view_status);

    //添加帮助的action
    help_csdn = new QAction(QIcon(":/icon/icon.png"), "CSDN查看帮助");
    help->addAction(help_csdn);
     help->addSeparator();//添加分割线
    help_about = new QAction(QIcon(":/icon/icon.png"), "关于记事本");
    help->addAction(help_about);


    //建立toolBar
    tbar = addToolBar("文件");

    tbar->addAction(file_open);
    tbar->addAction(file_save);
    tbar->addSeparator();//添加分割线
    tbar->addAction(edit_undo);
    tbar->addAction(edit_cut);
    tbar->addAction(edit_copy);
    tbar->addAction(edit_past);
    tbar->addAction(edit_del);
    tbar->addAction(edit_find);
    tbar->addAction(edit_all);
    tbar->addSeparator();
    tbar->addAction(form_font);
    tbar->addAction(form_color);



    //tabwidget 标签页
    this->TW = new QTabWidget(this);
    this->setCentralWidget(TW);//设置标签页居中？

    //状态栏statusbar
    this->stbar = statusBar();

    this->lb_fileinfo = new QLabel("我是文件信息");
    stbar->addWidget(lb_fileinfo);


    //设置时间为右对齐
     lb_time = new QLabel("我是时间");

     // 向状态栏添加时间标签作为永久小部件，才能实现右对齐。
     stbar->addPermanentWidget(lb_time);


    //初始化textedit的变量
    this->ID = 0;
   this->filename = "无标题";


    //刷新状态栏时间
     this->Flush_time();
    this->timer = new QTimer(this);

    /*启动定时器，并设置定时器的时间间隔为 1000 毫秒（即 1 秒）。
     * 这意味着每隔 1 秒，
     * 定时器将触发一个信号（timeout 信号），
     * 可以连接该信号到相应的槽函数，
     * 实现定时执行特定的操作。
*/
    timer->start(1000);//时间启动器






}

void MainWindow::Flush_time()
{
    this->myTime = QDateTime::currentDateTime();//获取当前时间
    //设置显示格式
    QString str = this->myTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    this->lb_time->setText(" 当前时间:" + str);
}

void MainWindow::New_Edit()
{
    QFont defaultFont("微软雅黑", 12);
    QTextEdit* te = new QTextEdit();//这里加不加this需要考虑
    te->setFont(defaultFont);
    this->Lst.append(te);//添加到list中

    this->TW->addTab(Lst.at(ID), filename);//将第id个textedit添加到标签页中
    this->lb_fileinfo->setText(filename);
    this->ID++;
    this->filename = "新建文本文档";
    TW->setTabsClosable(1);//设置标签页为可关闭状态

}

void MainWindow::File_Open()
{
    qDebug() << "打开文件";
    QString Fname;
    // 获取打开文件的路径和名称
    Fname = QFileDialog::getOpenFileName(this, "打开文件", "./", "文本文件 (*.txt);;所有文件 (*.*)");
    if(Fname.isEmpty())
    {
        QMessageBox::information(this, "警告", "文件打开失败");
        return;
    }
    qDebug() << "打开文件成功";

    //读取文件
    QFile file(Fname);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "错误", "读取文件失败");
    }

    QFileInfo fileinfo(Fname);
  this->filename = fileinfo.fileName();
    this->New_Edit();
    this->TW->setCurrentIndex(ID-1);//切换到当前打开的标签页

    //建立edit装内容
    QTextStream in(&file);
    in.setCodec("UTF-8");  // 设置文件的编码方式为UTF-8，以便读取文字不会乱码
    while(!in.atEnd())
    {
        QString line = in.readLine();//读取一行


        this->Lst.at(ID-1)->append(line);
    }
    file.close();
    qDebug() << "读取文件成功";


}

/*槽函数会被调用并且会自动接收到要关闭的标签页的索引作为参数。*/
void MainWindow::Del_Tab(int index)
{
    TW->removeTab(index);
}

void MainWindow::Click(int index)
{
    this->TW->setCurrentIndex(index);
    lb_fileinfo->setText("文件名:" + TW->tabText(index));
}

void MainWindow::File_Save()
{

    //进行写操作
    //Lst.at(index) 返回列表 Lst 中位于索引 index 处的元素
    //获取tab名字
    QString defaultFileName = this->TW->tabText(this->TW->currentIndex());

    QString sFname = QFileDialog::getSaveFileName(this, "保存文件", defaultFileName,"文本文件 (*.txt);;所有文件 (*.*)");
    if(sFname.isEmpty())
    {
        QMessageBox::information(this, "错误提示", "文件保存失败");
        return;
    }


    QFile file(sFname);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
     {
         QMessageBox::information(this, "错误提示", "无法打开文件进行保存");
         return;
     }
    //进行写操作
    QString txt = this->Lst.at(this->TW->currentIndex())->toPlainText();
    file.write(txt.toUtf8());

    QString newFileName = QFileInfo(sFname).fileName();
    this->TW->setTabText(this->TW->currentIndex(), newFileName);
    file.close();


    QMessageBox::information(this, "成功提示", "文件保存成功");

}

void MainWindow::Set_Color()
{
    QColor mycolor = QColorDialog::getColor();
    this->Lst.at(TW->currentIndex())->setTextColor(mycolor);
    //判断颜色是有效的不是
    if(!mycolor.isValid())
    {
//        QMessageBox::information(this, "提示", "颜色获取失败");
        return;
    }

}

void MainWindow::Set_Font()
{
    bool ok;
    QFont myfont = QFontDialog::getFont(&ok);
    if(ok)
    {
        this->Lst.at(TW->currentIndex())->setFont(myfont);
    }
    else
    {
//        QMessageBox::information(this, "提示", "字体设置失败");
        return;
    }
}

void MainWindow::Zoom()
{
    this->Lst.at(TW->currentIndex())->setFont(QFont("微软雅黑", 20));
}

void MainWindow::GoCsdn()
{
    QDesktopServices::openUrl(QUrl("https://caoshuaiqi.blog.csdn.net/"));
    return;
}

void MainWindow::About()
{
     QMessageBox::about(this, "关于记事本",
                        "软件名：window记事本\n"
                        "版本号:1.0版本\n"
                        "技术支持：Qt、CSDN个人博客\n"
                        "版权所有:Microsoft Windows\n"
                        "再次创作者：乔巴");
}

void MainWindow::Unreal_Fun()
{
    QMessageBox::information(this, "温馨提示", "无效设置模式...");
    return;
}




