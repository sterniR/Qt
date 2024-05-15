#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "json.hpp"
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::pushRequest);
    connect(ui->pushButtonRequest, &QPushButton::clicked, this, &MainWindow::plainText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushRequest() {
    manager->get(QNetworkRequest(QUrl("http://localhost:18080/api/bereiche")));
}

void MainWindow::plainText() {

}
