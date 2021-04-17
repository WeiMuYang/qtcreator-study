# 普通类修改成继承QT内部类   


## 1 语法修改   
```C++ 
/* MyButton.h */
#include <QWidget>     			 // 1. 添加要继承的类头文件
class MyButton :public QWidget{	 // 2. 添加继承 :public QWidget
    Q_OBJECT         		     // 3. qt使用信号槽的编译记号
public:
    			// 4. 修改默认构造函数，加上explicit和QWidget * parent = 0
    explicit MyButton(QWidget * parent = 0);
signals:  		// 5. 定义信号，信号只需要声明，不需要定义
    void sigClicked();
public slots:	// 6. 定义槽函数，在源文件中定义
	void changeLabel();
};
/* MyButton.cpp */
MyButton::MyButton(QWidget *parent ): // 7. 修改构造函数
    QWidget(parent)					  // 8. 通过初始化列表给父类赋值，默认为0
{

}
```

## 2 注意事项   
1. 根据构造函数，将父类的地址传递    
2. 在mainwindow中在构造函数中还要创建UI，和普通的有区别      




## 3 待解决的问题  
1.  如何发信号    
2.  如何将这个类的槽函数调用   
3.  信号槽的底层实现  
