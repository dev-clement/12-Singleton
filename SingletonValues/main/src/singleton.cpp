#include "singleton.hpp"

Singleton::Singleton(QObject *po_parent): QObject{po_parent} {}

QJSValue Singleton::singletonProvider(QQmlEngine *po_engine, QJSEngine *po_scriptEngine) {
    Q_UNUSED(po_scriptEngine);
    int i_value = 5;

    QJSValue o_jsValue = po_engine->newObject();
    o_jsValue.setProperty("someProperty", i_value);

    // Put in an array
    QJSValue o_array = po_engine->newArray(3);
    for (unsigned int i_idx{0}; i_idx < 3; ++i_idx) {
        o_array.setProperty(i_idx, i_idx * 5);
    }

    o_jsValue.setProperty("mArray", o_array);
    return o_jsValue;
}

QJSValue Singleton::getJSValue() {
    auto o_engine = qmlEngine(this);
    static const int i_value = 5;

    // QJSEngine
    QJSValue o_value = o_engine->newObject();
    o_value.setProperty("someProperty", QJSValue{ i_value });

    // Put it in an array
    QJSValue o_jsArray = o_engine->newArray(3);
    for (unsigned int i_idx{0}; i_idx < 3; ++i_idx) {
        o_jsArray.setProperty(QString::number(i_idx), QJSValue{i_idx * 5});
    }

    o_value.setProperty("mArray", o_jsArray);
    return o_value;
}
