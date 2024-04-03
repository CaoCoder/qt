#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextEdit>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void save();
    void load();
private:
    Ui::MainWindow *ui;
    QTextEdit* edit;
};
#endif // MAINWINDOW_H
