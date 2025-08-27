QT += quick
CONFIG += c++11
CONFIG += link_pkgconfig
PKGCONFIG += opencv4
SOURCES += \
        main.cpp \
        opencvimageprovider.cpp \
        videostreamer.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    resources.qrc


QML_IMPORT_PATH =


QML_DESIGNER_IMPORT_PATH =


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    opencvimageprovider.h \
    videostreamer.h
