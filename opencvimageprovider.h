#ifndef OPENCVIMAGEPROVIDER_H
#define OPENCVIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QMutex>

class OpencvImageProvider : public QQuickImageProvider
{
public:
    OpencvImageProvider();

    void updateImage(const QImage &newImage);

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;


private:
    QImage image;
    QMutex mutex;
};

#endif
