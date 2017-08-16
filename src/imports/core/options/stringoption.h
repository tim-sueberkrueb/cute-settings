#ifndef STRINGOPTION_H
#define STRINGOPTION_H

#include "varoption.h"

namespace CuteSettings
{
    class StringOption : public VarOption
    {
        Q_OBJECT

        Q_PROPERTY(QString value READ stringValue WRITE setStringValue NOTIFY stringValueChanged)
    public:
        explicit StringOption(QObject *parent = nullptr);

        QString stringValue() const;
        void setStringValue(const QString& value);

    signals:
        void stringValueChanged(const QString& value);
    };
}

#endif // STRINGOPTION_H
