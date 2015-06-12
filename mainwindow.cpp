#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageformat.h"
mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateImage()));
    timer->start(10);
    //从摄像头捕获视频
    if(videoCap.open(0))
    {
        srcImage = Mat::zeros(320, 240, CV_8UC3);

        //srcImage = Mat::zeros(videoCap.get(CAP_PROP_FRAME_HEIGHT), videoCap.get(CAP_PROP_FRAME_WIDTH), CV_8UC3);
        //        theTimer.start(33);
    }

}

mainwindow::~mainwindow()
{

}

void mainwindow::paintEvent(QPaintEvent *e)
{
    //显示方法一
    //    QPainter painter(this);
    //    QImage image1 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    //    painter.drawImage(QPoint(20,20), image1);
    //显示方法二
    QImage image2 = ImageFormat::Mat2QImage(srcImage);
    ui.label_2->setPixmap(QPixmap::fromImage(image2));

    QImage image3 = ImageFormat::Mat2QImage(grayImage);
    ui.label_3->setPixmap(QPixmap::fromImage(image3));

    QImage image4 = ImageFormat::Mat2QImage(HSVImage);
    ui.label->setPixmap(QPixmap::fromImage(image4));

    //ui.label->resize(ui.label->pixmap()->size());
    //ui.label->hide();
    //imageLabel->show();
}

void mainwindow::updateImage()
{
    videoCap >> srcImage;
    cv::resize(srcImage, srcImage, Size(320, 240));
    if(srcImage.data)
    {
        //std::cout<<srcImage.size()<<std::endl;
        cvtColor(srcImage, grayImage, COLOR_BGR2YCrCb);
        cvtColor(srcImage, HSVImage, COLOR_BGR2HSV);
        cvtColor(srcImage, srcImage, COLOR_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
        this->update();	//发送刷新消息
    }
}

void mainwindow::updateResult(){
    ui.label->hide();
}

void mainwindow::on_pushButton_clicked()
{
    ui.label_2->show();
}


void mainwindow::on_pushButton_2_clicked()
{
    ui.label_2->hide();
}

void mainwindow::on_pushButton_3_clicked()
{
    exit(0);
    //quit();
}
