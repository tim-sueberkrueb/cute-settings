#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QJsonObject>
#include <QQmlParserStatus>

#include "options/varoption.h"

namespace CuteSettings
{
    class Category : public QObject, public QQmlParserStatus
    {
        Q_OBJECT
        Q_INTERFACES(QQmlParserStatus)

        Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
        Q_PROPERTY(bool dirty READ dirty WRITE setDirty NOTIFY dirtyChanged)
    public:
        explicit Category(QObject *parent = nullptr);

        QString label() const;
        void setLabel(const QString& label);

        bool dirty() const;
        void setDirty(bool dirty);

        QJsonObject saveJsonObject(bool setClean = false);
        void loadJsonObject(const QJsonObject& jsonObject, bool setClean = false);

        Q_INVOKABLE void resetDefaults(bool setClean = false);

        void classBegin() override;
        void componentComplete() override;

    signals:
        void labelChanged(const QString& label);
        void dirtyChanged(bool dirty);

    private: // members
        QString _label;
        bool _dirty = false;
        bool _initialized = false;

    private: // methods
        void initialize();

    private slots:
        void childDirtyChanged(bool dirty);

    };
}

#endif // CATEGORY_H
