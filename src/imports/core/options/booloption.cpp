#include "booloption.h"

namespace CuteSettings
{
    BoolOption::BoolOption(QObject *parent) : VarOption(parent)
    {
        connect(this, &VarOption::valueChanged,
                [this]{ boolValueChanged(value().toBool()); });
    }

    bool BoolOption::boolValue() const
    {
        return value().toBool();
    }

    void BoolOption::setBoolValue(bool value)
    {
        if (boolValue() != value) {
            setValue(QJSValue(value));
            boolValueChanged(value);
        }
    }
}
