#include "scriptedoption.h"

namespace CuteSettings {
    ScriptedOption::ScriptedOption(QObject *parent) : VarOption(parent)
    {

    }

    QJSValue ScriptedOption::loadFunction() const
    {
        return _loadFunction;
    }

    void ScriptedOption::setLoadFunction(const QJSValue &loadFunction)
    {
        if (!loadFunction.equals(_loadFunction)) {
            loadFunctionChanged(_loadFunction = loadFunction);
        }
    }

    QJSValue ScriptedOption::saveFunction() const
    {
        return _saveFunction;
    }

    void ScriptedOption::setSaveFunction(const QJSValue &saveFunction)
    {
        if (!saveFunction.equals(_saveFunction)) {
            saveFunctionChanged(_saveFunction = saveFunction);
        }
    }

    QJSValue ScriptedOption::saveJSValue()
    {
        QJSValue finalValue = value();

        // Call JavaScript callback when requested and available
        // to allow user-scripted value conversion
        if (_saveFunction.isCallable()) {
            finalValue = _saveFunction.call(QJSValueList { finalValue });
        }

        return finalValue;
    }

    void ScriptedOption::loadJSValue(const QJSValue &value)
    {
        QJSValue finalValue = value;

        // Call JavaScript callback when requested and available
        // to allow user-scripted value conversion
        if (_loadFunction.isCallable()) {
            finalValue = _loadFunction.call(QJSValueList { value });
        }

        setValue(finalValue);
    }
}
