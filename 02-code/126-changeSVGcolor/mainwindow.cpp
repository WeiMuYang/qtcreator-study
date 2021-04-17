#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSvg>
#include <QDomDocument>
#include <QPixmap>

void SetSVGBackColor(QDomElement elem, QString strtagname, QString strattr, QString strattrval);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 1. 通过 读取 XML获取颜色信息修改
    QString strPath = ":/icons/x-diamond-fill.svg";
    QFile file(strPath);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    QDomDocument doc;
    doc.setContent(data);
    file.close();
    QString color = "red";
    SetSVGBackColor(doc.documentElement(), "path", "fill", color);
    QByteArray svg_content = doc.toByteArray();



    QSvgRenderer *svg_render = new QSvgRenderer(svg_content);
    QPixmap *pixmap = new QPixmap(32, 32);
    pixmap->fill(Qt::transparent);
    QPainter painter(pixmap);
    svg_render->render(&painter);
    QIcon icon(*pixmap);
    ui->listWidget->addItem(new QListWidgetItem(icon, QObject::tr("1-jkldsjf")));



    // 2. 利用replace替换

    QFile file1(":/icons/x-diamond.svg");
    file1.open(QIODevice::ReadOnly);
    QByteArray data1 = file1.readAll();
    QString datastr = QString(data1);
    datastr.replace("currentColor", "green");
    data1 = datastr.toLatin1();

    QSvgRenderer *svg_render1 = new QSvgRenderer(data1);
    QPixmap *pixmap1 = new QPixmap(32, 32);
    pixmap1->fill(Qt::transparent);
    QPainter painter1(pixmap1);
    svg_render1->render(&painter1);
    QIcon icon1(*pixmap1);
    ui->listWidget->addItem(new QListWidgetItem(icon1, QObject::tr("2-jkldsjf")));



}

MainWindow::~MainWindow()
{
    delete ui;
}



void SetSVGBackColor(QDomElement elem, QString strtagname, QString strattr, QString strattrval)
{
    if (elem.tagName().compare(strtagname) == 0)
    {
        QString before_color = elem.attribute(strattr);
        elem.setAttribute(strattr, strattrval);
        QString color = elem.attribute(strattr);
    }
    for (int i = 0; i < elem.childNodes().count(); i++)
    {
        if (!elem.childNodes().at(i).isElement())
        {
            continue;
        }
        SetSVGBackColor(elem.childNodes().at(i).toElement(), strtagname, strattr, strattrval);
    }
}

