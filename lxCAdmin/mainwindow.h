#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QList>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QStringListModel>
#include <QListView>
#include <QAbstractListModel>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList parse_users();
    bool CheckSubUID(QString &user);
};

#endif // MAINWINDOW_H
