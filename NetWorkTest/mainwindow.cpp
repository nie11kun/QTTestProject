#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    doRequest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doRequest() {
    manager = new QNetworkAccessManager(this);

    QSslConfiguration sSlConfig;
    sSlConfig.setDefaultConfiguration(QSslConfiguration::defaultConfiguration());
    sSlConfig.setProtocol(QSsl::TlsV1_2);

    QNetworkRequest request;
    request.setSslConfiguration(sSlConfig);
    request.setUrl(QUrl("https://info.niekun.net"));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    manager->get(request);

    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);
    connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
}

void MainWindow::replyFinished(QNetworkReply * reply) {
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        //qDebug() << reply->readAll();
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        qDebug() << "-----------------------";
        qDebug().noquote() << reply->readAll();

        ui->textBrowser->setText(reply->readAll());
    }
}
