#ifndef DATAPROC_H
#define DATAPROC_H

#include <QObject>
#include <QTimer>
#include <QThread>

class DataProc : public QObject
{
Q_OBJECT
public:
    explicit DataProc(QObject *parent = 0);

signals:
    void valueChanged(const QString &str);

public slots:
    void slot_data_proc();
    void slot_init_value();

private:
    QTimer *timer;
    int count;
};

#endif // DATAPROC_H
