#include "mainwindow.h"

#include <QApplication>
#include "test/test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testMysqlpp();
    MainWindow w;
    w.show();


    return a.exec();
}
