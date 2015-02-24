#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <QMessageBox>

QString ifguisuexists(QString guiSu)
{
    QProcess which;
    which.start(QString("which %1").arg(guiSu));
    which.waitForFinished(-1);
    QString supath = QString(which.readAll()).trimmed();
    if(!supath.isEmpty() && QFile::exists(supath)) { return supath; }
    else { return "REQCNOTFOUND"; }

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList allappargs = app.arguments();

    QProcess whoamip;
    whoamip.start("whoami");
    whoamip.waitForFinished();

//    if (QString(whoamip.readAll()).remove("\r").remove("\n") != "root") {

//        QString argsconc = "";

//        for (int i = 1; i < allappargs.size(); ++i)
//        {
//            argsconc += QString("\"%1\" ").arg(allappargs.at(i));
//        }
//        argsconc += "'rootcheck=no'";
//        QString gksulocation = ifguisuexists("gksu");
//        if (gksulocation != "REQCNOTFOUND")
//        {
//            QProcess::startDetached(QString("%1 %2 %3").arg(gksulocation).arg(app.applicationFilePath()).arg(argsconc));
//            return 0;
//        }
//        QString kdesulocation = ifguisuexists("kdesu");
//        if (kdesulocation != "REQCNOTFOUND")
//        {
//            QProcess::startDetached(QString("%1 %2 %3").arg(kdesulocation).arg(app.applicationFilePath()).arg(argsconc));
//            return 0;
//        }
//        QString gnomesulocation = ifguisuexists("gnomesu");
//        if (gnomesulocation != "REQCNOTFOUND")
//        {
//            QProcess::startDetached(QString("%1 %2 %3").arg(gnomesulocation).arg(app.applicationFilePath()).arg(argsconc));
//            return 0;
//        }
//        QString kdesudolocation = ifguisuexists("kdesudo");
//        if (kdesudolocation != "REQCNOTFOUND")
//        {
//            QProcess::startDetached(QString("%1 %2 %3").arg(kdesudolocation).arg(app.applicationFilePath()).arg(argsconc));
//            return 0;
//        }
//        QMessageBox rootmsgb;
//        rootmsgb.setIcon(QMessageBox::Warning);
//        rootmsgb.setWindowTitle("LxCAdmin must be run as root");
//        rootmsgb.setTextFormat(Qt::RichText);
//        rootmsgb.setText("LxCAdmin must be run as root. Close it, and re-run using either:<br/><b>sudo " + app.applicationFilePath() + "</b><br/>or:<br/><b>su - -c ' " + app.applicationFilePath() +" '</b>");
//        rootmsgb.setStandardButtons(QMessageBox::Ok);
//        rootmsgb.exec();
//        app.quit();
//    }
//    else {
    MainWindow w;
    w.show();

    return app.exec();
//    }
}
