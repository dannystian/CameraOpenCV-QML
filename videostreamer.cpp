#include "videostreamer.h"
#include <QDebug>

VideoStreamer::VideoStreamer()
{
    connect(&tUpdate, &QTimer::timeout, this, &VideoStreamer::streamVideo);
}

VideoStreamer::~VideoStreamer()
{
    cap.release();
    tUpdate.stop();
}

void VideoStreamer::streamVideo()
{
    cap >> frame;
    if (frame.empty()) {
        qWarning() << "Empty frame!";
        return;
    }


    QImage img(frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
    img = img.rgbSwapped();

    emit newImage(img);
}

void VideoStreamer::openVideoCamera(QString path)
{
    if (path.isEmpty()) {
        cap.open(0, cv::CAP_V4L2);
    }
    else if (path.length() == 1) {
        cap.open(path.toInt(), cv::CAP_V4L2);
    }
    else {
        cap.open(path.toStdString());
    }

    if (!cap.isOpened()) {
        qWarning() << "Gagal membuka kamera/video!";
        return;
    }

    double fps = cap.get(cv::CAP_PROP_FPS);
    if (fps <= 0) fps = 30;

    tUpdate.start(1000 / fps);
    qDebug() << "Video camera opened with FPS:" << fps;
}
