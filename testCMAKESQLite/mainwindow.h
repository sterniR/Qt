#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QMessageBox>


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
    QSqlQuery sqlBefehl;
    QSqlDatabase con;
    QMessageBox box;

    QString anyIfEmpty(QString, bool);
private slots:
    void FehlerAnzeigen();
    void pushButtonAlleAnsehenClicked();
    void pushButtonEinfuegenClicked();
    void pushButtonAendernClicked();
    void pushButtonLoeschenClicked();
    void pushButtonFilternClicked();
    void Ausgabe(int);
    void ListAusgabeClicked();
};
#endif // MAINWINDOW_H
