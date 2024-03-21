#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "primefind/pu.hpp"

#include <chrono>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QProgressBar>
#include <QTimer>
#include <commoncpp/timer.hpp>



inline static constexpr double calculate_score(std::size_t current_value) {
    return double(current_value)*0.000001;
}


void MainWindow::uiStartBenchmark() {
    running = true;
    ui->resultDisplay->show();
    ui->benchmarkMenu->setDisabled(true);
    ui->resultBar->setValue(0);
    current_value = 3;
    time_spent = 0;
    timer.reset();
}

void MainWindow::uiStopBenchmark() {
    running = false;
    ui->resultDisplay->hide();
    ui->benchmarkMenu->setDisabled(false);
}

MainWindow::MainWindow(QWidget *parent)
      : QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initially hide result display
    ui->resultDisplay->hide();
    ui->startButton->setEnabled(false);

    // Initial setup
    connect(this, &MainWindow::benchmarkBegins, this, &MainWindow::uiStartBenchmark);
    connect(this, &MainWindow::benchmarkDone, this, &MainWindow::uiStopBenchmark);
    connect(ui->startButton, &QPushButton::pressed, this, &MainWindow::uiStartBenchmark);
    connect(ui->stopButton, &QPushButton::pressed, this, &MainWindow::uiStopBenchmark);
    connect(ui->startButton, &QPushButton::pressed, this, &MainWindow::runNext);

    // Detect and add benchmarks
    for (const auto& [impl_name, impl] : *primefinder::imlementations) {
        QRadioButton *btn = new QRadioButton(impl.description, ui->benchmarkMenu);
        ui->benchmarkSelection->layout()->addWidget(btn);
        connect(btn, &QRadioButton::clicked, this, [&, impl = std::addressof(impl), btn] () {
            current_pf = impl->constructor(impl->recommended_count);
            current_impl = impl;
            if (!current_pf->init()) {
                btn->setEnabled(false);
                btn->setText(btn->text()+" (unavailable)");
                ui->startButton->setEnabled(false);
                current_pf = nullptr;
            } else {
                ui->startButton->setEnabled(true);
            }
        });
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::runNext() {
    auto& pf = current_pf;

    // Stop if no supposed to be running
    if (!running)
        return;

    // Run
    timer.reset();
    const auto& result = pf->run(current_value);
    time_spent += timer.get<std::chrono::microseconds>();

    // Update value
    current_value += pf->count;

    // Update status
    const double score = calculate_score(current_value);
    while (int(score*1.2) > ui->resultBar->maximum())
        ui->resultBar->setMaximum(ui->resultBar->maximum()*2);
    ui->resultBar->setValue(score);

    // Stop if time is out
    if (time_spent >= 60000000) {
        // Update status with exact score
        const double seconds = double(time_spent)/1000000.;
        ui->resultBar->setValue(calculate_score(current_value)*(seconds/60.));

        // Add to log
        QLabel *l = new QLabel(current_impl->description, ui->logEntries);
        ui->logEntriesLayout->layout()->addWidget(l);
        QProgressBar *pb = new QProgressBar(ui->logEntries);
        ui->logEntriesLayout->layout()->addWidget(pb);
        pb->setFormat(ui->resultBar->format());
        pb->setMaximum(ui->resultBar->maximum());
        pb->setValue(ui->resultBar->value());

        // Stop
        emit benchmarkDone();
        return;
    }

    // Rerun soon
    QTimer::singleShot(1, this, &MainWindow::runNext);
}
