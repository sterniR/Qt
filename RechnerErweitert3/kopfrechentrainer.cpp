#include "kopfrechentrainer.h"
#include "./ui_kopfrechentrainer.h"
#include <ctime>

Kopfrechentrainer::Kopfrechentrainer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Kopfrechentrainer)
{
    ui->setupUi(this);

    std::srand((unsigned)time(nullptr));
    ergebnis = -1;

    ui->LstOperation->addItem("Nur Addition");
    ui->LstOperation->addItem("Nur Subtraktion");
    ui->LstOperation->addItem("Addition oder Subtraktion");
    ui->LstOperation->setCurrentRow(0);

    ui->Opt1bis10->setText("1 bis 10");
    ui->Opt20bis50->setText("20 bis 40");
    ui->Opt50bis150->setText("50 bis 150");

    ui->Opt20bis50->setChecked(true);
    ui->ChkLoesung->setChecked(true);
    ui->ChkLoesung->setText("Lösung");

    connect(ui->CmdPruefenNeu, SIGNAL(clicked()), SLOT(CmdPruefenNeuClicked()));  //Die Methode "connect()" wird aufgerufen.
    connect(ui->CmdEnde, SIGNAL(clicked()), SLOT(close()));                     //Die Methode "connect()" wird aufgerufen.
}

void Kopfrechentrainer::CmdPruefenNeuClicked()
{
    if(ergebnis != -1)
    {
        int eingabe = ui->EditEingabe->text().toInt();

        QString kommentar;
        if(eingabe == ergebnis)
            kommentar = "Richtig";
        else
            kommentar = "Falsch";

        if(ui->ChkLoesung->isChecked())
            kommentar += QString(": %1 %2 %3 = %4").arg(a).arg(operation).arg(b).arg(ergebnis);
        ui->LblKommentar->setText(kommentar);
        ui->EditEingabe->setText("");

        if(ui->LstOperation->currentRow() == 0)
            operation = "+";
        else if(ui->LstOperation->currentRow() == 1)
            operation = "-";
        else
        {
            int operationzahl = std::rand() % 2;
            if(operationzahl == 0)
                operation = "+";
            else
                operation = "-";
        }

        if(ui->Opt1bis10->isChecked())
        {
            a = rand() % 1 + 9;
            b = rand() % 10 + 1;
        }
        else if(ui->Opt20bis50->isChecked())
        {
            a = rand() % 20 + 30;
            b = rand() % 20 + 30;
        }
        else
        {
            a = rand() % 100 + 50;
            b = rand() % 100 + 50;
        }
    }


    if(operation == "+")
        ergebnis = a + b;
    else
        ergebnis = a - b;

    QString aufgabe = QString("%1 %2 %3").arg(a).arg(operation).arg(b);
    ui->LblAufgabe->setText(aufgabe);

    ui->EditEingabe->setFocus();

}

Kopfrechentrainer::~Kopfrechentrainer()
{
    delete ui;
}
