#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set titles and labels
    setWindowTitle("Секундомер");
    ui->lbl_main->setText("Секундомер");
    // buttons
    ui->btn_start->setText("Старт");
    ui->btn_lap->setText("Круг");
    ui->btn_reset->setText("Сброс");
    // initial state
    ui->lbl_stopwatch->setText("00.00.00");
    ui->btn_lap->setEnabled(false);
    ui->tb_records->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

