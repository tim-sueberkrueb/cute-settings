#ifndef BOOLEANOPTION_H
#define BOOLEANOPTION_H

#include "varoption.h"

namespace CuteSettings
{
    class BoolOption : public VarOption
    {
        Q_OBJECT
        Q_PROPERTY(bool value READ boolValue WRITE setBoolValue NOTIFY boolValueChanged)
    public:
        explicit BoolOption(QObject *parent = nullptr);

        bool boolValue() const;
        void setBoolValue(bool value);

    signals:
        void boolValueChanged(bool value);
    };
}

#endif // BOOLEANOPTION_H
