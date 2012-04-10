TARGET = ktester
CONFIG *= qt opengl release
QT *= opengl xml

INCLUDEPATH += /usr/include/
INCLUDEPATH += /usr/include/ni/
INCLUDEPATH += /usr/include/nite/
INCLUDEPATH += /usr/local/include/

HEADERS += ../include/tester/Viewer.h
HEADERS += ../include/tester/devices/kinect/KinectMouse.h
HEADERS += ../include/tester/tasks/pointing/Difficulty.h
HEADERS += ../include/tester/tasks/pointing/Trial.h
HEADERS += ../include/tester/tasks/pointing/Block.h
HEADERS += ../include/tester/tasks/pointing/Experiment.h
HEADERS += ../include/tester/util/Point.h
HEADERS += ../include/tester/util/Circle.h

SOURCES += ../main.cpp
SOURCES += ../src/Viewer.cpp
SOURCES += ../src/devices/kinect/KinectMouse.cpp
SOURCES += ../src/tasks/pointing/Difficulty.cpp
SOURCES += ../src/tasks/pointing/Trial.cpp
SOURCES += ../src/tasks/pointing/Block.cpp
SOURCES += ../src/tasks/pointing/Experiment.cpp
SOURCES += ../src/util/Point.cpp
SOURCES += ../src/util/Circle.cpp

LIBS += -lQGLViewer
LIBS += -lOpenNI
LIBS += -lXnVNite_1_5_0