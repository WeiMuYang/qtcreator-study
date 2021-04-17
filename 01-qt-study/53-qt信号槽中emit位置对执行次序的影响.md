# 信号槽中emit位置对执行次序的影响    
## 1 信号槽简介   
- 一个信号可以连接到许多插槽和信号。许多信号可以连接到一个插槽。   
- 如果一个信号连接到多个插槽，则当信号发出时，这些插槽将按照连接的相同顺序激活。   
- 如果函数成功地将信号连接到插槽，则该函数将返回一个QMetaObject:：Connection，它表示连接的句柄。     
- 如果连接句柄无法创建连接，例如，如果QObject无法验证信号或方法的存在，或者它们的签名不兼容，则连接句柄将无效。您可以通过将句柄强制转换为bool来检查它是否有效。    
- **默认情况下，每个连接都会发出一个信号；对于重复的连接，会发出两个信号。**    
- **您可以通过一个disconnect（）调用断开所有这些连接。如果传递Qt:：UniqueConnection类型，则只有在它不是重复的情况下才会建立连接。**    
- 如果已经有一个重复的（完全相同的信号发送到相同对象上完全相同的插槽），则连接将失败，并且connect将返回无效的QMetaObject:：connection。   
- 可选类型参数描述要建立的连接类型。具体而言，它确定特定信号是立即传送到时隙还是排队等待稍后的传递。     
- 如果信号排队，那么参数必须是Qt的元对象系统已知的类型，因为Qt需要复制参数以将它们存储在幕后事件中。如果您尝试使用排队连接并得到错误消息    

## 2 connectType    
- 此枚举描述信号和插槽之间可以使用的连接类型。具体而言，它确定特定信号是立即传送到槽，还是排队等待稍后的传递。    

参数|值|描述
:-:|:-:|-
Qt::AutoConnection|0|（默认）如果接收器位于发出信号的线程中，则使用Qt:：DirectConnection。否则，将使用Qt:：QueuedConnection。连接类型是在信号发出时确定的。   
Qt::DirectConnection|1|当信号发出时，插槽立即被调用。插槽在信令线程中执行。   
Qt::QueuedConnection|2|当控件返回到接收方线程的事件循环时调用该插槽。槽在接收器的线程中执行。   
Qt::BlockingQueuedConnection|3|与Qt:：QueuedConnection相同，只是在插槽返回之前信令线程会阻塞。如果接收器位于信令线程中，则不能使用此连接，否则应用程序将死锁。   
Qt::UniqueConnection|0x80|这是一个标志，可以使用位“或”与上述任何一种连接类型组合。设置Qt:：UniqueConnection时，如果连接已存在（即相同信号已连接到同一对对象的同一插槽），则QObject:：connect（）将失败。这个标志是在qt4.6中引入的。  


## 3 示例分析   
```c++
// MainWindow.h
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void Process1Clicked();
    void Process2Clicked();
    void Process3Clicked();
    void Process4Clicked();
signals:
    void signal1();
    void signal2();
    void signal3();
    void signal4();
private:
    Ui::MainWindow *ui;
};
// MainWindow.cpp
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Process1Clicked()),Qt::DirectConnection);   // 中断
    connect(this, SIGNAL(signal2()), this, SLOT(Process2Clicked()),Qt::QueuedConnection);	// 异步 
    connect(this, SIGNAL(signal3()), this, SLOT(Process3Clicked()),Qt::DirectConnection);
    connect(this, SIGNAL(signal4()), this, SLOT(Process4Clicked()),Qt::QueuedConnection);
    connect(this, SIGNAL(signal1()), this, SLOT(Process1Clicked()),Qt::DirectConnection);
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::Process1Clicked()  {
    qDebug() << "Process1 clicked";
    emit signal2();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process1";
        QThread::sleep(1);
    }
}
void MainWindow::Process2Clicked() {
    qDebug() << "Process2 clicked";
    emit signal3();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process2";
        QThread::sleep(1);
    }
}
void MainWindow::Process3Clicked() {
    qDebug() << "Process3 clicked";
    emit signal4();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process3";
        QThread::sleep(1);
    }
}
void MainWindow::Process4Clicked() {
    qDebug() << "Process4 clicked";
    emit signal1();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process4";
        QThread::sleep(1);
    }
}
```

## 3 执行效果   
```bash
Process1 clicked
Process1
Process1
Process1
Process1
Process2 clicked
Process3 clicked
Process3
Process3
Process3
Process3
Process2
Process2
Process2
Process2
Process4 clicked
Process1 clicked
Process1
Process1
Process1
Process1
Process4
Process4
Process4
Process4

```
## 4 注意事项   
1. 这个次序影响的是**发射信号 emit语句发送后，是立马启动emit对应的槽函数还是等当前正运行的槽函数结束再执行**，分为：中断和异步。    
2. 经过上面的分析我们可以知道，一般常用的connect后执行方式有两种方式：  
	- 中断方式   
	- 异步方式   
3. 中断方式只需要将连接方式换成Qt::DirectConnection就可以了。   
4. 异步方式只需要将连接方式换成Qt::QueuedConnection就可以了。  

## 5 参考资料   
1. https://blog.csdn.net/weixin_46146288/article/details/106869333?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param   
2. https://blog.csdn.net/swt18772101268/article/details/106015504   
3. https://blog.csdn.net/maplblue/article/details/52946665?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.channel_param       
