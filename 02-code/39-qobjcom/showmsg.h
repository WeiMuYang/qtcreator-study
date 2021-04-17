#ifndef SHOWMSG_H
#define SHOWMSG_H
#include <QString>

#include <QObject>
#include <QMessageBox>

class ShowMsg : public QObject
{
    Q_OBJECT
public:
    explicit ShowMsg(QObject *parent = 0);

signals:

public slots:
    // 接收SendMsg信号的槽函数
    void RecvMsg(QString str);
};

#endif // SHOWMSG_H
