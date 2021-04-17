#ifndef CTHREAD_H
#define CTHREAD_H

// #include <QObject>
#include <QThread>


class CThread : public QThread
{
    Q_OBJECT
public:
    explicit CThread(QThread *parent = 0);

signals:

public slots:
    void display();

protected:
    void run();

private:

};

#endif // CTHREAD_H
