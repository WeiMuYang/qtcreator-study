#include <QCoreApplication>
#include <QDebug>

void getBytePosBit(unsigned char byteData, int pos, int *pbit);
void separateByte(unsigned char byteData);
void changeBytePosBit(unsigned char *pByteData, int pos, int bit);

/**
 * @file        main.cpp
 * @brief       测试二进制位运算
 * @authors     YangWeiBin
 * @copyright   Gmagii
 * @version     v0.0.1
 * @date        2020-11-06 08:58:04
 */

/**
 * @brief 实现字节的拆分
 * @param byteData:1个字节的数
 */
void separateByte(unsigned char byteData){
    int arr[8] = {0};
    int bit = 0;
    // 进行的位的与运算，一个是1则是1

    for(int i = 0; i < 8; ++i){
        getBytePosBit(byteData, i, &bit);
        arr[i]  = bit;
    }
    qDebug() << arr[7] << " " << arr[6] << " " << arr[5] << " " << arr[4] << " "
             << arr[3] << " " << arr[2] << " " << arr[1] << " " << arr[0];
}

/**
 * @brief 修改一个字节pByteData的第pos位为bit
 * @param pByteData:要修改的字节,取值[0,255]
 * @param pos:字节的第pos位,取值[0,7]
 * @param bit:需要修改的值,取值[0,1]
 */
void changeBytePosBit(unsigned char *pByteData, int pos, int bit){
    // 位移动运算
    unsigned char temp = 0x01 << pos;   // 第pos位是1，剩下的都是0
    if(0 == bit){
        unsigned char temp0 = 0xff;     // 8位全是1                    1111 1111
        temp0 = temp0 ^ temp;           // ^异或：相同为0不同为1      ^  0010 0000
                                        // 第pos位是0，剩下的都是1   =   1101 1111
        (*pByteData) = (*pByteData) & temp0; // &按位与：两个都是1才是1
    }else if(1 == bit){
        (*pByteData) = (*pByteData) | temp;  // |按位或：两个都是0才是0
    }
}

/**
 * @brief 获取pByteData第pos位的bit值
 * @param pByteData: 需要获取的字节值 [0,255]
 * @param pos:对应的字节位置 [0,7]
 * @param pbit:位的值    [0,1]
 */
void getBytePosBit(unsigned char byteData, int pos, int *pbit){
    switch (pos) {
    case 0:
        (*pbit) = (byteData & 0x01) == 0x01 ? 1 : 0;
        break;
    case 1:
        (*pbit) = (byteData & 0x02) == 0x02 ? 1 : 0;
        break;
    case 2:
        (*pbit) = (byteData & 0x04) == 0x04 ? 1 : 0;
        break;
    case 3:
        (*pbit) = (byteData & 0x08) == 0x08 ? 1 : 0;
        break;
    case 4:
        (*pbit) = (byteData & 0x10) == 0x10 ? 1 : 0;
        break;
    case 5:
        (*pbit) = (byteData & 0x20) == 0x20 ? 1 : 0;
        break;
    case 6:
        (*pbit) = (byteData & 0x40) == 0x40 ? 1 : 0;
        break;
    case 7:
        (*pbit) = (byteData & 0x80) == 0x80 ? 1 : 0;
        break;
    default:
        qDebug() << "getBytePosBit @param pos is error!";
        break;
    }
}


int main(int argc, char *argv[])
{
    unsigned char byte = 231;

    separateByte(byte);
    changeBytePosBit(&byte, 7,0);
    separateByte(byte);
    changeBytePosBit(&byte, 5,0);
    separateByte(byte);
    changeBytePosBit(&byte, 5,0);
    separateByte(byte);
    changeBytePosBit(&byte, 1,0);
    separateByte(byte);
    changeBytePosBit(&byte, 1,0);
    separateByte(byte);
    changeBytePosBit(&byte, 1,0);
    separateByte(byte);
    changeBytePosBit(&byte, 3,1);
    separateByte(byte);
    changeBytePosBit(&byte, 3,1);
    separateByte(byte);
    changeBytePosBit(&byte, 3,1);
    separateByte(byte);
    changeBytePosBit(&byte, 5,1);
    separateByte(byte);
    changeBytePosBit(&byte, 5,1);
    separateByte(byte);

    return 0;
}
