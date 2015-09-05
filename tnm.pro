#-------------------------------------------------
#
# Project created by QtCreator 2014-02-08T16:35:08
#
#-------------------------------------------------

QT       += core  sql qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tnm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    database.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/res/values-fr/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-et/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-nb/strings.xml \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/AndroidManifest.xml \
    android/version.xml \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    build/tnmstaging \
    android/assets/database/tnmstaging \
    #StageBox.qml \
    qml/Launcher.qml \
    qml/TNM.qml

include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

android {
    folder_01.source = database
    folder_01.target = .
    DEPLOYMENTFOLDERS = folder_01
}

deployment.files += tnmstaging
deployment.path = /assets/database
INSTALLS += deployment
RESOURCES += \
    resources.qrc
#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    qml/SideMenu.qml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
