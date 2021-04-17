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

    void setName(QString s){
        m_str_name = s;
    };
public slots:
    void displayA();


private:
    int m_stop;
    QString m_str_name;
};

#endif // PROCESSA_H
