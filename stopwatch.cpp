#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent): QObject(parent)
  , is_running(false)
  , common_timer(new QTimer(this))
  , accumulated_time(0)
{

    common_timer->setInterval(100);
    connect(common_timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

bool Stopwatch::isRunning() const
{
    return is_running;
}

void Stopwatch::start()
{
    if (!is_running) {
        is_running = true;
        common_timer->start();
        current_timer.start();
    }
}

void Stopwatch::stop()
{
    if (is_running) {
        is_running = false;
        common_timer->stop();
        accumulated_time += current_timer.elapsed();
    }
}

void Stopwatch::updateTime()
{
    if (is_running) {
        qint64 ms = accumulated_time + current_timer.elapsed();
        emit timeChanged(ms);
    }
}
