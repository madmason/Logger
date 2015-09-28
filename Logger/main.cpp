#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Application.h"
using namespace logger;
using namespace logger::logging;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    new Application();
    return app.exec();
}
