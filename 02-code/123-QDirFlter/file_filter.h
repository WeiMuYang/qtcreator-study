#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QDebug>


class FileFilter : public QObject
{
    Q_OBJECT
public:
    explicit FileFilter(QObject *parent = nullptr);
    bool filter(QString path,QString condition);

signals:



};

#endif // FILEFILTER_H
