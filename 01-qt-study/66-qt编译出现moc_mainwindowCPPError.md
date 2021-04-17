# qt编译出现Moc问题    

## 1 问题描述   
- qt编译出现： -1: error: [debug/moc_mainwindow.cpp] Error 1   

![66-1](./img/66-1.png)  

## 2 问题分析   
1. 问题报错位置定位不明确，而且是和moc相关的问题，大概率是Qt预编译的问题    
2. mainwindow.cpp报错的话，检查mainwindow.cpp和mainwindow.h，看看是不是qt自带的语法问题：信号槽机制     


## 3 信号槽检查发现   
```C++
private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_110001_clicked();

    void onthreadUdp_started(); // Udp线程开始
    void onthreadUdp_finished();// Udp线程结束

    void onthreadWells_started();
	// 槽函数中不能包含属性成员
    QVector <WellsData> m_wellsOfSix;     // 6个井的容器A   --error
```




