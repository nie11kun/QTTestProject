#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <otherthread.h>
#include <QThread>

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
    OtherThread *ot;
    QThread *t;

signals:
    void startOtherThread();

};


#endif // MAINWINDOW_H
