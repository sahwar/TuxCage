#include "mainwindow.h"
#include "ui_mainwindow.h"

QStringList MainWindow::parse_users() {
QStringList users;

//TODO: check the uid and gid settings from /etc/login.defs
//      (Ubuntu defaults to 1000)
    QFile passwdf("/etc/passwd");
    if(!passwdf.open(QIODevice::ReadOnly)) {
         QMessageBox notreadable;
         notreadable.setIcon(QMessageBox::Warning);
         notreadable.setWindowTitle("Fatal Error");
         notreadable.setText("The file \"/etc/passwd\" is not readable or doesn't exist!");
         notreadable.setStandardButtons(QMessageBox::Ok);
         notreadable.exec();
         users << "Error!";
         return users;
    }
    QTextStream buffer(&passwdf);

    while(!buffer.atEnd()) {
        QString line = buffer.readLine();
        QStringList PassLine = line.split(":", QString::SkipEmptyParts);
        if( PassLine[2].toInt() >= 1000  && PassLine[3].toInt() >= 1000 ) {
            if(PassLine[0] != "nobody"){
                users.append(PassLine[0]);
            }
        }
    }
    qDebug() << users;
    passwdf.close();
    return users;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->UsersList->addItems(parse_users());
    ui->UsersList->setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                   QAbstractItemView::DoubleClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}



