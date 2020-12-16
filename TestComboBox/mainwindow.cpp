#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int index = ui->comboBox->currentIndex();
    QString a = QString::number(index);
    ui->label->setText(a);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString a = QString::number(index);
    ui->label->setText(a);
}
