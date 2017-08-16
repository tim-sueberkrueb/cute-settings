#include "doubleoption.h"

namespace CuteSettings
{
    DoubleOption::DoubleOption(QObject *parent) : VarOption(parent)
    {
        connect(this, &VarOption::valueChanged,
                [this]{ doubleValueChanged(value().toNumber()); });
    }

    double DoubleOption::doubleValue() const
    {
        return value().toNumber();
    }

    void DoubleOption::setDoubleValue(double value)
    {
        if (doubleValue() != value) {
            setValue(QJSValue(value));
            doubleValueChanged(value);
        }
    }
}
