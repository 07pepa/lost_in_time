#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSvg>
#include <QQmlContext>
#include "Controler.h"
#include <QQmlComponent>
#include <stdexcept>
int main(int argc, char *argv[])
{  QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    Controler kontroler;
    QQmlContext * context=engine.rootContext();
    context->setContextProperty("control",&kontroler);

    return app.exec();
}
