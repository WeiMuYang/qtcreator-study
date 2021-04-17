#ifndef CREATEFRAME_H
#define CREATEFRAME_H
#include <QString>


class CreateFrame
{
public:
    CreateFrame();


private:
    QString m_str_time;         // 时间 年 月 日 时 分 秒
    unsigned char m_uc_crc;     // CRC校验
    int m_n_frameNum;           // 帧计数
    int m_n_retransmission;     // 重传次数
    int m_n_dataLength;         // 信息字个数
    QString m_str_dataSend;     // 信号源
    QString m_str_dataRevecive;
};

#endif // CREATEFRAME_H
