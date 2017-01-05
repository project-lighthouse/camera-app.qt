#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    fprintf(stderr, "main started\n");
    QApplication a(argc, argv);
    fprintf(stderr, "main application created\n");

    MainWindow w;
    fprintf(stderr, "window created\n");

    w.show();
    fprintf(stderr, "window shown\n");

    return a.exec();
}
