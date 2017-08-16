#include <QJSEngine>
#include <QDebug>

#include "varoption.h"

namespace CuteSettings
{
    VarOption::VarOption(QObject *parent) : QObject(parent)
    {

    }

    QString VarOption::label() const
    {
        return _label;
    }

    void VarOption::setLabel(const QString &label)
    {
        if (label != _label) {
            labelChanged(_label = label);
        }
    }

    QJSValue VarOption::value() const
    {
        if (_value.isUndefined() || _value.isNull()) {
            return _defaultValue;
        }
        return _value;
    }

    void VarOption::setValue(const QJSValue &value, bool userInitiated)
    {
        if (!value.equals(_value)) {
            valueChanged(_value = value);
            if (userInitiated) {
                setDirty(true);
            }
        }
    }

    bool VarOption::dirty() const
    {
        return _dirty;
    }

    void VarOption::setDirty(bool dirty)
    {
        if (dirty != _dirty) {
            dirtyChanged(_dirty = dirty);
        }
    }

    QJSValue VarOption::defaultValue() const
    {
        return _defaultValue;
    }

    void VarOption::setDefaultValue(const QJSValue &defaultValue)
    {
        if (!defaultValue.equals(_defaultValue)) {
            defaultValueChanged(_defaultValue = defaultValue);
        }
    }

    bool VarOption::isDefault() const
    {
        return _value.isNull() || _value.isUndefined() || _value.equals(_defaultValue);
    }

    QJSValue VarOption::saveJSValue()
    {
        return value();
    }

    void VarOption::loadJSValue(const QJSValue &value)
    {
        setValue(value, false);
    }

    QVariant VarOption::saveVariantValue()
    {
        return saveJSValue().toVariant();
    }

    void VarOption::loadVariantValue(const QVariant &value)
    {
        auto engine = qjsEngine(this);
        if (!engine) {
            qWarning() << "Could not get associated QJSEngine of Option.";
            return;
        }
        auto jsValue = engine->toScriptValue(value);
        loadJSValue(jsValue);
    }

    QJsonValue VarOption::saveJsonValue()
    {
        return QJsonValue::fromVariant(saveVariantValue());
    }

    void VarOption::loadJsonValue(const QJsonValue &value)
    {
        loadVariantValue(value.toVariant());
    }
}
