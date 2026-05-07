#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent): QObject(parent)
  , is_running(false)
{

}

bool Stopwatch::isRunning() const
{
    return is_running;
}

void Stopwatch::start()
{
    if (!is_running) {
        is_running = true;
    }
}

void Stopwatch::stop()
{
    if (is_running) {
        is_running = false;
    }
}
