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
    QSqlDatabase con;
    QSqlQuery sqlBefehl;
private slots:
    void CmdEinfuegenClicked();
    void FehlerAnzeige();
    void CmdAnzeigenAlleClicked();
    void Ausgabe(int);
    void CmdAuswaehlenClicked();
    void CmdEingabeClicked();
    void CmdAktionClicked();
};
#endif // MAINWINDOW_H
