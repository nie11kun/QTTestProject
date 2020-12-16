#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ot = new OtherThread;
    t = new QThread;
    ot->moveToThread(t);
    t->start();

    connect(this, SIGNAL(startOtherThread()), ot, SLOT(function()));

    emit startOtherThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

