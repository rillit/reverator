#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QTreeView>
#include <QInputDialog>
#include <QtWidgets>
#include <QTreeWidget>
#include <QBrush>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_buttongitinit_clicked();

    void on_pushButton_clicked();

    void on_buttoncommit_clicked();

private:
    Ui::MainWindow *ui;

    void addTreeRoot(QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent,
                      QString name, QString description);
    QProcess *proc;
};

#endif // MAINWINDOW_H
