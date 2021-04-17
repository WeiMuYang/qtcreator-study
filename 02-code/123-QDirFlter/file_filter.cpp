#include "file_filter.h"

FileFilter::FileFilter(QObject *parent) : QObject(parent)
{

}




/**
 * @brief               文件是否满足条件
 * @param path          文件路径
 * @param condition     文件满足的条件：通配符
 * @return              true  满足条件    false   不满足条件
 */
bool FileFilter::filter(QString path,QString condition){
    QDir dir(path);
//    if (!dir.exists()) {
//        qDebug()<<"can't open "<<endl;
//        return false;
//    }
    dir.setFilter(QDir::Dirs);
    dir.setSorting(QDir::DirsFirst);
    QStringList filterst;
    filterst << condition;
    QFileInfoList list = dir.entryInfoList(filterst);
    while(list.length() <= 0 ){
            qDebug() << "It's not match your condition!";
            return false;
    }
    return true;
}
























