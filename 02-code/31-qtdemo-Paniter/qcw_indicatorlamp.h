#ifndef QCWINDCCATORLAMP_H
#define QCWINDCCATORLAMP_H

#include <QWidget>

class QColor;

class Q_DECL_EXPORT QcwIndicatorLamp: public QWidget
{
    Q_OBJECT

	
public:    
    explicit QcwIndicatorLamp(QWidget *parent = 0);
	bool isAlarm() const {return m_alarm;}
		       	            
Q_SIGNALS:

public Q_SLOTS:
	void setAlarm(bool);
    void setState();

protected:
	void paintEvent(QPaintEvent *);
  
private:
	bool m_alarm;
    bool m_state;
};

#endif
