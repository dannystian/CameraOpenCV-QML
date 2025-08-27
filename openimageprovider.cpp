#include "opencvimageprovider.h"
#include <QColor>

OpencvImageProvider::OpencvImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
    image = QImage(200, 200, QImage::Format_RGB32);
    image.fill(QColor("black"));
}

QImage OpencvImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);

    QMutexLocker locker(&mutex);

    if (size)
        *size = image.size();

    if (requestedSize.width() > 0 && requestedSize.height() > 0)
        return image.scaled(requestedSize.width(), requestedSize.height(), Qt::KeepAspectRatio);

    return image;
}

void OpencvImageProvider::updateImage(const QImage &newImage)
{
    if (newImage.isNull())
        return;

    QMutexLocker locker(&mutex);
    image = newImage;
}
