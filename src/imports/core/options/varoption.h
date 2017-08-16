#ifndef VAROPTION_H
#define VAROPTION_H

#include <QObject>
#include <QVariant>
#include <QJSValue>
#include <QJsonValue>

namespace CuteSettings
{
    class VarOption : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
        Q_PROPERTY(bool dirty READ dirty WRITE setDirty NOTIFY dirtyChanged)
        Q_PROPERTY(QJSValue value READ value WRITE setValue NOTIFY valueChanged)
        Q_PROPERTY(QJSValue defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged)

    public:
        explicit VarOption(QObject *parent = nullptr);

        QString label() const;
        void setLabel(const QString& label);

        QJSValue value() const;
        void setValue(const QJSValue& value, bool userInitiated = true);

        bool dirty() const;
        void setDirty(bool dirty);

        QJSValue defaultValue() const;
        void setDefaultValue(const QJSValue& defaultValue);

        bool isDefault() const;

        virtual QJSValue saveJSValue();
        virtual void loadJSValue(const QJSValue& value);

        QVariant saveVariantValue();
        void loadVariantValue(const QVariant& value);

        QJsonValue saveJsonValue();
        void loadJsonValue(const QJsonValue& value);

    signals:
        void labelChanged(const QString& label);
        void dirtyChanged(bool dirty);
        void valueChanged(const QJSValue& value);
        void defaultValueChanged(const QJSValue& value);

    private: // members
        QString _label;
        bool _dirty = false;
        QJSValue _value;
        QJSValue _defaultValue;
    };
}

#endif // VAROPTION_H
