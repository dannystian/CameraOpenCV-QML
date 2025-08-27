#ifndef VIDEOSTREAMER_H
#define VIDEOSTREAMER_H

#include <QObject>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <iostream>

class VideoStreamer: public QObject
{
    Q_OBJECT
public:
    VideoStreamer();
    ~VideoStreamer();
    Q_INVOKABLE void openVideoCamera(QString path);

public slots:
    void streamVideo();

signals:
    void newImage(QImage &);
private:
    cv::Mat frame;
    cv::VideoCapture cap;
    QTimer tUpdate;
};

#endif
