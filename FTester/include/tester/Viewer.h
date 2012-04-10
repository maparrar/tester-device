/**
 * @file Viewer.h
 * @brief Header for class Viewer
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */

#include <QGLViewer/qglviewer.h>
#include <qcolor.h>
#include "devices/falcon/FalconMouse.h"

class Viewer : public QGLViewer
{
public :
    void addMessage(QString message);
    void addMessage(QString message,float n);
    void addMessage(QString message,float n,int index);
    void drawCursor();
    void setVars(int argc, char** argv);
protected :
    virtual void init();
    virtual void draw();
    virtual void animate();
    virtual void postSelection(const QPoint& point);
private :
    static const int maxMessages=50;     //Max number of messages to display
    int countMessages;                   //Counter of messages to display
    QString messages[maxMessages];       //List of messages to display in the window
    qglviewer::Vec orig, dir, selectedPoint;
    Point cursor;
    void displayMessages();
    void thanks();
};