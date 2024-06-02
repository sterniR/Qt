#include "mainwindow.h"
#include <QNetworkReply>
#include "./ui_mainwindow.h"
#include "json.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);
    // connect(ui->pushButtonRequestBereiche, &QPushButton::clicked, this, &MainWindow::pushRequestBereich);
    // connect(ui->pushButtonRequestKurse, &QPushButton::clicked, this, &MainWindow::pushRequestKurse);

    manager->get(QNetworkRequest(QUrl("http://localhost:18080/api/daten")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray inhalt = reply->peek(reply->bytesAvailable());
    auto object = nlohmann::json::from_bson(inhalt.toStdString());

    const auto& bereiche = object["bereiche"];
    const auto& jahrgänge = object["jahrgaenge"];


}

void MainWindow::pushRequestBereich()
{

}

void MainWindow::pushRequestKurse()
{
    manager->get(QNetworkRequest(QUrl("http://localhost:18080/api/daten/kurse")));
}
