TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Application.cpp \
    logging/ConsoleLogger.cpp \
    logging/LogEntry.cpp \
    logging/Logger.cpp \
    logging/LoggerListener.cpp \
    logging/LogLevel.cpp \
    logging/LogManager.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Application.h \
    logging/ConsoleLogger.h \
    logging/LogEntry.h \
    logging/Logger.h \
    logging/LoggerListener.h \
    logging/LogLevel.h \
    logging/LogManager.h \

