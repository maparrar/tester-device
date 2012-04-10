/**
 * @file Point.cpp
 * @brief Point Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../include/tester/util/Point.h"
Point::Point(){
    x=0;
    y=0; 
}
Point::Point(int a,int b){ 
    x=(double)a; 
    y=(double)b; 
}
Point::Point(double a,double b){ 
    x=a; 
    y=b; 
}
Point::~Point(){}
void Point::move(double a,double b){
    x+=a;
    y+=b;
}
double Point::distance(Point pto){ 
    return(sqrt(pow(x-pto.x,2)+pow(y-pto.y,2)));
}
void Point::setX(double _x){ 
    x=_x;
}
void Point::setY(double _y){ 
    y=_y;
}
double Point::getX(){
    return x;
}
double Point::getY(){
    return y;
}