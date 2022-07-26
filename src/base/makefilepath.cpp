#include "makefilepath.h"

#include <QDir>
#include <QCoreApplication>
MakeFilePath::MakeFilePath()
{

}

QString MakeFilePath::config(const QString &FileName)
{
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();dir.cd("config");
    return dir.absoluteFilePath(QString(FileName));
}

QString MakeFilePath::data(const QString &FileName)
{
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();dir.cd("data");
    return dir.absoluteFilePath(QString(FileName));
}

QString MakeFilePath::bin(const QString &FileName)
{

    QDir dir(QCoreApplication::applicationDirPath());
    return dir.absoluteFilePath(QString(FileName));
}

