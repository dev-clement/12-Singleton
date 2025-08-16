#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "singleton.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType("com.franco.custom", 0, 1, "MySingleton", Singleton::singletonProvider);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("SingletonValues", "Main");

    return app.exec();
}
