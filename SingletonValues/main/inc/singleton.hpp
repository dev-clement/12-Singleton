#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>

class Singleton : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit Singleton(QObject *po_parent = nullptr);

    static QJSValue singletonProvider(QQmlEngine *po_engine, QJSEngine *po_scriptEngine);
    Q_INVOKABLE QJSValue getJSValue();
signals:
};

#endif // SINGLETON_HPP
