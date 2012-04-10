/**
 * @file Circle.h
 * @brief Header for class Circle
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

#include <QGLViewer/qglviewer.h>
#include <QColor>
/**
 * @class Circle
 * Circle allows create and manipulate circles based in Point in the tester-device.
 */
class Circle: public Point{
private:
    bool visible;       //Indicates if the circle is displayed
    double radius;
    QColor color;      //Circle color
public:
    Circle();
    Circle(Point p,double r);
    Circle(Point p,double r,QColor _color1);
    Circle(Point p,double r,QColor _color1,QColor _color2);
    Circle(Point p,double r,QColor _color1,QColor _color2,QColor _color3);
    ~Circle();
    void setVisible(bool _activo);
    bool getVisible();
    void setRadius(double _r);
    double getRadius();
    /**
     * Returns the Circle area
     * @return area of Circle
     */
    virtual double area();
    /**
     * Returns the Circle perimeter
     * @return perimeter of Circle
     */
    virtual double perimeter();
    /**
     * Paints the Circle using OpenGL
     */
    void paint();
    /**
     * Returns if a Point p is inside of the Circle
     * @param p Point to evaluate
     * @return true if the Point p is inside of Circle, false in otherwise
     */
    bool inside(Point p); 
}; 
#endif /* CIRCLE_H */