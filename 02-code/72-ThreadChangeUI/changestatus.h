#ifndef CHANGESTATUS_H
#define CHANGESTATUS_H
#include <QMovie>

class QLabel;

class ChangeStatus
{
public:
    ChangeStatus();

    void ChangeLightBulb(QLabel * lab, int status);

    QMovie *movie;

};

#endif // CHANGESTATUS_H
