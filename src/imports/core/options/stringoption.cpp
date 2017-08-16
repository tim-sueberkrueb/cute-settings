#include "stringoption.h"

namespace CuteSettings
{
    StringOption::StringOption(QObject *parent) : VarOption(parent)
    {
        connect(this, &VarOption::valueChanged,
                [this]{ stringValueChanged(value().toString()); });
    }

    QString StringOption::stringValue() const
    {
        return value().toString();
    }

    void StringOption::setStringValue(const QString& value)
    {
        if (value != stringValue()) {
            setValue(QJSValue(value));
            stringValueChanged(value);
        }
    }
}
