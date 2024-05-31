#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int richtung;
    int zufallszahl;
    QSqlDatabase con;
    QSqlQuery sqlBefehl;
    QVector<QString> frage;
    QVector<QString> antwort;
    QVector<int> idFeld;
private slots:
    void AuswahlInit();
    void TestInit();

    void FehlerAnzeige();
    void NaechsteVokabeln();
    void TabelleAnzeige();

    void CmdRichtungCurrentIndexChanged(int);
    void LstDeuItemSelectionChanged();
    void CmdTestStartenClicked();
    void CmdPruefenClicked();
    void CmdTestBeendenClicked();
    void CmdNeuEingabeStartenClicked();
    void CmdNeuEingabeSpeichernClicked();
    void CmdAuswahlLoeschenClicked();
    void CmdNeuEingabeBeendenClicked();

};
#endif // MAINWINDOW_H
