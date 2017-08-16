#include "intoption.h"

namespace CuteSettings
{
    IntOption::IntOption(QObject *parent) : VarOption(parent)
    {
        connect(this, &VarOption::valueChanged,
                [this]{ intValueChanged(value().toInt()); });
    }

    int IntOption::intValue() const
    {
        return value().toInt();
    }

    void IntOption::setIntValue(int value)
    {
        if (intValue() != value) {
            setValue(QJSValue(value));
            intValueChanged(value);
        }
    }
}
