#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Dial Widget
    ui->DiaEingabe->setMinimum(10);
    ui->DiaEingabe->setMaximum(60);
    ui->DiaEingabe->setValue(35);
    connect(ui->DiaEingabe, SIGNAL (valueChanged(int)), SLOT (DiaEingabeValueChange()));

    //Progress Bar Widget
    ui->PgrAusgabe->setValue(50);

    //Horizontal Slider Widget
    ui->SldEingabe->setMinimum(100);
    ui->SldEingabe->setMaximum(200);
    ui->SldEingabe->setValue(150);
    connect(ui->SldEingabe, SIGNAL(valueChanged(int)), SLOT(SldEingabeValueChange()));

    //Date / Time edit Widget
    QDate datum = QDate{2024,5,1};
    QTime time = QTime{15,00,00};
    QDateTime datumUndUhrzeit = QDateTime{datum,time};
    ui->DatEingabe->setDateTime(datumUndUhrzeit);
    ui->DatEingabe->setDisplayFormat("dd.MM.yyyy hh:mm:ss");
    connect(ui->DatEingabe, SIGNAL(dateTimeChanged(QDateTime)), SLOT(DatEingabeDateTimeChange()));

    //Calender Widget
    QDate datumMin = QDate{2000,01,01};
    ui->CalAuswahl->setMinimumDate(datumMin);
    QDate datumMax = QDate{2025,12,31};
    ui->CalAuswahl->setMaximumDate(datumMax);
    QDate datumNow = QDate{2024,05,01};
    ui->CalAuswahl->setSelectedDate(datumNow);
    connect(ui->CalAuswahl, SIGNAL(clicked(QDate)), SLOT(CalAuswahlClicked()));
}

void MainWindow::DiaEingabeValueChange()
{
    int wert = ui->DiaEingabe->value();
    ui->LblAusgabe->setText(QString("Dial Wert: %1").arg(wert));

    int bereich = ui->DiaEingabe->maximum() - ui->DiaEingabe->minimum();
    int differenz = wert - ui->DiaEingabe->minimum();
    int anteil = 100 * differenz/bereich;
    ui->PgrAusgabe->setValue(anteil);
    ui->LcdAusgabe->display(wert);
}
void MainWindow::SldEingabeValueChange()
{
    int wert = ui->SldEingabe->value();
    ui->LblAusgabe->setText(QString("Slider: %1").arg(wert));

    int bereich = ui->SldEingabe->maximum() - ui->SldEingabe->minimum();
    int differenz = wert - ui->SldEingabe->minimum();
    int anteil = 100 * differenz/bereich;
    ui->PgrAusgabe->setValue(anteil);

    ui->LcdAusgabe->display(wert);
}
void MainWindow::DatEingabeDateTimeChange()
{
    QDateTime wert = ui->DatEingabe->dateTime();
    ui->LblAusgabe->setText(wert.toString("dd.MM.yyyy hh:mm:ss"));
}
void MainWindow::CalAuswahlClicked()
{
    QDate wert = ui->CalAuswahl->selectedDate();
    ui->LblAusgabe->setText(wert.toString("dd.MM.yyyy"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
