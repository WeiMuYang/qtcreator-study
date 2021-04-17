# QObject::connect: Cannot queue arguments of type XXX    

## 1 问题描述   
- 在多线程中，qt编译出现：QObject::connect: Cannot queue arguments of type XXX   
- 意思是说，信号槽队列中的数据类型必须是系统能识别的元类型，不然得用qRegisterMetaType()进行注册。参考如下链接和Qt的帮助文档即可解决这个问题    
- 线程中信号和槽函数的传递，参数是默认放到队列中去的，但是这个自定义的参数结构，不是QT自带的参数结构，不能识别。     

## 2 问题原因    
- qt文档描述：
	- With queued connections, the parameters must be of types that are known to Qt's meta-object system, because Qt needs to copy the arguments to store them in an event behind the scenes. If you try to use a queued connection and get the error message：    
	- **QObject::connect: Cannot queue arguments of type 'MyType' **    
	- call qRegisterMetaType() to register the data type before you establish the connection.    
- 文档翻译     
	- 对于排队连接，参数必须是Qt的元对象系统已知的类型，因为Qt需要复制参数以将它们存储在幕后事件中。如果尝试使用排队连接并收到错误消息：    
	- **QObject:：connect:无法将“MyType”类型的参数排队**   
	- 在建立连接之前，调用qRegisterMetaType（）来注册数据类型。    

## 3 解决方法   
- 将不识别的参数结构进行注册，让QT能够识别。    
- A 包含注册用到函数库的头文件：`#include <QMetaType> `  
- B 在构造的类的构造函数中调用其方法完成注册：qRegisterMetaType< QHash<int , pMsg> >("QHash<int , pMsg>");    

## 4 注意事项   
- 注册的数据类型，常见在`QList<Type > `、`QVector<Type > `等支持泛型的自定义类型中    

## 5 参考资料   
1. https://www.cnblogs.com/-wang-cheng/p/4962257.html    
2. http://cowboy.1988.blog.163.com/blog/static/7510579820101023024270/   
3. https://blog.csdn.net/leoeitail/article/details/107377121   
4. https://blog.csdn.net/Q1302182594/article/details/51082182?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param    

