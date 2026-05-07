#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    bool isRunning() const;

    void start();
    void stop();

private:
    bool is_running;
};

#endif // STOPWATCH_H
