#include "mainwindow.h"
#include "json.hpp"
#include "./ui_mainwindow.h"
#include <QNetworkReply>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);
    connect(ui->pushSendRequest, &QPushButton::clicked, this, &MainWindow::pushRequest);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray data = reply->peek(reply->bytesAvailable());
    auto array = nlohmann::json::parse(data.data());
    QString results;
    for(const auto & object : array) {
        if(object["type"] != "video")
            continue;
        results.append(QString::fromStdString(object["title"]));
        results.append("\n");
    }
    ui->plainTextEdit->setPlainText(results);
}

void MainWindow::pushRequest()
{
    manager->get(QNetworkRequest(QUrl("https://yt.artemislena.eu/api/v1/search?q=Qt creator")));
}
