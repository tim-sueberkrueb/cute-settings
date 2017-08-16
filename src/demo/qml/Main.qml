import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import "."

Window {
    width: 640
    height: 480

    title: Settings.main.title.value

    ColumnLayout {
        anchors {
            fill: parent
            margins: 16
        }

        spacing: 16

        Label {
            text: "Settings Demo"
            font.pixelSize: 24
        }

        TextField {
            id: inputFilePath
            text: Settings.filePath
            placeholderText: "Settings filepath (e.g. settings.json)"
            selectByMouse: true
            onTextChanged: {
                if (text !== Settings.filePath) {
                    Settings.filePath = text;
                }
            }
        }

        Label {
            text: "Status: " + (Settings.dirty? "Unsaved changes have been made" : "Normal")
        }

        Row {
            spacing: 16

            Button {
                text: "Load"
                onClicked: {
                    Settings.load();
                }
            }

            Button {
                text: "Save"
                onClicked: {
                    Settings.save();
                }
            }
        }

        GridLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            columns: 2
            columnSpacing: 16
            rowSpacing: 16

            Label {
                text: "Title"
            }

            TextField {
                id: inputTitle
                text: Settings.main.title.value
                selectByMouse: true

                onTextChanged: {
                    if (text !== Settings.main.title.value) {
                        Settings.main.title.value = text;
                    }
                }

                Connections {
                    target: Settings.main.title
                    onValueChanged: inputTitle.text = Settings.main.title.value;
                }
            }

            Label {
                text: "Akitv?"
            }

            CheckBox {
                id: checkboxActive
                checked: Settings.main.active.value
                onCheckedChanged: {
                    if (checked !== Settings.main.active.value) {
                        Settings.main.active.value = checked;
                    }
                }

                Connections {
                    target: Settings.main.active
                    onValueChanged: checkboxActive.checked = Settings.main.active.value
                }
            }

            Label {
                text: "Age"
            }

            Row {
                spacing: 8

                Slider {
                    id: sliderAge
                    from: 0
                    to: 100
                    value: Settings.main.age.value
                    onValueChanged: {
                        if (value !== Settings.main.age.value) {
                            Settings.main.age.value = value;
                        }
                    }
                    Connections {
                        target: Settings.main.age
                        onValueChanged: sliderAge.value = Settings.main.age.value
                    }
                }

                Label {
                    anchors.verticalCenter: parent.verticalCenter
                    text: Settings.main.age.value
                }
            }

            Label {
                text: "Favourite number"
            }

            TextField {
                id: inputFavNumber
                text: Settings.main.favouriteNumber.value.toString()
                selectByMouse: true

                validator: DoubleValidator {}

                onTextChanged: {
                    var number = parseFloat(text);
                    if (number !== Settings.main.favouriteNumber.value) {
                        Settings.main.favouriteNumber.value = number;
                    }
                }

                Connections {
                    target: Settings.main.favouriteNumber
                    onValueChanged: inputFavNumber.text = Settings.main.favouriteNumber.value.toString();
                }
            }
        }

        Item { Layout.fillHeight: true } // spacer
    }

    Component.onCompleted: {
        showNormal();
    }
}
