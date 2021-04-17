#include "io_ctrl.h"



#define  deviceDescription  L"USB-5830,BID#0"
const wchar_t* profilePath = L"";

IOCtrl::IOCtrl(QObject *parent) : QObject(parent)
{
    // need Add m_pinstantDiCtrl And m_DiThr_Arr Init  202011042228
    m_errCode_ret = Success;
    m_pinstantDoCtrl = InstantDoCtrl::Create();
    m_pinstantDiCtrl = InstantDiCtrl::Create();
    DeviceInformation devInfo(deviceDescription);
    m_errCode_ret = m_pinstantDoCtrl->setSelectedDevice(devInfo);
    if(BioFailed(m_errCode_ret))
        printf("ret error in IOCtrl() 001!\n");
    m_errCode_ret = m_pinstantDiCtrl->setSelectedDevice(devInfo);
    if(BioFailed(m_errCode_ret))
        printf("ret error in IOCtrl() 002!\n");

    m_errCode_ret = m_pinstantDoCtrl->LoadProfile(profilePath);//Loads a profile to initialize the device.
    if(BioFailed(m_errCode_ret))
        printf("ret error in IOCtrl() 003!\n");
    m_errCode_ret = m_pinstantDiCtrl->LoadProfile(profilePath);
    if(BioFailed(m_errCode_ret))
        printf("ret error in IOCtrl() 004!\n");

    for(int i = 0; i < 16; ++i)
        connect(&(m_DiThr_Arr[i]), SIGNAL(sendInputData(int,int)), this, SLOT(ReceiveInputData(int,int)),Qt::DirectConnection);


    byte  bufferForWriting[64] = {0};
    bufferForWriting[0] = 0x0;
    m_pinstantDoCtrl->Write(0, 1,bufferForWriting);
    m_pinstantDoCtrl->Write(1, 1,bufferForWriting);

    initThr();
    startThr();
}


void IOCtrl::initThr(){
    for(int i = 0; i < 8; ++i){
        m_DoThr_Arr[i].setData(m_pinstantDoCtrl,0,i);
        m_DoThr_Arr[i+8].setData(m_pinstantDoCtrl,1,i);
    }

    for(int i = 0; i < 8; ++i){
        m_DiThr_Arr[i].setData(m_pinstantDiCtrl,0,i);
        m_DiThr_Arr[i+8].setData(m_pinstantDiCtrl,1,i);
    }
}

void IOCtrl::ReceiveInputData(int index, int stats)
{
    if(stats == 1)
        m_DoThr_Arr[index].setType(0);
    else
        m_DoThr_Arr[index].setType(1);
}

void IOCtrl::startThr(){

    for(int i = 0; i < 3; ++i){
        m_DoThr_Arr[i].setType(1);
        m_DoThr_Arr[i].start();
        m_DiThr_Arr[i].start();
        m_DiThr_Arr[i].ThreadContinue();
    }
    for(int i = 0; i < 3; ++i){
        m_DoThr_Arr[i].ThreadContinue();
    }
    //    m_DoThr_Arr[0].setType(1);
    //    m_DoThr_Arr[0].start();
    //    m_DoThr_Arr[0].ThreadContinue();
    //    m_DiThr_Arr[0].start();
    //    m_DiThr_Arr[0].ThreadContinue();
}


IOCtrl::~IOCtrl()
{
    // Close device and release any allocated resource.
    m_pinstantDoCtrl->Dispose();
    m_pinstantDiCtrl->Dispose();

    // If something wrong in this execution, print the error code on screen for tracking.
    if(BioFailed(m_errCode_ret)) {
        wchar_t enumString[256];
        AdxEnumToString(L"ErrorCode", (int32)m_errCode_ret, 256, enumString);
        printf("Some error occurred. And the last error code is 0x%X. [%ls]\n", m_errCode_ret, enumString);
    }
}

