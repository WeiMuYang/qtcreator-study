#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pStackedLayout = new QStackedLayout();
    m_pStackedLayout->addWidget(ui->verticalWidget1);
    m_pStackedLayout->addWidget(ui->verticalWidget2);
    m_pStackedLayout->addWidget(ui-> horizontalWidget3);




    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");
    // ui->label->setPixmap(QPixmap::fromImage(imTrue));


    QLabel *locationLabel = new QLabel("July");

    locationLabel->setAlignment(Qt::AlignCenter);

    locationLabel->setMinimumSize(locationLabel->sizeHint());

    //QLabel *aixLabel;

    QLabel *aixLabel = new QLabel("“CTRL + H” for help");

    //Optional

    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框

    statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
    // addWidget(QWidget * widget, int stretch = 0) 位于最左端，
    // 当调用showMessage函数时，消息文字将与此函数添加的部件上文字重合
    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(aixLabel, 1);


    QLabel *per1 = new QLabel("1", this);
    QLabel *per2 = new QLabel("Ready2", this);
    QLabel *per3 = new QLabel("Ready3", this);
    //  addPermanentWidget(QWidget * widget, int stretch = 0) 添加永久性部件，
    // 永久意味着它不能被临时消息（showMessage函数）掩盖，位于最右端，stretch伸缩性为0
    per1->setPixmap(QPixmap::fromImage(imTrue));
        QPixmap pixmap = QPixmap::fromImage(imTrue);

//        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
      QPixmap fitpixmap = pixmap.scaled(6, 6, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

      ui->mode->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

     per1->setPixmap(fitpixmap);



    //statusBar()->addPermanentWidget(imTrue);
    statusBar()->addPermanentWidget(per1); //现实永久信息
    statusBar()->addPermanentWidget(per2);
    statusBar()->insertPermanentWidget(0, per3);

    statusBar()->showMessage("Status is here…", 5000); // 显示临时信息，时间3秒钟.
    ui->label_2->setStyleSheet("border-image: url(:/img/true.png);");

    ui->label_2->setToolTip("<html><head/><body><p>这是标签</p></body></html>");;


    ui->tableView->setRowCount(8);     //设置行数为8
    ui->tableView->setColumnCount(6);  //设置列数为6
    ui->tableView->clear();


    //自适应宽度
            ui->tableView->horizontalHeader()->setStretchLastSection(true);
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            //设置默认高度
            ui->tableView->verticalHeader()->setDefaultSectionSize(25);

            //隐藏滚动条
            ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
            ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);//不可选择
            ui->tableView->verticalHeader()->setVisible(false); //隐藏列表头

             //设置表头
            QStringList header;
            header << "类型" << "厚度" << "体积" << "类型" << "厚度" << "体积";
            ui->tableView->setHorizontalHeaderLabels(header);

            ui->tableView->setSpan(0, 3, 1, 5);//将无用单元格合并

            //设置每一项
            ui->tableView->setItem(0, 0, new QTableWidgetItem("F"));//
            ui->tableView->setItem(1, 0, new QTableWidgetItem("PF"));//
            ui->tableView->setItem(2, 0, new QTableWidgetItem("P_S_H")); //
            ui->tableView->setItem(3, 0, new QTableWidgetItem("P_I_H"));//
            ui->tableView->setItem(4, 0, new QTableWidgetItem("P_T"));//
            ui->tableView->setItem(5, 0, new QTableWidgetItem("P_S"));//
            ui->tableView->setItem(6, 0, new QTableWidgetItem("P_N"));//
            ui->tableView->setItem(7, 0, new QTableWidgetItem("P_I"));//

            ui->tableView->setItem(1, 3, new QTableWidgetItem("PF")); //
            ui->tableView->setItem(2, 3, new QTableWidgetItem("P_S_H"));//
            ui->tableView->setItem(3, 3, new QTableWidgetItem("P_I_H"));//
            ui->tableView->setItem(4, 3, new QTableWidgetItem("P_T"));//
            ui->tableView->setItem(5, 3, new QTableWidgetItem("P_S"));//
            ui->tableView->setItem(6, 3, new QTableWidgetItem("P_N"));//
            ui->tableView->setItem(7, 3, new QTableWidgetItem("P_I"));////每一项的厚度值

            ui->tableView->setItem(0, 1, new QTableWidgetItem(QString::number(200)));//










}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchPage()
{
    int nCount = m_pStackedLayout->count();
    int nIndex = m_pStackedLayout->currentIndex();

    // 获取下一个需要显示的页面索引
    ++nIndex;

    // 当需要显示的页面索引大于等于总页面时，切换至首页
    if (nIndex >= nCount)
        nIndex = 0;

    m_pStackedLayout->setCurrentIndex(nIndex);
}
//   https://blog.csdn.net/u011012932/java/article/details/51539851

void MainWindow::on_pushButton_clicked()
{
    switchPage();
}

//void MainWindow::on_pushButton_35_clicked()
//{
//    switchPage();
//    ui->gridWidget->setStyleSheet("background-color: rgb(255, 255, 255)");
//}

void MainWindow::on_pushButton1_clicked()
{
    m_pStackedLayout->setCurrentIndex(0);
    ui->gridWidget11->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->gridWidget12->setStyleSheet("");
    ui->gridWidget13->setStyleSheet("");
}

void MainWindow::on_pushButton2_clicked()
{
    m_pStackedLayout->setCurrentIndex(1);
    ui->gridWidget12->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->gridWidget11->setStyleSheet("");
    ui->gridWidget13->setStyleSheet("");
}

void MainWindow::on_pushButton3_clicked()
{
    m_pStackedLayout->setCurrentIndex(2);
    ui->gridWidget13->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->gridWidget11->setStyleSheet("");
    ui->gridWidget12->setStyleSheet("");
}
