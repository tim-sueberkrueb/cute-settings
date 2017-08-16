#ifndef SCRIPTEDOPTION_H
#define SCRIPTEDOPTION_H

#include "varoption.h"

namespace CuteSettings
{
    class ScriptedOption : public VarOption
    {
        Q_OBJECT

        Q_PROPERTY(QJSValue load READ loadFunction WRITE setLoadFunction NOTIFY loadFunctionChanged)
        Q_PROPERTY(QJSValue save READ saveFunction WRITE setSaveFunction NOTIFY saveFunctionChanged)

    public:
        explicit ScriptedOption(QObject *parent = nullptr);

        QJSValue loadFunction() const;
        void setLoadFunction(const QJSValue& loadFunction);

        QJSValue saveFunction() const;
        void setSaveFunction(const QJSValue& saveFunction);

        QJSValue saveJSValue();
        void loadJSValue(const QJSValue& value);

    signals:
        void loadFunctionChanged(const QJSValue& load);
        void saveFunctionChanged(const QJSValue& save);

    private: // members
        QJSValue _loadFunction;
        QJSValue _saveFunction;
    };
}
#endif // SCRIPTEDOPTION_H
