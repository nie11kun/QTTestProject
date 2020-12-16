#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    doDownload();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doDownload() {
    QNetworkRequest request;
    QSslConfiguration sSlConfig;
    sSlConfig.setDefaultConfiguration(QSslConfiguration::defaultConfiguration());
    sSlConfig.setProtocol(QSsl::TlsV1_2);

    request.setSslConfiguration(sSlConfig);
    request.setUrl(QUrl("https://info.niekun.net"));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    manager = new QNetworkAccessManager(this);

    manager->get(request);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
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

        //qDebug() << reply->readAll();

        ui->textBrowser->setText(reply->readAll());
        QFile file("./downloaded.txt");
        if(file.open(QIODevice::WriteOnly))
        {
            file.resize(0);
            file.write(reply->readAll());
            file.close();
        } else {
            qDebug() << "open failed";
        }
    }

    reply->deleteLater();
}
