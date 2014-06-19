TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += "/usr/include/mysql"
INCLUDEPATH += "/usr/include/mysql++"

LIBS += -L/usr/lib/
LIBS += -lmysqlpp -lmysqlclient
