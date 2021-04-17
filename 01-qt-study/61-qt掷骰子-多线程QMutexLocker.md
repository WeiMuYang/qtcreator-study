# 线程同步-QMutexLocker   
- 对于QMutex必须使用lock()和unlock()配对实现代码段的保护，在一些逻辑复杂的代码段或可能发生异常的代码中，配对可能会出错   
- QMutexLocker 是简化了，互斥量处理的类，QMutexLocker的构造函数，接收一个互斥量作为参数，并将其锁定，QMutexLocker的析构函数则将此互斥量解锁     
- 所以在QMutexLocker实例变量的生存周期内的代码得到保护，自动完成互斥量的锁定和解锁     


```C++
void QDiceThread::run()
{
    m_stop=false;//启动线程时令m_stop=false
    m_seq=0;
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的

    while(!m_stop)//循环主体
    {
        if (!m_paused)
        {
//            mutex.lock();
            QMutexLocker Locker(&mutex);  // 调用构造函数，锁定mutex
            m_diceValue=qrand(); //获取随机数
            m_diceValue=(m_diceValue % 6)+1;
            m_seq++;
//            mutex.unlock();
        }						          // 调用析构函数，解锁mutex
        msleep(500); //线程休眠100ms
    }
}
```




























