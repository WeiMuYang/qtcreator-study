#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QByteArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1 直接初始化
    QByteArray byteArr_arr1("123456");
    // 1.1 打印长度
    qDebug() << byteArr_arr1.length();  // 6
    // 1.2 长度增一
    byteArr_arr1.resize(byteArr_arr1.length() + 1);
    // 1.3 新增位置添加一个16进制数
    byteArr_arr1[byteArr_arr1.length()-1] = 0x3c;
    // 1.4 打印16进制
    qDebug() << byteArr_arr1.toHex();   // "3132333435363c"
    // 1.5 打印修改后的长度
    qDebug() << byteArr_arr1.length();  // 7

    qDebug() <<"=======================================";

    // 2 先初始化，在赋值
    QByteArray byteArr_arr2;
    byteArr_arr2.resize(6);
    // 2.1 打印长度
    qDebug() << byteArr_arr2.length();  // 6
    // 2.3 进行赋值
    byteArr_arr2[0] = 0x3a;
    byteArr_arr2[1] = 0x3b;
    byteArr_arr2[2] = 0x3c;
    byteArr_arr2[3] = 0x3d;
    byteArr_arr2[4] = 0x3e;
    byteArr_arr2[5] = 0x3f;
    // 2.4 长度增一
    byteArr_arr2.resize(byteArr_arr2.length() + 1);
    byteArr_arr2[byteArr_arr2.length()-1] = 0x4a;
    // 2.5 打印16进制
    qDebug() << byteArr_arr2.toHex();   // "3a3b3c3d3e3f4a"
    // 2.6 打印修改后的长度
    qDebug() << byteArr_arr2.length();  // 7

    qDebug() <<"=======================================";

    // 3 QByteArry与QString转换
    QString str = byteArrayToHexStr(byteArr_arr2);
    qDebug() << str;                    // "3A 3B 3C 3D 3E 3F 4A"
    qDebug() <<"=======================================";
    QByteArray test1 = str.toLocal8Bit();
    qDebug() << test1;                  // "3A 3B 3C 3D 3E 3F 4A"
    QByteArray test2 = QByteArray::fromHex(test1);
    qDebug() << test2;                  // ":;<=>?J"
    qDebug() <<"=======================================";
    // 4. QByteArray与int
    QByteArray ba;
    int n = 63;
    ba.setNum(n);           // ba == "63"
    ba.setNum(n, 16);       // ba == "3f"

    int m = 63;
    QByteArray::number(m);              // returns "63"
    QByteArray::number(m, 16);          // returns "3f"
    QByteArray::number(m, 16).toUpper();  // returns "3F"

    qDebug() <<"=======================================";
    // 5. QByteArray与float
    // 5.1 科学计数法
    QByteArray ba1 = QByteArray::number(12.3456, 'E', 1);
    // 5.2 保留3位小数
    QByteArray ba2 = QByteArray::number(1112.3456, 'f', 3);
    // 5.3 长度大小等于字符个数
    qDebug() << ba1.length() << ba1;  // 7 "1.2E+01"
    qDebug() << ba2.length() << ba2;  // 8 "1112.346"

    qDebug() <<"=======================================";
    // 6. QByteArray与char
    QByteArray array(10, 'Q');  // 初始化
    char *buf = array.data();   // buf只是一个指针   深拷贝
    int len = array.size();     // buf的长度
    qDebug() << buf;            // QQQQQQQQQQ
    qDebug() << len;            // 10


    char buff[10];
    //给buf赋值
    for (int i = 0; i < 10; i++)
    {
        buff[i] = (i + 1) % 3;  //其中存在'\0'元素
    }
    QByteArray arrayy;
    arrayy = QByteArray(buff, 10);//因为buff[]中有`\0`，必须要写上数据长度；否则，数据会直接截断，丢失数据
    qDebug() << buff;
    qDebug() << arrayy;             // "\x01\x02\x00\x01\x02\x00\x01\x02\x00\x01"


    qDebug() <<"=======================================";

    // 7. unsigned char 和char  分别赋值给QByteArray
    char c1 = 0xff;
    unsigned char uc1 = 0xff;
    QByteArray charAndunsigned;
    charAndunsigned.append(c1);
    charAndunsigned.append(uc1);
    qDebug() << charAndunsigned;        // "\xFF\xFF"
    qDebug() << charAndunsigned.toHex();// "ffff"






}


// 1. 字节数组 --> 十六进制QString
QString MainWindow::byteArrayToHexStr(const QByteArray &data)
{
    QString temp = "";
    QString hex = data.toHex();

    for (int i = 0; i < hex.length(); i = i + 2) {
        temp += hex.mid(i, 2) + " ";
    }

    return temp.trimmed().toUpper();
}


//// https://bbs.csdn.net/topics/392267649
/// // CRC8= X8+X5+X4+X0
///
unsigned char MainWindow::crc_high_first(unsigned char *ptr, unsigned char len)
{
    unsigned char i;
    unsigned char crc = 0x00; /* 计算的初始crc值 */

    while(len--) {
        crc ^= *ptr++;  /* 每次先与需要计算的数据异或,计算完指向下一数据 */
        for (i=8; i>0; --i)   /* 下面这段计算过程与计算一个字节crc一样 */
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;  // 生成多项式
            else
                crc = (crc << 1);
        }
    }

    return  crc;
}



MainWindow::~MainWindow()
{
    delete ui;
}
