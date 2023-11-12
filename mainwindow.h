#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "settingupdate.h"
#include <QToolBar>
#include <QListView>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected slots:
    void onAdd();
    void onDelete();
private:
    QListView *pwNew = nullptr;
    QListView *pwComplete = nullptr;
    QAction *add = nullptr;
    QAction *remove = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
