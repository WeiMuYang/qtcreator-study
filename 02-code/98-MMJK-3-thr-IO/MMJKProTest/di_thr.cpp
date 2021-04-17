#include "di_thr.h"
#include <QDebug>

/**
* Copyright (c) 2020 MYWB. All rights reserved
* @projectName   MMJKProTest
* @file          di_thr.cpp
* @brief         进行输入信号监听的线程
* @author
* @date          2020-11-04 22:23:58
*/

DIThr::DIThr(QThread *parent) : QThread(parent) {
    m_pauseTex.lock();
    m_status = 0;
    m_errCode_ret = Success;

}

void DIThr::setData(InstantDiCtrl *p, int port, int b)
{
    m_pinstantDiCtrl = p;
    m_port = port;
    m_bit = b;
}

void DIThr::run()
{
    while(1){
        m_pauseTex.lock();      // 3. 给对象加锁
        dataIsIn(m_port, m_bit);
        m_pauseTex.unlock();    // 4. 给对象解锁
        msleep(500);             // 暂停1秒
    }
}

/**
 * @brief 判断p端口的b位是否有数据输入（间隔0.5秒）
 * @param port 端口号，行号 ：  0 1
 * @param bit  位置号： 0 1 2 3 4 5 6 7
 * @return 0：未通电   1： 通电
 */
void DIThr::dataIsIn(int port, int bit){
    uint8 data = 0;
    m_errCode_ret = m_pinstantDiCtrl->ReadBit(int32(port), int32(bit), &data);

   // CHK_RESULT(m_errCode_ret);  error 20201105
    qDebug() << data;
    if(data == 1){

        emit sendInputData(m_port * 8 + m_bit, 1);

    }
    else{
        emit sendInputData(m_port * 8 + m_bit, 0);

    }
}

void DIThr::ThreadPause() {
    m_pauseTex.lock();      // 1. 给对象加锁
}
void DIThr::ThreadContinue() {
    m_pauseTex.unlock();    // 2. 给对象解锁
}


