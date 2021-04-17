# QByteArray常见问题   

## 1 QbyteArray和int相互转化   
```C++
// int 转 QByteArray
int  intVar = 199;
QByteArray array;
int len = sizeof(intVar);
array.resize(len);
memcpy(array.data(), &intVar, len);  // 所求的值在前面 已知量在中间

// QByteArray 转 int
// array 数据接上面
int  outIntVar;
int len = sizeof(outIntVar);
memcpy(&outIntVar, array.data(), len);  // 所求的值在前面 已知量在中间
```

## 2 QbyteArray和float相互转化   
```C++
// float 转 QByteArray
float  floatVar = 199.0;
QByteArray array;
int len = sizeof(floatVar);
array.resize(len);
memcpy(array.data(), &floatVar, len);    // 所求的值在前面 已知量在中间

// QByteArray 转 float
// array 数据接上面
float  outFloatVar;
int len = sizeof(outFloatVar);
memcpy(&outFloatVar, array.data(), len);   // 所求的值在前面 已知量在中间
```
## 3 QByteArray的赋值与判断   
- 对于QByteArray中某个字节的赋值最好采用`'\x0a'`这种方式，因为`0x20`只能识别非0的十进制数字    
- 对于QByteArray中某个字节的判断也同理，最好采用`'\x0a'`这种方式      

```C++
	QByteArray arr1;
    arr1.append(0x20);
    arr1.append('\x00'); // ERROR arr1.append(0x00);
    arr1.append('\x00');
    arr1.append('\xdb'); // ERROR arr1.append(0xdb);
    arr1[0] = 0x22;
    // ERROR   arr1.at(0) = 0x22;

    if(arr1.at(1) == 0x00)
        qDebug() << arr1.toHex();

    if(arr1.at(3) == '\xdb')   // ERROR if(arr1.at(3) == 0xdb)  警告：而且无法进行正确判断
        qDebug() << arr1.toHex();
```






## 4 参考资料  
1. https://www.freesion.com/article/5107168141/  