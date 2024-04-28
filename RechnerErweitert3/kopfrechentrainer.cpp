#include "kopfrechentrainer.h"
#include "./ui_kopfrechentrainer.h"
#include <ctime>

Kopfrechentrainer::Kopfrechentrainer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Kopfrechentrainer)
{
    ui->setupUi(this);
    std::srand((unsigned)time(nullptr));
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

        kommentar += QString(": %1 + %2 = %3").arg(a).arg(b).arg(ergebnis);

        ui->LblKommentar->setText(kommentar);
        ui->EditEingabe->setText("");
    }

    a = rand() % 20 + 20;
    b = rand() % 20 + 20;
    ergebnis = a + b;

    QString aufgabe = QString("%1 + %2").arg(a).arg(b);
    ui->LblAufgabe->setText(aufgabe);

    ui->EditEingabe->setFocus();
}

Kopfrechentrainer::~Kopfrechentrainer()
{
    delete ui;
}
