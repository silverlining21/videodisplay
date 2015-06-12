#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <opencv.hpp>
#include <QtGui>
#include <QApplication>
#include <QFileDialog>
#include <opencv2/opencv.hpp>

#include "ui_mainwindow.h"

using namespace cv;
class QTime;
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = 0);
    ~mainwindow();

public slots:
    void updateImage();
    void on_pushButton_clicked();
    void updateResult();
    //void showResultTemplate(QString tempale_name);

signals:

private:
    QTimer* theTimer;
    Mat srcImage;
    Mat HSVImage;
    Mat grayImage;
    VideoCapture videoCap;
    QLabel *imageLabel;
    Ui::MainWindow ui;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif
