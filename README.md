## Cute Settings

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![GitHub release](https://img.shields.io/github/release/tim-sueberkrueb/cute-settings.svg)](https://github.com/tim-sueberkrueb/cute-settings/releases)
[![GitHub issues](https://img.shields.io/github/issues/tim-sueberkrueb/cute-settings.svg)](https://github.com/tim-sueberkrueb/cute-settings/issues)
[![Maintained](https://img.shields.io/maintenance/yes/2017.svg)](https://github.com/tim-sueberkrueb/cute-settings/commits/develop)

Simple settings library for QML applications.

### Dependencies
* Qt >= 5.7 with at least the following modules is required:
    * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
    * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)
    * [qtquickcontrols2](http://code.qt.io/cgit/qt/qtquickcontrols2.git/) (Demo only)

Note that while the demo requires Qt >= 5.7, the core library is likely to work with older Qt 5 versions (untested).

### Build

Cute Settings uses [Qbs](http://doc.qt.io/qbs/) as build system.

If you haven't already, start by setting up a `qt5` profile for `qbs`:
```sh
qbs setup-toolchains --type gcc /usr/bin/g++ gcc
qbs setup-qt $(which qmake) qt5 # make sure that qmake is in PATH
qbs config profiles.qt5.baseProfile gcc
```

Then, from the root of the repository, run:
```sh
qbs -d build -j $(nproc) profile:qt5 # use sudo if necessary
```

To the `qbs` call above you can append additional configuration parameters:
```sh
... qbs.installRoot:/install/root # e.g. /
... qbs.installPrefix:path/to/install # e.g. usr
```

### License
Licensed under the terms of the MIT license.

