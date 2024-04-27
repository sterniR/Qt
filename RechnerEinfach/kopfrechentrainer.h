#ifndef KOPFRECHENTRAINER_H
#define KOPFRECHENTRAINER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Kopfrechentrainer;
}
QT_END_NAMESPACE

class Kopfrechentrainer : public QMainWindow
{
    Q_OBJECT

public:
    Kopfrechentrainer(QWidget *parent = nullptr);
    ~Kopfrechentrainer();

private:
    Ui::Kopfrechentrainer *ui;
    int a, b, ergebnis;
private slots:
    void CmdPruefenNeuClicked();
};
#endif // KOPFRECHENTRAINER_H
