# qt5移植到qt4问题汇总   

[toc]

## 1 lambda表达式   

### 1.1  信号槽经典写法   
- 在qt4中的connect函数，只支持经典的写法  

```C++
connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));  
```
### 1.2 lambda表达式及其相互转换  

- 在qt5中支持的写法比较多，详见[19 qt界面设计-信号和槽的自定义](./39-qt界面设计-信号和槽的自定义.md) ，其中包括：lambda表达式。   

```C++
    // 1. 传统Qt是连接方式
    // 传统Qt4连接方式为 信号发送者，信号，信号接受者，处理函数
    QObject::connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(qT4_slot()));
 
    //2. Qt5连接方式
    //其实这么写的方式和Qt4没有啥却别，只是在Qt4 中引用了信号槽，在简单的使用时没有问题，但是在庞大的工程中，信号和糟仅仅是宏替换，在编译的时候没有安全监测
    //Qt5的新方法，在编译的时候就会有监测，如果我们手误操作失误，就会出现问题
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::qT5_slot);

    //Qt5 Lambda表达式
    //这里需要注意 Lambda表达式是C++ 11 的内容，所以，需要再Pro项目文件中加入 CONFIG += C++ 11
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,[=](){qDebug()<<"lambda 表达式";});
}
void Widget::qT4_slot() {
    qDebug()<< "This is Qt 4 Connect method";
}
void Widget::qT5_slot() {
    qDebug()<< "This is Qt 5 Connect method";
}

```

### 1.3 转换的注意事项  
1. 定义新的槽函数，形参表是lambda表达式中，`[=]`后面的括号    
2. 新的槽函数的函数体是`{}`中的内容   
3. 记得在`*.h`文件中写声明  

## 2 `setSectionResizeMode`函数   
- 在qt4中是`setResizeMode` ，与qt5是不同的   

## 3 `QStringLiteral`类型   
- 在qt4中没有这个类型，然而qt5中在用QString时，需要将QString通过QStringLiteral来强转，然而在qt4中将其直接替换成空格即可   

## 4 qt4乱码解决   
- 在main函数中，加入如下代码：   

```C++
#include <QTextCodec>
//中文乱码解决代码，写在main函数中
QTextCodec *codec=QTextCodec::codecForName("utf-8");
QTextCodec::setCodecForLocale(codec);
QTextCodec::setCodecForCStrings(codec);
QTextCodec::setCodecForTr(codec);
```

## 5 在qt4中表格会变形   
- 因为在qt5中设计器增加和很多属性设置，但是在qt4中，设计器并没有那么强大，表格可能会变形，需要重新调整  

## 6 JsonCpp库的兼容性   
- 在qt5中，只需要`jsoncpp.cpp`和`json.h`，但是在qt4中，需要整个文件包，具体详见[20 在qt4下使用JsonCpp.md](./20-在qt4下使用JsonCpp.md)      




## 参考文献   
1. https://www.cnblogs.com/rainbow70626/p/10328143.html   
2. https://blog.csdn.net/u012724150/article/details/52851363  
3. https://blog.csdn.net/ys_073/article/details/8498837?utm_source=blogxgwz8   
