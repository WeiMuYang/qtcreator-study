#ifndef DO01CERTITHR_H
#define DO01CERTITHR_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "compatibility.h"
#include "bdaqctrl.h"
using namespace Automation::BDaq;
typedef unsigned char byte;


class DOThr : public QThread
{
    Q_OBJECT
public:
    explicit DOThr(QThread *parent = 0, InstantDoCtrl *p = 0, int port = 0 ,int b = 0);
    void setData(InstantDoCtrl *p = 0, int port = 0 ,int b = 0);
    void dataOut(uint8 status, double interval);
    void MySleep(double sec);
    void setType(int t);

    void ThreadPause();
    void ThreadContinue();

protected:
    void run();

private:
    int m_port;
    int m_bit;
    ErrorCode m_errCode_ret;
    InstantDoCtrl *m_pinstantDoCtrl;
    QMutex m_pauseTex;      // 6. 提供线程之间的访问序列化
    int m_n_type;
};

#endif // DO01CERTITHR_H
