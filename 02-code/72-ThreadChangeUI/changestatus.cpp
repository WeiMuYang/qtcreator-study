#include "changestatus.h"
#include <QString>
#include <QLabel>

ChangeStatus::ChangeStatus()
{

}



void ChangeStatus::ChangeLightBulb(QLabel * lab, int status){
    QString  pathGif;
    if(0 == status)
        pathGif = ":/img/error.gif";
    else if(1 == status)
        pathGif = ":/img/warning.gif";
    else
        pathGif = ":/img/true.gif";

    movie = new QMovie(pathGif);
    lab->setMovie(movie);
    lab->show();
    movie->start();
}
