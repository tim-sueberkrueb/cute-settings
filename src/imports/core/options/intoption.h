#ifndef INTOPTION_H
#define INTOPTION_H

#include "varoption.h"

namespace CuteSettings
{
    class IntOption : public VarOption
    {
        Q_OBJECT

        Q_PROPERTY(int value READ intValue WRITE setIntValue NOTIFY intValueChanged)

    public:
        explicit IntOption(QObject *parent = nullptr);

        int intValue() const;
        void setIntValue(int value);

    signals:
        void intValueChanged(int value);
    };
}

#endif // INTOPTION_H
