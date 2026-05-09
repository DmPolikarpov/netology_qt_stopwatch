#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    bool isRunning() const;

    void start();
    void stop();

signals:
    void timeChanged(qint64 ms);

private slots:
    void updateTime();

private:
    bool is_running;
    QTimer *common_timer;
    QElapsedTimer current_timer;
    qint64 accumulated_time;
};

#endif // STOPWATCH_H
