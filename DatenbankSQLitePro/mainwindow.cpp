#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    con = QSqlDatabase::addDatabase("SQLITE");
    con.setDatabaseName("firma.db");
    if(!con.open())
    {
        ui->LstAusgabe->addItem("DB nicht geöffnet");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    connect(ui->CmdEinfuegen, SIGNAL(clicked()), SLOT(CmdEinfuegenClicked()));
}

void MainWindow::CmdEinfuegenClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.exec("CREATE TABLE personen("
                   "name TEXT,"
                   "vorname TEXT"
                   "personalnummer INTEGER PRIMARY KEY,"
                   "gehalt REAL,"
                   "geburtstag TEXT) ");
    FehlerAnzeige();
}
void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LstAusgabe->addItem("Fehler: " + fehler.databaseText());
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}
