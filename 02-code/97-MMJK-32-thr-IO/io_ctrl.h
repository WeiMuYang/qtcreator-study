#ifndef IOCTRL_H
#define IOCTRL_H

#include <stdlib.h>
#include <stdio.h>
#include <QTime>
#include <QObject>
#include <QCoreApplication>
#include "compatibility.h"
#include "bdaqctrl.h"
#include "do_thr.h"
#include "di_thr.h"
using namespace Automation::BDaq;
typedef unsigned char byte;

class IOCtrl : public QObject
{
    Q_OBJECT
public:
    explicit IOCtrl(QObject *parent = 0);
    ~IOCtrl();
    ErrorCode m_errCode_ret;
    InstantDoCtrl *m_pinstantDoCtrl;
    DeviceInformation m_devInfo;
    int32 m_startPort;
    DOThr m_DoThr_Arr[16];


    InstantDiCtrl *m_pinstantDiCtrl;   // 110422
    DIThr m_DiThr_Arr[16];             // 110422

    void startThr();
    void initThr();

public slots:
    void ReceiveInputData(int index,int stats);
};

#endif // IOCTRL_H
