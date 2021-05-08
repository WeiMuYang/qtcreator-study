#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled)
    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void setEnabled(bool e) { m_bl_enabled = e; }

    bool getEnabled() const { return m_bl_enabled; }


    double getMinValue() const;
    void setMinValue(double minValue);

public slots:
  //  void setRange(double minValue, double maxValue);

private:
    Ui::Widget *ui;

    double minValue;
    bool m_bl_enabled = false;



};

#endif // WIDGET_H
