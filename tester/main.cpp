/**
* @file main.cpp
* @brief Main for test classes
* @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
* @details BSD License @details Project info http://code.google.com/p/tester-device/
*/
using namespace std;
#include <iostream>
#include "include/tester/Viewer.h"
#include <qapplication.h>

int main(int argc, char** argv){
    // Read command lines arguments.
    QApplication application(argc,argv);
    // Instantiate the viewer.
    Viewer viewer;
#if QT_VERSION < 0x040000
    // Set the viewer as the application main widget.
    //application.setMainWidget(&viewer);
#else
    viewer.setWindowTitle("simpleViewer");
#endif
    // Make the viewer window visible on screen.
    viewer.show();
    // Run main loop.
    return application.exec();
}