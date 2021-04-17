# QcomboBox的用法及其设置   

## 1 基本用法  

```C++
// MainWindow.cpp
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 下拉后字体对齐  
    
    ui->combobox->insertItem(3, QIcon( ":/img/new.png" ), "bush");
    ui->combobox->setItemData(0, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(1, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(2, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(3, Qt::AlignCenter, Qt::TextAlignmentRole);

    connect(ui->combobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(printBoxText(QString )));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printBoxText(QString str)
{
    ui->label->setText(str);
}

// MainWindow.h
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void printBoxText(QString );
private:
    Ui::MainWindow *ui;
};
```

## 2 设置样式   
```CSS
#combobox{     
    background-color: rgb(54, 98, 180);  
	border:2px solid #00ffff; 
    /* border必须有， background-color才能生效  */
	color:#ffffff;
} 
```

- 要想使背景色生效，必须要设置一下某个border属性，border-color、border-width等等任何一个跟border相关的属性都行。因为pushbutton的原生边界把背景色给覆盖住了。   


## 参考资料  
1. https://blog.csdn.net/aa804738534/article/details/104756489?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param   
2. https://blog.csdn.net/ymc0329/article/details/7284498/   
3. https://blog.csdn.net/qq_31073871/article/details/79965015  