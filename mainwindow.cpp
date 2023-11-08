#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    SetUp(new SettingUpdate() )
{
    SetUp->Initialization();
    this->index = 0;
    ui->setupUi(this);
    this->LoadTask();
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

    SetUp->SaveSetting(datetime.toString("hhmmss"),"DATA" , datetime.toString("yyyy-MM-dd hh:mm:ss"));
    SetUp->SaveSetting(datetime.toString("hhmmss"),"TASK" , ui->task_line->text());
    SetUp->SaveSetting(datetime.toString("hhmmss"),"INFO" , ui->info_line->text());

    this->index++;
}


void MainWindow::on_pushButton_delete_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget_TODO->selectionModel()->selectedRows();
    while (!selectedRows.empty()) {
        datetime = QDateTime::fromString( ui->tableWidget_TODO->item(selectedRows[0].row(),0)->text() , "yyyy-MM-dd hh:mm:ss") ;
        SetUp->RemoveSetting(datetime.toString("hhmmss"));

        ui->tableWidget_TODO->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget_TODO->selectionModel()->selectedRows();
    }
    this->index--;
}

void MainWindow::LoadTask(){

    QStringList group = SetUp->getGroup();
    for(int i=0 ;i < group.size();i++){
        ui->tableWidget_TODO->insertRow(i);
        ui->tableWidget_TODO->setItem(i,0,new QTableWidgetItem(SetUp->LoadSetting(group[i],"DATA")));
        ui->tableWidget_TODO->setItem(i,1,new QTableWidgetItem(SetUp->LoadSetting(group[i],"TASK")));
        ui->tableWidget_TODO->setItem(i,2,new QTableWidgetItem(SetUp->LoadSetting(group[i],"INFO")));
        QTableWidgetItem *item = new QTableWidgetItem();
        item->data(Qt::CheckStateRole);
        item->setCheckState(Qt::Unchecked);
        ui->tableWidget_TODO->setItem(i,3,item);

    }
}
