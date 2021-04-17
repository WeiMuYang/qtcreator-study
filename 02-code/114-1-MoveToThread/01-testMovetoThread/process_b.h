#ifndef THREAD01_H
#define THREAD01_H

#include <QObject>
#include <QDebug>

class ProcessB : public QObject
{
    Q_OBJECT
public:
    explicit ProcessB(QObject *parent = 0);
    void setStop(int s){
        m_stop = s;
    }

public slots:
    void displayB();

signals:
    void processBSig();
private:
    int m_stop;
};

#endif // THREAD01_H
