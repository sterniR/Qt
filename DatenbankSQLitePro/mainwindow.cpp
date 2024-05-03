#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("firma.db");
    if(!con.open())
    {
        ui->LstAusgabe->addItem("DB nicht geöffnet");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    connect(ui->CmdEinfuegen, SIGNAL(clicked()), SLOT(CmdEinfuegenClicked()));
    connect(ui->CmdAnzeigenAlle, SIGNAL(clicked()), SLOT(CmdAnzeigenAlleClicked()));
}

void MainWindow::CmdEinfuegenClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.exec("CREATE TABLE personen("
                   "name TEXT, "
                   "vorname TEXT, "
                   "personalnummer INTEGER PRIMARY KEY, "
                   "gehalt REAL, "
                   "geburtstag TEXT)");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES("
                   "'Maier', 'Hans', 6714, 3500, '15.03.1962')");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES("
                   "'Schmitz', 'Almut', 81343, 3750, '12.04.1958')");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES"
                   "('Günter', 'Manfred', 4352, 3200, '19.03.2000')");
    FehlerAnzeige();
}
void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LstAusgabe->addItem("Fehler: " + fehler.databaseText());
}

void MainWindow::CmdAnzeigenAlleClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeige();
    Ausgabe(5);
}

void MainWindow::Ausgabe(int feldAnzahl)
{
    QString ausgabe;
    while(sqlBefehl.next())
    {
        ausgabe = "";
        for(int i=0; i<feldAnzahl; i++)
            ausgabe += sqlBefehl.value(i).toString() + " # ";
        ui->LstAusgabe->addItem(ausgabe);
    }
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}
