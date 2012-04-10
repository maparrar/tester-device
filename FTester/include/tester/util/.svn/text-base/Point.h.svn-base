/**
 * @file Point.h
 * @brief Header for class Point
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef POINT_H
#define POINT_H
#include "math.h" 
/**
 * @class Point
 * Point allows create and manipulate points in the tester-device.
 */
class Point{
private:
    double x;
    double y;
public:
    ///Constructor
    Point();
    Point(int a,int b);
    Point(double a,double b);
    virtual ~Point();
    /**
     * Change the point coordinates adding x=x+a and y=y+b
     * @param a adds a to actual position in x-axis
     * @param b adds b to actual position in y-axis
     */
    void move(double a,double b);
    /**
     * Return the distance between this point and the parameter pto
     * @param pto point to calculate distance between this and pto
     * @return double with the distance between this and pto
     */
    double distance(Point pto);
    void setX(double _x);
    void setY(double _y);
    double getX();
    double getY();
};
#endif /* POINT_H */