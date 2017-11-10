#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);

    ui->treeWidget->setHeaderLabels(QStringList() << "ABC" << "123");

    addTreeRoot("A", "Root_first");
    addTreeRoot("B", "Root_second");
    addTreeRoot("C", "Root_third");

    proc = new QProcess(this);
    QObject::connect(proc, SIGNAL(readyReadStandardOutput()), this, SLOT(on_pushButton_3_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTreeRoot(QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    treeItem->setText(0, name);
    treeItem->setText(1, description);
    addTreeChild(treeItem, name + "A", "Child_first");
    addTreeChild(treeItem, name + "B", "Child_second");
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                              QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    treeItem->setText(0, name);
    treeItem->setText(1, description);

    parent->addChild(treeItem);
}

void MainWindow::on_pushButton_2_clicked()
{
    QBrush brush_red(Qt::red);
    ui->treeWidget->currentItem()->setBackground(0, brush_red);
    QBrush brush_green(Qt::green);
    ui->treeWidget->currentItem()->setBackground(1, brush_green);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString cmd;
    cmd = ui->lineEdit->text();
    proc->start(cmd);
    ui->textBrowser->append(proc->readAllStandardOutput());
    ui->lineEdit->clear();
}

void MainWindow::on_buttongitinit_clicked()
{
    QString cmd;
    cmd = "git init";
    proc->start(cmd);
    ui->textBrowser->append(proc->readAllStandardOutput());
}

void MainWindow::on_pushButton_clicked()
{
    QString cmd;
    cmd = "git add " + ui->gitaddfile->text();
    proc->start(cmd);
    ui->textBrowser->append(proc->readAllStandardOutput());
    ui->textBrowser->append("file added " + ui->gitaddfile->text());
    ui->gitaddfile->clear();
}

void MainWindow::on_buttoncommit_clicked()
{
    QString cmd;
    cmd = 'git commit -m "' + ui->gitcomment->text() + '"';
    proc->start(cmd);
    ui->textBrowser->append(proc->readAllStandardOutput());
    ui->textBrowser->append("file committed");
    ui->gitaddfile->clear();
}
