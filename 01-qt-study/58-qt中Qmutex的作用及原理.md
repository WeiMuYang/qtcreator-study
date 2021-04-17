# QMutex的原理以及实现      
## 1 基本介绍   
- QMutex类提供线程之间的访问序列化。   
- QMutex的目的是保护对象、数据结构或代码段，以便一次只有一个线程可以访问它（这类似于Java synchronized关键字）。      
- 通常最好使用带有QMutexLocker的互斥锁，因为这样可以很容易地确保一致地执行锁定和解锁。  

- 非争用情况下   
	- QMutex经过优化，在非争用的情况下速度更快。如果互斥体上没有争用，非递归QMutex将不会分配内存。它的构造和销毁几乎没有任何开销，这意味着有许多互斥体作为其他类的一部分是很好的。
## 2 lock和trylock的区别  
- 在线程中调用lock()时，在同一位置尝试调用lock()的其他线程将阻塞在这个位置，直到获得锁的线程调用unlock()。     
- 可替代lock()的非阻塞方法是tryLock()。  

## 3 应用实例   
```c++
// MyThread.h
class MyThread: public QThread {
public:
    MyThread(QString name = "");

    void threadStart();
    void threadStop();
    void display(QString s);  // 1. 打印函数
protected:
    void run();
private:
    QString m_name;
    QMutex m_mutex;
};

// MyThread.cpp
MyThread::MyThread(QString name)
    :m_name(name)
{
}
void MyThread::threadStart()
{
    qDebug()<< m_name << "start.";
    start();
}

void MyThread::threadStop() {
    qDebug()<< m_name << "stop.";
    terminate();
    wait();
}
void MyThread::display(QString s)  {
    // if(m_mutex.tryLock()){   // tryLock
    m_mutex.lock();
        for (int i = 0; i < 10; ++i){
            qDebug() << s;
            sleep(1);
        }
        m_mutex.unlock();
    //  }
}
void MyThread::run() {
    display("Thread display!");	// 1. 子线程调用display
}
// MainWindow.h
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0, QString s = "");
    ~MainWindow();
protected:
    void closeEvent(QEvent *event);
private slots:
    void on_pushButton1_clicked();
private:
    Ui::MainWindow *ui;
    MyThread m_mythread;     // 1. 子线程对象
};
// MainWindow.cpp
MainWindow::MainWindow(QWidget *parent, QString name) :
    QMainWindow(parent), m_mythread(name),
    ui(new Ui::MainWindow)  {
    ui->setupUi(this);
    m_mythread.threadStart(); // 1. 启动子线程
}

MainWindow::~MainWindow()  {
    delete ui;
}
void MainWindow::closeEvent(QEvent *event)   {
    if(m_mythread.isRunning())
        m_mythread.threadStop();
}
void MainWindow::on_pushButton1_clicked()  {
        m_mythread.display("Main display!"); // 主线程调用 display
}
```
## 4 运行效果   
### 4.1 不用Mutex   
```bash
"test1" start.
"Thread display!"
"Thread display!"      // 此处单击按钮
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Thread display!"
"Main display!"
"Main display!"
```

### 4.2 使用Mutex.Lock    
```bash
"test1" start.
"Thread display!"
"Thread display!"   // 此处单击按钮
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
"Main display!"
```

### 4.3 使用Mutex.tryLock   
```bash
"test1" start.
"Thread display!"
"Thread display!"  // 此处单击按钮
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
"Thread display!"
```
## 5 注意事项   
1. 多个线程调用时，子线程肯定是在run()函数中调用     
2. Mutex.tryLock不阻塞当前进程，若加锁失败，返回false   
3. 无论用不用信号槽，同一个线程调用是有次序的(应该是，可验证)   



## 6 参考资料   
1. https://www.cnblogs.com/ybqjymy/p/12881760.html   
2. https://blog.csdn.net/boyemachao/article/details/99460107   
3. https://blog.csdn.net/hailmy/article/details/41745035?utm_medium=distribute.pc_relevant.none-task-blog-baidulandingword-1&spm=1001.2101.3001.4242   
4. https://blog.csdn.net/Zhangchen9091/article/details/21746873?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.channel_param   