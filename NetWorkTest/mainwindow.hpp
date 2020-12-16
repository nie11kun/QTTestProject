#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void doRequest();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

private slots:
    void replyFinished(QNetworkReply *reply);
};
#endif // MAINWINDOW_HPP
