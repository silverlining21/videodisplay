#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T21:30:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videodisplay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imageformat.cpp

HEADERS  += mainwindow.h \
    imageformat.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS +=  /usr/local/lib/libopencv_core.so \
         /usr/local/lib/libopencv_highgui.so \
         /usr/local/lib/libopencv_features2d.so \
         /usr/local/lib/libopencv_imgproc.so \
         /usr/local/lib/libopencv_flann.so  \
         /usr/local/lib/libopencv_calib3d.so\
         /usr/local/lib/libopencv_video.so  \
         /usr/local/lib/libopencv_videoio.so  \
         /usr/local/lib/libopencv_objdetect.so \
         /usr/local/lib/libopencv_ml.so
