#ifndef IMAGEFORMAT_H
#define IMAGEFORMAT_H
#include "mainwindow.h"
#include <QImage>

/** Image format operations.
This class contains static functions to convert between OpenCV Mat and Qt QImage formats.
*/
class ImageFormat {
    public:
    /** Converts color Mat to QImage.
    @param src OpenCV Mat color image.
    @return Qt QImage.
    */
    static QImage Mat2QImage(cv::Mat const& src);

    /** Converts grayscale Mat to QImage.
    @param src OpenCV Mat grayscale image.
    @return Qt QImage.
    */
    static QImage MatGray2QImage(cv::Mat const& src);

    /** Converts color QImage to Mat.
    @param src Qt color QImage.
    @return Qt OpenCV Mat color image.
    */
    static cv::Mat QImage2Mat(QImage const& src);
};
#endif // IMAGEFORMAT_H

