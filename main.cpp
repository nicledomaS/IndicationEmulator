#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "IndicationHandler.h"
#include "IndicationController.h"
#include "EventGenerator.h"
#include "Diod.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    auto diod = std::make_shared<Diod>();
    auto controller = std::make_shared<indicationEmulator::IndicationController>(diod);
    auto handler = indicationEmulator::createHandler(controller);

    QQmlApplicationEngine engine;

    EventGenerator switchController(handler);
    auto context = engine.rootContext();
    context->setContextProperty("controller", &switchController);
    context->setContextProperty("diod", diod.get());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    return app.exec();
}
