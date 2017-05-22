#include <iostream>
#include <vector>

#include "mainwindow.h"
#include <QApplication>

#include "priorityzone.h"
#include "priorityutils.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
