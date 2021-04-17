#ifndef IOCTRL_H
#define IOCTRL_H

#include <QObject>

class IOCtrl : public QObject
{
    Q_OBJECT
public:
    explicit IOCtrl(QObject *parent = 0);

signals:

public slots:
};

#endif // IOCTRL_H