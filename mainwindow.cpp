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
    // FIXME: Move this to a library and off the main thread.
    cv::Ptr<cv::VideoCapture> capture(new cv::VideoCapture());
    if (!capture->open(0)) {
        fprintf(stderr, "on_pushButton_clicked(): could not open camera\n");
        return;
    }

    cv::Mat frame;
    for (uint64_t i = 0; i < 200; ++i) {
        if (capture->read(frame)) {
            fprintf(stderr, "on_pushButton_clicked() captured frame %llu (%d * %d)\n", i, frame.cols, frame.rows);
            QImage qFrame = QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            ui->visualFeedback->setProperty("pixmap", qFrame);
        }
    }
}
