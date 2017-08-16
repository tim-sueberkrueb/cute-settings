pragma Singleton
import QtQuick 2.0
import CuteSettings 0.1

Settings {
    id: settings

    property Category main: Category {
        property StringOption title: StringOption {
            defaultValue: "Cute Settings Demo"
        }

        property BoolOption active: BoolOption {
            defaultValue: false
        }

        property IntOption age: IntOption {
            defaultValue: 42
        }

        property DoubleOption favouriteNumber: DoubleOption {
            defaultValue: 3.1415
        }

        property VarOption anything: VarOption {
            label: "Variant Option"
            value: ({"test": [1, 2, 3]})
        }

        property ScriptedOption applesToBananas: ScriptedOption {
            defaultValue: "Banana"
            load: function(value) {
                if (value === "Apple") {
                    return "Banana";
                }
                return value;
            }
            save: function() {
                if (value === "Banana") {
                    return "Apple";
                }
                return value;
            }
        }
    }
}
