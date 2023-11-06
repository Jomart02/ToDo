#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    char* Group[] = {"Task1"};
    SettingUpdate::Initialization(Group, 1);
    this->index = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_save_clicked()
{
    datetime = QDateTime::currentDateTime();
    ui->tableWidget_TODO->insertRow(index);
    ui->tableWidget_TODO->setItem(index,0,new QTableWidgetItem(datetime.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tableWidget_TODO->setItem(index,1,new QTableWidgetItem(ui->task_line->text()));
    ui->tableWidget_TODO->setItem(index,2,new QTableWidgetItem(ui->info_line->text()));

    QTableWidgetItem *item = new QTableWidgetItem();
    item->data(Qt::CheckStateRole);
    item->setCheckState(Qt::Unchecked);
    ui->tableWidget_TODO->setItem(index,3,item);

    SettingUpdate::SaveSetting(datetime.toString("yyyy-MM-dd hh:mm:ss"),"DATA" , datetime.toString("yyyy-MM-dd hh:mm:ss"));
    SettingUpdate::SaveSetting(datetime.toString("yyyy-MM-dd hh:mm:ss"),"TASK" , ui->task_line->text());
    SettingUpdate::SaveSetting(datetime.toString("yyyy-MM-dd hh:mm:ss"),"INFO" , ui->info_line->text());


    this->index++;
}


void MainWindow::on_pushButton_delete_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget_TODO->selectionModel()->selectedRows();
    while (!selectedRows.empty()) {
        ui->tableWidget_TODO->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget_TODO->selectionModel()->selectedRows();
    }
    this->index--;
}
