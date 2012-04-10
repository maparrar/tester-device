TARGET = ftester
CONFIG *= qt opengl release
QT *= opengl xml

INCLUDEPATH += /usr/include/
INCLUDEPATH += /usr/local/include/
INCLUDEPATH += /usr/local/include/falcon/

HEADERS += ../include/tester/Viewer.h
HEADERS += ../include/tester/devices/falcon/FalconMouse.h
HEADERS += ../include/tester/tasks/pointing/Difficulty.h
HEADERS += ../include/tester/tasks/pointing/Trial.h
HEADERS += ../include/tester/tasks/pointing/Block.h
HEADERS += ../include/tester/tasks/pointing/Experiment.h
HEADERS += ../include/tester/util/Point.h
HEADERS += ../include/tester/util/Circle.h

SOURCES += ../main.cpp
SOURCES += ../src/Viewer.cpp
SOURCES += ../src/devices/falcon/FalconMouse.cpp
SOURCES += ../src/tasks/pointing/Difficulty.cpp
SOURCES += ../src/tasks/pointing/Trial.cpp
SOURCES += ../src/tasks/pointing/Block.cpp
SOURCES += ../src/tasks/pointing/Experiment.cpp
SOURCES += ../src/util/Point.cpp
SOURCES += ../src/util/Circle.cpp

LIBS += -lQGLViewer
LIBS += -lnifalcon
LIBS += -lnifalcon_cli_base
