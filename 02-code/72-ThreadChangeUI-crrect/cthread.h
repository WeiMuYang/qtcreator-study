#ifndef CTHREAD_H
#define CTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>

class QLabel;

class ChangeStatus;

class CThread : public QThread
{
    Q_OBJECT
public:
    explicit CThread(QThread *parent = 0);

    void thrStart();

    void thrEnd();

    void thrPause();

    void thrContinue();

    void setData(QLabel * label, int s);

protected:
    void run();


signals:
    void sendCgeStatus(int s);

public slots:


private:
    QMutex m_qmutex;
    ChangeStatus *m_changeStatus;
    QLabel * m_label;
    int m_status;
};

#endif // CTHREAD_H
