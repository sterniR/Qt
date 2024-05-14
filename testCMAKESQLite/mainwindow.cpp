#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("firma.db");
    if (!con.open()) {
        ui->ListAusgabe->addItem("DB Nicht gefunden.");
    }

    sqlBefehl = QSqlQuery(con);

    connect(ui->pushButtonAlleAnsehen, SIGNAL(clicked()), SLOT(pushButtonAlleAnsehenClicked()));
    connect(ui->pushButtonEinfuegen, SIGNAL(clicked()), SLOT(pushButtonEinfuegenClicked()));
    connect(ui->pushButtonAendern, SIGNAL(clicked()), SLOT(pushButtonAendernClicked()));
    connect(ui->pushButtonLoeschen, SIGNAL(clicked()), SLOT(pushButtonLoeschenClicked()));
    connect(ui->pushButtonFiltern, SIGNAL(clicked()), SLOT(pushButtonFilternClicked()));
    connect(ui->ListAusgabe, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(ListAusgabeClicked()));
}

void MainWindow::ListAusgabeClicked() {
    ui->lineEditName->clear();
    ui->lineEditNachanme->clear();
    ui->lineEditPersonalnummer->clear();
    ui->lineEditGehalt->clear();
    ui->InputDateEdit->clear();

    QString datensatz = ui->ListAusgabe->currentItem()->text();
    QStringList liste = datensatz.split("|");
    QString feldwertName = liste.at(0).trimmed();
    QString feldwertNachname = liste.at(1).trimmed();
    QString feldwertPersonalnummer = liste.at(2).trimmed();
    QString feldwertGehalt = liste.at(3).trimmed();
    QString feldwertGeburtstag = liste.at(4).trimmed();
    ui->lineEditName->insert(feldwertName);
    ui->lineEditNachanme->insert(feldwertNachname);
    ui->lineEditPersonalnummer->insert(feldwertPersonalnummer);
    ui->lineEditGehalt->insert(feldwertGehalt);
    ui->InputDateEdit->setDate(QDate::fromString(feldwertGeburtstag, "dd.MM.yyyy"));
}

void MainWindow::FehlerAnzeigen() {
    QSqlError fehler = sqlBefehl.lastError();
    QString error = fehler.text();
    error.push_front("Fehler: ");
    if (fehler.isValid()) {
        box.setText(error);
        box.exec();
    }
}

void MainWindow::Ausgabe(int anzahl) {
    QString ausgabe;
    while (sqlBefehl.next()) {
        ausgabe = "";
        for (int i = 0; i < anzahl; i++)
            ausgabe += sqlBefehl.value(i).toString() + " | ";
        ui->ListAusgabe->addItem(ausgabe);
    }
}

void MainWindow::pushButtonAlleAnsehenClicked() {
    ui->ListAusgabe->clear();
    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeigen();
    Ausgabe(5);
}

void MainWindow::pushButtonEinfuegenClicked() {
    ui->ListAusgabe->clear();

    sqlBefehl.exec("CREATE TABLE personen"
                   "(name TEXT,"
                   "nachname TEXT,"
                   "personalnummer INTERGER PRIMARY KEY,"
                   "gehalt REAL,"
                   "geburtstag TEXT)");
    //FehlerAnzeigen();

    /*Platzhalter Datensatz
    sqlBefehl.exec("INSERT INTO personen VALUES"
                   "('Hans', 'Maier', 6714, 3500, '15.03.1962')");
    FehlerAnzeigen();
    sqlBefehl.exec("INSERT INTO personen VALUES"
                   "('Julia', 'Mertens', 2297, 3621.5, '30.12.1959')");
    FehlerAnzeigen();
    sqlBefehl.exec("INSERT INTO personen VALUES"
                   "('Peter', 'Schmitz', 81343, 3750, '12.04.1958')");
    FehlerAnzeigen();*/

    if (ui->lineEditPersonalnummer->text() != "") {
        sqlBefehl.prepare("INSERT INTO personen VALUES ('" + ui->lineEditName->text() + "', '"
                          + ui->lineEditNachanme->text() + "', "
                          + ui->lineEditPersonalnummer->text() + ", " + ui->lineEditGehalt->text()
                          + ", '" + ui->InputDateEdit->text() + "')");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);

        sqlBefehl.exec("SELECT * FROM personen");
        FehlerAnzeigen();
        Ausgabe(5);
    } else {
        box.setText("Personalnummer darf nicht leer sein.");
        box.exec();
    }
}

void MainWindow::pushButtonAendernClicked() {
    // bool selected = ui->ListAusgabe->currentItem() != nullptr;

    if (ui->ListAusgabe->currentItem() == nullptr) {
        box.setText("Zur Veränderung muss die jeweilige Reihe ausgewählt sein.");
        box.exec();
        return;
    }
    QString datensatz = ui->ListAusgabe->currentItem()->text();
    QStringList liste = datensatz.split("|");
    QString feldwertPersonalnummer = liste.at(2).trimmed();
    sqlBefehl.exec("UPDATE personen SET name = '" + ui->lineEditName->text()
                   + "' WHERE personalnummer = '" + feldwertPersonalnummer + "'");
    sqlBefehl.exec("UPDATE personen SET nachname = '" + ui->lineEditNachanme->text()
                   + "' WHERE personalnummer = '" + feldwertPersonalnummer + "'");
    sqlBefehl.exec("UPDATE personen SET personalnummer = '" + ui->lineEditPersonalnummer->text()
                   + "' WHERE personalnummer = '" + feldwertPersonalnummer + "'");
    sqlBefehl.exec("UPDATE personen SET gehalt = '" + ui->lineEditGehalt->text()
                   + "' WHERE personalnummer = '" + feldwertPersonalnummer + "'");
    sqlBefehl.exec("UPDATE personen SET geburtstag = '" + ui->InputDateEdit->text()
                   + "' WHERE personalnummer = '" + feldwertPersonalnummer + "'");

    ui->ListAusgabe->clear();
    ui->lineEditName->clear();
    ui->lineEditNachanme->clear();
    ui->lineEditPersonalnummer->clear();
    ui->lineEditGehalt->clear();
    ui->InputDateEdit->clear();
    FehlerAnzeigen();

    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeigen();
    Ausgabe(5);
}

void MainWindow::pushButtonLoeschenClicked() {
    if (ui->ListAusgabe->currentItem() == nullptr) {
        box.setText("Zur Veränderung muss die jeweilige Reihe ausgewählt sein.");
        box.exec();
        return;
    }
    QString datensatz = ui->ListAusgabe->currentItem()->text();
    QStringList liste = datensatz.split("|");
    QString feldwertPersonalnummer = liste.at(2).trimmed();
    sqlBefehl.exec("DELETE FROM personen WHERE personalnummer = '" + feldwertPersonalnummer + "'");
    FehlerAnzeigen();

    ui->ListAusgabe->clear();
    ui->lineEditName->clear();
    ui->lineEditNachanme->clear();
    ui->lineEditPersonalnummer->clear();
    ui->lineEditGehalt->clear();
    ui->InputDateEdit->clear();

    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeigen();
    Ausgabe(5);
}

void MainWindow::pushButtonFilternClicked() {
    ui->ListAusgabe->clear();
    /*Ein Feld ausgefüllt
    if (ui->lineEditName->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditNachanme->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE nachname LIKE '%"
                          + ui->lineEditNachanme->text() + "%'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditPersonalnummer->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE personalnummer = '"
                          + ui->lineEditPersonalnummer->text() + "'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE gehalt >= '" + ui->lineEditGehalt->text()
                          + "' * 0.9 AND gehalt <= '" + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }

    //Zwei Felder ausgefüllt
    if (ui->lineEditName->text() != "" && ui->lineEditNachanme->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND nachname LIKE '%" + ui->lineEditNachanme->text() + "%'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditName->text() != "" && ui->lineEditPersonalnummer->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND personalnummer = '" + ui->lineEditPersonalnummer->text() + "'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditName->text() != "" && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND gehalt >= '" + ui->lineEditGehalt->text()
                          + "' * 0.9 AND gehalt <= '" + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditPersonalnummer->text() != "" && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE personalnummer = '"
                          + ui->lineEditPersonalnummer->text() + "' AND gehalt >= '"
                          + ui->lineEditGehalt->text() + "' * 0.9 AND gehalt <= '"
                          + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditNachanme->text() != "" && ui->lineEditPersonalnummer->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE nachname LIKE '%"
                          + ui->lineEditNachanme->text() + "%' AND personalnummer = '"
                          + ui->lineEditPersonalnummer->text() + "'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditNachanme->text() != "" && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE nachname = '" + ui->lineEditNachanme->text()
                          + "' AND gehalt >= '" + ui->lineEditGehalt->text()
                          + "' * 0.9 AND gehalt <= '" + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }

    //Drei Felder ausgefüllt
    if (ui->lineEditName->text() != "" && ui->lineEditNachanme->text() != ""
        && ui->lineEditPersonalnummer->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND nachname LIKE '%" + ui->lineEditNachanme->text()
                          + "%' AND personalnummer = '" + ui->lineEditPersonalnummer->text() + "'");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditName->text() != "" && ui->lineEditNachanme->text() != ""
        && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND nachname LIKE '%" + ui->lineEditNachanme->text()
                          + "%' AND gehalt >= '" + ui->lineEditGehalt->text()
                          + "' * 0.9 AND gehalt <= '" + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditName->text() != "" && ui->lineEditPersonalnummer->text() != ""
        && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE '%" + ui->lineEditName->text()
                          + "%' AND personalnummer LIKE '" + ui->lineEditPersonalnummer->text()
                          + "' AND gehalt >= '" + ui->lineEditGehalt->text()
                          + "' * 0.9 AND gehalt <= '" + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }
    if (ui->lineEditNachanme->text() != "" && ui->lineEditPersonalnummer->text() != ""
        && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();

        sqlBefehl.prepare("SELECT * FROM personen WHERE nachname LIKE '%"
                          + ui->lineEditNachanme->text() + "%' AND personalnummer LIKE '"
                          + ui->lineEditPersonalnummer->text() + "' AND gehalt >= '"
                          + ui->lineEditGehalt->text() + "' * 0.9 AND gehalt <= '"
                          + ui->lineEditGehalt->text() + "' * 1.1");
        sqlBefehl.exec();
        FehlerAnzeigen();
        Ausgabe(5);
    }

    //Vier Felder ausgefüllt
    (ui->lineEditName->text() != "" && ui->lineEditNachanme->text() != ""
     && ui->lineEditPersonalnummer->text() != "" && ui->lineEditGehalt->text() != "") {
        ui->ListAusgabe->clear();*/

    sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE :name AND nachname LIKE '"
                      + anyIfEmpty(ui->lineEditNachanme->text(), true)
                      + "'"); /* "' AND personalnummer = '"
                      + anyIfEmpty(ui->lineEditPersonalnummer->text(), false) + "' AND gehalt >= '"
                      + anyIfEmpty(ui->lineEditGehalt->text(), false) + "' * 0.9 AND gehalt <= '"
                      + anyIfEmpty(ui->lineEditGehalt->text(), false) + "' * 1.1");*/
    sqlBefehl.bindValue(":name", anyIfEmpty(ui->lineEditName->text(), true));
    sqlBefehl.bindValue(":name", anyIfEmpty(ui->lineEditName->text(), true));
    sqlBefehl.bindValue(":name", anyIfEmpty(ui->lineEditPersonalnummer->text(), false), true));
    sqlBefehl.bindValue(":name", anyIfEmpty(ui->lineEditName->text(), true));
    sqlBefehl.exec();
    FehlerAnzeigen();
    Ausgabe(5);
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::anyIfEmpty(QString value, bool matchIncomplete) {
    if (value.isEmpty())
        return "%";
    if (matchIncomplete)
        return "%" + value + "%";
    return value;
}
