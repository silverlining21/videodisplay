#include "imageformat.h"

QImage ImageFormat::Mat2QImage(cv::Mat const& srcImage) {
     QImage dest2 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
     return dest2;
}

QImage ImageFormat::MatGray2QImage(cv::Mat const& srcImage) {
     QImage dest2 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_Indexed8);
     return dest2;
}

cv::Mat ImageFormat::QImage2Mat(QImage const& src) {
     cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
     cv::Mat result;
     cvtColor(tmp, result,COLOR_BGR2RGB);
     return result;
}
