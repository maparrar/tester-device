/**
 * @file Circle.cpp
 * @brief Circle Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../include/tester/util/Circle.h"

Circle::Circle():Point(){
    visible=true;
    radius=10;
    color=QColor(255,255,255,255);
}
Circle::Circle(Point p,double r):Point(p){
    visible=true;
    radius=r;
    color=QColor(255,255,255,255);
}
Circle::Circle(Point p,double r,QColor _color):Point(p){
    visible=true;
    radius=r;
    color=_color;
}
Circle::~Circle(){}
void Circle::setVisible(bool _visible){ 
    visible=_visible; 
}
bool Circle::getVisible(){ 
    return visible ; 
}
void Circle::setRadius(double _r){ 
    radius=_r; 
}
double Circle::getRadius(){ 
    return(radius) ; 
}
double Circle::area(){ 
    const double PI=3.1514;
    return(PI*pow(radius,2)); 
}
double Circle::perimeter() { 
    const double PI=3.1514 ; 
    return(2*PI*radius) ; 
}
//Print a circle in the screen
void Circle::paint(){
    glColor3f(color.red(),color.green(),color.blue());
    if(visible){
        glBegin(GL_TRIANGLE_FAN);
        for (int angle=0; angle<365; angle=angle+5){
            float angle_radians = angle * (float)3.14159 / (float)180;
            float posX = getX() + radius * (float)cos(angle_radians);
            float posY = getY() + radius * (float)sin(angle_radians);
            glVertex2f(posX,posY);
        }
        glEnd();
    }
}
//True if the point is inside of circle
bool Circle::inside(Point p){
    float dist=sqrt(pow(p.getX()-getX(),2)+pow(p.getY()-getY(),2));
    if(dist<radius){
        return true;
    }else{
        return false;
    }
}