#include "ideditor.h"

idEditor::idEditor(QString &user)
{
}


bool idEditor::CheckSubUID() {
    QFile subuidf("/etc/subuid");
    if(!subuidf.open(QIODevice::ReadOnly)) { return false; }
    QTextStream buffer;
    bool retr = false;

    while(!buffer.atEnd()) {
        QString line = buffer.readLine();
        QStringList PassLine = line.split(":", QString::SkipEmptyParts);
        if( PassLine[0] == user ) {
            retr = true;
        }
    }
    return retr;
}
