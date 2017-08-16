#ifndef DOUBLEOPTION_H
#define DOUBLEOPTION_H

#include "varoption.h"

namespace CuteSettings
{
    class DoubleOption : public VarOption
    {
        Q_OBJECT
        Q_PROPERTY(double value READ doubleValue WRITE setDoubleValue NOTIFY doubleValueChanged)
    public:
        explicit DoubleOption(QObject *parent = nullptr);

        double doubleValue() const;
        void setDoubleValue(double value);

    signals:
        void doubleValueChanged(double value);
    };
}

#endif // DOUBLEOPTION_H
