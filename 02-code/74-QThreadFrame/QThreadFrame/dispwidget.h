#ifndef DISPWIDGET_H
#define DISPWIDGET_H

#include <QDialog>
#include <QPainter>
#include <QImage>

#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui.hpp>

class DispWidget : public QObject {
    Q_OBJECT
public:
    DispWidget(QWidget *parent = 0);
    ~DispWidget();

    QImage IplImageToQImage(const IplImage * iplImage,double mini, double maxi);

public slots:
    bool showImage();

signals:
    void signal_disp_send();

public:
    QImage image;

};

#endif // DISPWIDGET_H
