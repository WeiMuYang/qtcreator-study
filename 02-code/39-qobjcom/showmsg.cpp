#include "showmsg.h"

ShowMsg::ShowMsg(QObject *parent) : QObject(parent)
{

}

void ShowMsg::RecvMsg(QString str)
{
    QMessageBox::information(0, tr("show"), str);
}
