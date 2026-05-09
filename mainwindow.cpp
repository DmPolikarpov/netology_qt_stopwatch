#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create stopwatch
    stopwatch = new Stopwatch(this);

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

    // setup connections
    connect(stopwatch, &Stopwatch::timeChanged, this, &MainWindow::updateTimeDisplay);
    connect(stopwatch, &Stopwatch::lapCompleted, this, &MainWindow::addLapRecord);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_start_clicked()
{
    if (stopwatch->isRunning()) {
        stopwatch->stop();
        ui->btn_start->setText("Старт");
        ui->btn_lap->setEnabled(false);
    } else {
        stopwatch->start();
        ui->btn_start->setText("Стоп");
        ui->btn_lap->setEnabled(true);
    }
}

void MainWindow::updateTimeDisplay(qint64 ms)
{
    int min = ms / 60000;
    int sec = (ms % 60000) / 1000;
    int hdr = (ms % 1000) / 10;

    QString text = QString("%1.%2.%3")
                       .arg(min, 2, 10, QLatin1Char('0'))
                       .arg(sec, 2, 10, QLatin1Char('0'))
                       .arg(hdr, 2, 10, QLatin1Char('0'));
    ui->lbl_stopwatch->setText(text);
}

void MainWindow::on_btn_reset_clicked()
{
    stopwatch->reset();
    ui->lbl_stopwatch->setText("00.00.00");
    ui->tb_records->clear();
    ui->tb_records->hide();
    ui->btn_start->setText("Старт");
    ui->btn_lap->setEnabled(false);
}

void MainWindow::on_btn_lap_clicked()
{
    stopwatch->lap();
}

void MainWindow::addLapRecord(int lapNumber, qint64 lapTime)
{
    QString record = QString("Круг %1, время: %2 сек")
                         .arg(lapNumber)
                         .arg(QString::number(lapTime/1000, 'f', 1));
    if (ui->tb_records->isHidden())
    {
        ui->tb_records->show();
    };
    ui->tb_records->append(record);
}
