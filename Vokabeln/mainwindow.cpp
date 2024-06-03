#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand((unsigned)time(nullptr));

    // Datenbankverbindung erstellen
    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("vokabeln.db");
    if(!con.open())
    {
        ui->LstLabel->setText("Fehler: Keine Datenbank geöffnet.");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    //Datenbank erzeugen und füllen
    sqlBefehl.exec("CREATE TABLE vokabeln"
                   "(id INTEGER PRIMARY KEY, deu TEXT, eng TEXT, fra TEXT)");
    sqlBefehl.exec("INSERT INTO vokabeln VALUES"
                   "(1, 'Bedingung', 'condition', 'condition'),"
                   "(2, 'suchen', 'to look for', 'chercher'),"
                   "(3, 'Werbeanzeige', 'advertisement', 'publicité'),"
                   "(4, 'abkürzen', 'to abbreviate', 'raccourcir'),"
                   "(5, 'nützlich', 'useful', 'utile'),"
                   "(6, 'Wirkung', 'effect', 'effet'),"
                   "(7, 'beraten', 'to advise', 'conseiller'),"
                   "(8, 'übersetzen', 'to translate', 'traduire'),"
                   "(9, 'einfach', 'easy', 'simple'),"
                   "(10, 'ankündigen', 'to announce', 'annoncer')");

    //Combo Box Widget und List Widget verbinden
    connect(ui->CmdRichtung, SIGNAL(currentIndexChanged(int)), SLOT(CmdRichtungCurrentIndexChanged(int)));
    connect(ui->LstDeu, SIGNAL(itemSelectionChanged()), SLOT(LstDeuItemSelectionChanged()));
    connect(ui->CmdAuswahlLoeschen, SIGNAL(clicked()), SLOT(CmdAuswahlLoeschenClicked()));
    connect(ui->CmdNeuEingabeBeenden, SIGNAL(clicked()), SLOT(CmdNeuEingabeBeendenClicked()));
    connect(ui->CmdNeuEingabeSpeichern, SIGNAL(clicked()), SLOT(CmdNeuEingabeSpeichernClicked()));
    connect(ui->CmdNeuEingabeStarten, SIGNAL(clicked()), SLOT(CmdNeuEingabeStartenClicked()));
    connect(ui->CmdTestStarten, SIGNAL(clicked()), SLOT(CmdTestStartenClicked()));
    connect(ui->CmdTestBeenden, SIGNAL(clicked()), SLOT(CmdTestBeendenClicked()));
    connect(ui->CmdPruefen, SIGNAL(clicked()), SLOT(CmdPruefenClicked()));

    //ComboBox Widget füllen
    ui->CmdRichtung->addItem("(Sprachauswahl treffen)");
    ui->CmdRichtung->addItem("Deutsch - Englisch");
    ui->CmdRichtung->addItem("Deutsch - Französisch");
    ui->CmdRichtung->addItem("Englisch - Deutsch");
    ui->CmdRichtung->addItem("Englisch - Französisch");
    ui->CmdRichtung->addItem("Französisch - Deutsch");
    ui->CmdRichtung->addItem("Französisch - Englisch");

    //Anfangszustand einstellen
    this->resize(430, 165);
    this->setWindowTitle("Vokabeln");
    AuswahlInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AuswahlInit() {
    //Umschalten in Auswahlmodus
    ui->CmdRichtung->setEnabled(true);
    ui->CmdRichtung->setCurrentIndex(0);
    ui->CmdTestStarten->setEnabled(false);
    ui->CmdTestBeenden->setEnabled(false);
    ui->LstLabel->clear();
    ui->EdtAntwort->setEnabled(false);
    ui->CmdPruefen->setEnabled(false);
    ui->CmdNeuEingabeStarten->setEnabled(true);
}

void MainWindow::TestInit() {
    //Vorbereitung des Testmodus
    ui->CmdRichtung->setEnabled(false);
    ui->CmdTestStarten->setEnabled(true);
    ui->CmdTestBeenden->setEnabled(true);
    ui->CmdNeuEingabeStarten->setEnabled(false);
}

void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LstLabel->setText("Fehler: " + fehler.databaseText());
}

void MainWindow::NaechsteVokabeln()
{
    // Falls alle Vokabeln geschafft
    if(frage.count() < 1)
    {
        QMessageBox mb;
        mb.setText("Gratuliere! Alles geschafft.");
        mb.exec();

        AuswahlInit();
    }

    // Nächste Vokabeln auswählen und anzeigen
    else
    {
        zufallszahl = rand() % frage.count();
        ui->LstLabel->setText(frage.at(zufallszahl));
    }
}

void MainWindow::TabelleAnzeige()
{

}

void MainWindow::CmdRichtungCurrentIndexChanged(int index)
{
    // Falls Sprachauswahl getroffen
    if(index != 0)
    {
        // Vorbereiten des Testmodus
        TestInit();

        QString sqlCode;
        if(index == 1)
            sqlCode = "SELECT deu, eng FROM vokabeln";
        else if(index == 2)
            sqlCode = "SELECT eng, deu FROM vokabeln";
        else if(index == 3)
            sqlCode = "SELECT deu, fra FROM vokabeln";
        else if(index == 4)
            sqlCode = "SELECT fra, deu FROM vokabeln";
        else if(index == 5)
            sqlCode = "SELECT eng, fra FROM vokabeln";
        else if(index == 6)
            sqlCode = "SELECT fra, eng FROM vokabeln";
        sqlBefehl.exec(sqlCode);
        FehlerAnzeige();

        // QVector-Objekte leeren, mit Datensätzen füllen
        frage.clear();
        antwort.clear();
        while(sqlBefehl.next())
        {
            frage.append(sqlBefehl.value(0).toString());
            antwort.append(sqlBefehl.value(1).toString());
        }
    }
}

void MainWindow::LstDeuItemSelectionChanged()
{

}

void MainWindow::CmdTestStartenClicked()
{
    //Umschalten in Testmodus
    ui->CmdTestStarten->setEnabled(false);
    ui->EdtAntwort->setEnabled(true);
    ui->CmdPruefen->setEnabled(true);
    NaechsteVokabeln();
}

void MainWindow::CmdPruefenClicked()
{
    // Antwort prüfen
    QString kommentar;
    if(ui->EdtAntwort->text() == antwort.at(zufallszahl))
    {
        kommentar = "Richtig: " + frage.at(zufallszahl) + " = " + antwort.at(zufallszahl);
        frage.remove(zufallszahl);
        antwort.remove(zufallszahl);
    }
    else
        kommentar = "Falsch: " + frage.at(zufallszahl) + " = " + antwort.at(zufallszahl);

    // Kommentar anzeigen
    QMessageBox mb;
    mb.setText(kommentar);
    mb.exec();

    // Eingabe löschen, nächste Vokabel
    ui->EdtAntwort->clear();
    NaechsteVokabeln();
}

void MainWindow::CmdTestBeendenClicked()
{
    QMessageBox mb;
    mb.setText("TEst beenden?");
    mb.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    mb.setButtonText(QMessageBox::Yes, "Ja");
    mb.setButtonText(QMessageBox::No, "Nein");
    mb.setDefaultButton(QMessageBox::No);
    if(mb.exec() == QMessageBox::Yes)
        AuswahlInit();
}

void MainWindow::CmdNeuEingabeStartenClicked()
{

}

void MainWindow::CmdNeuEingabeSpeichernClicked()
{

}

void MainWindow::CmdAuswahlLoeschenClicked()
{

}

void MainWindow::CmdNeuEingabeBeendenClicked()
{

}

