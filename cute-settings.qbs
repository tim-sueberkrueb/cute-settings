import qbs

Project {
    property bool withDemo: true
    property bool testsEnabled: false

    name: "cute-settings"
    sourceDirectory: "src/imports"
    minimumQbsVersion: "1.7.1"

    references: [
        "src/imports/core/core.qbs",
        "src/demo/demo.qbs",
        "tests/tests.qbs"
    ]
}
