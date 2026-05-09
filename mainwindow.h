#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_start_clicked();
    void updateTimeDisplay(qint64 ms);

    void on_btn_reset_clicked();

    void on_btn_lap_clicked();

    void addLapRecord(int lapNumber, qint64 lapTime);

private:
    Ui::MainWindow *ui;

    Stopwatch *stopwatch;
};
#endif
