#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void doDownload();

private:
    Ui::MainWindow *ui;
    void slotReadyRead();
    void slotError();
    QNetworkAccessManager *manager;

private slots:
    void replyFinished(QNetworkReply *reply);
};
#endif // MAINWINDOW_HPP
