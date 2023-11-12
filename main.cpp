#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

     QFile file(":/style");
     file.open(QFile::ReadOnly);
     QString styleSheet = QLatin1String(file.readAll());
     qApp->setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
