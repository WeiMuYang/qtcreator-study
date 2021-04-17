#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);

public slots:
    // 1. 对象运行的函数
    void process();
    // 2. 对象自行销毁
    void myDelete();

signals:
    // 3. process执行结束发送信号
    void endsig();
};

#endif // A_H
