#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "primefind/pu.hpp"

#include <memory>
#include <chrono>
#include <QMainWindow>
#include <commoncpp/timer.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

    std::unique_ptr<primefinder> current_pf;
    const primefinder::Implementation *current_impl;

    bool running = false;

    common::Timer timer;
    std::time_t time_spent = 0;
    uint64_t current_value = 0;

private slots:
    void uiStartBenchmark();
    void uiStopBenchmark();
    void runNext();

signals:
    void benchmarkBegins();
    void benchmarkDone();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
