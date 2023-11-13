#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pwNew = ui->listView_new;
    pwComplete = ui->listView_complete;

    pwNew->setDragEnabled(true);
    pwNew->setAcceptDrops(true);
    pwNew->setDropIndicatorShown(true);
    pwNew->setDefaultDropAction(Qt::MoveAction);

    pwComplete->setDragEnabled(true);
    pwComplete->setAcceptDrops(true);
    pwComplete->setDropIndicatorShown(true);
    pwComplete->setDefaultDropAction(Qt::MoveAction);

    pwNew->setModel(new QStringListModel());
    pwComplete->setModel(new QStringListModel());

    QFile file(":/new");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);

    pwNew->setStyleSheet(styleSheet);

    pwComplete->setStyleSheet("QListView {font-size: 20pt; font-weight: bold;} "
                          "QListView::item {background-color: #2ecc71; padding: 10%;"
                          "border: 1px solid #27ae60; }"
                          );

    QToolBar* toolBar = new QToolBar(this);
    addToolBar(toolBar);

    add = new QAction(this);
    remove = new QAction(this);

    add->setIcon(QIcon("/home/artem/Загрузки/add.png"));
    remove->setIcon(QIcon("/home/artem/Загрузки/delete.png"));

    connect(add, &QAction::triggered, this, &MainWindow::onAdd);
    connect(remove, &QAction::triggered, this, &MainWindow::onDelete);

    toolBar->addAction(add);
    toolBar->addAction(remove);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAdd(){
    pwNew->model()->insertRow(pwNew->model()->rowCount());
    QModelIndex oIndex = pwNew->model()->index( pwNew->model()->rowCount()-1,0);
    pwNew->edit(oIndex);


}
void MainWindow::onDelete(){
      QModelIndex oIndex = pwNew->currentIndex();
      QModelIndex oIndex1 = pwComplete->currentIndex();

      qDebug() <<  pwNew->currentIndex().data().toString();
      qDebug() <<  pwComplete->currentIndex().data().toString();
      pwComplete->currentIndex().model()->data(pwComplete->currentIndex()
//      pwNew->model()->removeRow(oIndex.row());
//      pwComplete->model()->removeRow(oIndex1.row());
}

