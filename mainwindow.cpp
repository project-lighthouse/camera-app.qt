#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/cvstd.hpp>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    fprintf(stderr, "MainWindow::MainWindow()\n");
    ui->setupUi(this);
    fprintf(stderr, "MainWindow::MainWindow() done\n");
}

MainWindow::~MainWindow()
{
    fprintf(stderr, "MainWindow::~MainWindow()\n");
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fprintf(stderr, "on_pushButton_clicked()\n");
    cv::Ptr<cv::VideoCapture> capture(new cv::VideoCapture());
    if (!capture->open(0)) {
        fprintf(stderr, "on_pushButton_clicked(): could not open camera\n");
        return;
    }

    cv::Mat frame;
    for (uint64_t i = 0; i < 200; ++i) {
        if (capture->read(frame)) {
            fprintf(stderr, "on_pushButton_clicked() captured frame %llu\n", i);
        }
    }
}
