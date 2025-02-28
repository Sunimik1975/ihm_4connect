QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Ruta relativa para encontrar el archivo .lib
LIBS += -L$$PWD/lib/ -lConnect4Lib

# Ruta relativa para encontrar los archivos de cabecera
INCLUDEPATH += $$PWD/lib/

SOURCES += \
    RegisterWindow.cpp \
    connect4.cpp \
    gameboard.cpp \
    iconcombobox.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_principal.cpp \
    rankingwindow.cpp \
    rounds.cpp \
    staticsplayer.cpp

HEADERS += \
    RegisterWindow.h \
    connect4.h \
    gameboard.h \
    iconcombobox.h \
    mainwindow.h \
    menu_principal.h \
    rankingwindow.h \
    rounds.h \
    staticsplayer.h

FORMS += \
    RegisterWindow.ui \
    gameboard.ui \
    mainwindow.ui \
    menu_principal.ui \
    rankingwindow.ui \
    rounds.ui \
    staticsplayer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    avatars/chica.jpg \
    avatars/default.png \
    avatars/zorro.jpg

RESOURCES += \
    avatar.qrc
