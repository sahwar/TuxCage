#ifndef IDEDITOR_H
#define IDEDITOR_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class idEditor
{
public:
    idEditor(QString &user);

private:
    QString user;
    bool CheckSubUID();
    bool CheckSubGID();
    bool SetSubUID();
    bool SetSubGID();
};

#endif // IDEDITOR_H
