#ifndef PROCESSA_H
#define PROCESSA_H

#include <QObject>
#include <QDebug>

class ProcessA : public QObject
{
    Q_OBJECT
public:
    explicit ProcessA(QObject *parent = 0);
    void setStop(int s){
        m_stop = s;
    }


public slots:
    void displayA();

signals:
    void processASig();

private:
    int m_stop;
};

#endif // PROCESSA_H
