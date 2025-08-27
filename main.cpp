#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "opencvimageprovider.h"
#include "videostreamer.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    VideoStreamer videoStreamer;

    OpencvImageProvider *liveImageProvider(new OpencvImageProvider);

    engine.rootContext()->setContextProperty("VideoStreamer",&videoStreamer);
    engine.addImageProvider("live", liveImageProvider);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.load(url);

    QObject::connect(&videoStreamer, &VideoStreamer::newImage,
                     liveImageProvider, [=](const QImage &img){
                         liveImageProvider->updateImage(img);
                     });

    return app.exec();
}
