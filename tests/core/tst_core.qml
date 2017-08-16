import QtQuick 2.0
import QtTest 1.0
import CuteSettings 0.1

TestCase {
    name: "CoreTests"

    Settings {
        id: settings

        property Category category: Category {
            property BoolOption boolOption: BoolOption {
                defaultValue: true
            }

            property DoubleOption doubleOption: DoubleOption {
                defaultValue: 3.1415
            }

            property IntOption intOption: IntOption {
                defaultValue: 33
            }

            property StringOption stringOption: StringOption {
                defaultValue: "Test string"
            }

            property VarOption varOption: VarOption {
                defaultValue: [1, 2, 3]
            }

            property ScriptedOption scriptedOption: ScriptedOption {
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

            property Category nestedCategory: Category {
                property BoolOption success: BoolOption {
                    defaultValue: true
                }
            }
        }
    }

    function test_defaultValues() {
        compare(settings.category.boolOption.value, true);
        compare(settings.category.doubleOption.value, 3.1415);
        compare(settings.category.intOption.value, 33);
        compare(settings.category.stringOption.value, "Test string");
        compare(settings.category.varOption.value, [1, 2, 3]);
        compare(settings.category.scriptedOption.value, "Banana");

        settings.resetDefaults(true);
    }

    function test_loadString() {
        var loadJson = {
            "category": {
                "boolOption": false,
                "doubleOption": 0.125,
                "intOption": 3,
                "stringOption": "Sweet dreams are made of this",
                "varOption": { "test": [1, 2, 3] },
                "scriptedOption": "Apple",
                "nestedCategory": {
                    "success": false
                }
            }
        };
        var loadJsonString = JSON.stringify(loadJson);
        settings.loadString(loadJsonString);

        compare(settings.category.boolOption.value, false);
        compare(settings.category.doubleOption.value, 0.125);
        compare(settings.category.intOption.value, 3);
        compare(settings.category.stringOption.value, "Sweet dreams are made of this");
        compare(settings.category.varOption.value, { "test": [1, 2, 3] });
        compare(settings.category.scriptedOption.value, "Banana");
        compare(settings.category.nestedCategory.success.value, false);

        var saveJsonString = settings.saveString();
        var saveJson = JSON.parse(saveJsonString);

        compare(loadJson, saveJson);

        settings.resetDefaults(true);
    }

    function test_dirty() {
        compare(settings.dirty, false);
        compare(settings.category.dirty, false);
        compare(settings.category.boolOption.dirty, false);

        settings.category.boolOption.value = false;

        compare(settings.category.boolOption.dirty, true);
        compare(settings.category.dirty, true);
        compare(settings.dirty, true);

        settings.resetDefaults(true);
    }
}
