#ifndef CTHTREAD_H
#define CTHTREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QString>

// 1. 带有信号槽的子线程，替换 QObject 为 QThread
class CThread : public QThread
{
    Q_OBJECT
public:
    explicit CThread(QObject *parent = 0);

signals:

public slots:
    void display();

protected:
    void run();

private:
    QTimer *m_pTimer;
};

#endif // CTHTREAD_H
