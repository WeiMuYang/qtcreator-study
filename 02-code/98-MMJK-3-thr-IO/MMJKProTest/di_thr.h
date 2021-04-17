#ifndef DITHR_H
#define DITHR_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "compatibility.h"
#include "bdaqctrl.h"
using namespace Automation::BDaq;
typedef unsigned char byte;


class DIThr : public QThread
{
    Q_OBJECT
public:
    explicit DIThr(QThread *parent = 0);
    void setData(InstantDiCtrl *p = 0, int port = 0 ,int b = 0);
    void dataIsIn(int port, int bit);
    void ThreadPause();
    void ThreadContinue();

signals:
    void sendInputData(int index,int stats);

protected:
    void run();

private:
    int m_port;
    int m_bit;
    ErrorCode m_errCode_ret;
    InstantDiCtrl *m_pinstantDiCtrl;
    int m_status;
    QMutex m_pauseTex;
};

#endif // DITHR_H
