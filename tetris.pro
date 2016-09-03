TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lutil.cpp \
    app.cpp \
    tetrimino.cpp \
    block.cpp \
    board.cpp \
    shape.cpp

HEADERS += \
    lutil.h \
    app.h \
    tetrimino.h \
    block.h \
    board.h \
    consts.h \
    color.h \
    shape.h

LIBS += -lglut
LIBS += -lGL
LIBS += -lGLU

QMAKE_CXXFLAGS += -lGL
QMAKE_CXXFLAGS += -lGLU
QMAKE_CXXFLAGS += -lglut
