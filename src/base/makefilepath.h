#ifndef MAKEFILEPATH_H
#define MAKEFILEPATH_H
#include <QString>
class MakeFilePath
{
public:
    MakeFilePath();
    static QString config(const QString& FileName);
    static QString data(const QString& FileName);
    static QString bin(const QString& FileName);
};

#endif // MAKEFILEPATH_H
