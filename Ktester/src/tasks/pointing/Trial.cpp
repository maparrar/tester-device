/**
 * @file Trial.cpp
 * @brief Trial Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
using namespace std;
#include "../../../include/tester/tasks/pointing/Trial.h"
#include <iostream>
Trial::Trial(){
    state=0;
    float radiusC1=20;
    c1=Circle(Point(350,100),radiusC1,QColor(0,255,0,255));
    c2=Circle(Point(200,300),radiusC1,QColor(255,0,0,255));
    calculateId();
}
Trial::Trial(Point center,float width,float distance,float angle,float raduisC1){
    state=0;
    W=width;
    D=distance;
    int xC1=center.getX()+((distance/2)*cos(angle));
    int yC1=center.getY()+((distance/2)*sin(angle));
    int xC2=center.getX()-((distance/2)*cos(angle));
    int yC2=center.getY()-((distance/2)*sin(angle));
    c1=Circle(Point(xC1,yC1),raduisC1,QColor(0,255,0,255));
    c2=Circle(Point(xC2,yC2),width/2,QColor(255,0,0,255));
    calculateId();
}
void Trial::calculateId(){
    //W=(float)(c2.getRadius()*2);
    //D=c1.distance(c2);
    ID=log((D/W)+1)/log(2);     //By properties of logarithms log2(x)=logk(x)/logk(2) where k is real positive different of 1
}
Trial::~Trial(){}
//---------------------------------------------------------------------------
// Set and Get
//---------------------------------------------------------------------------
void Trial::setState(int _state){
    state=_state;
}
int Trial::getState(){
    return state;
}
float Trial::getW(){
    return W;
}
float Trial::getD(){
    return D;
}
long Trial::getMT(){
    return MT;
}
float Trial::getID(){
    return ID;
}
float Trial::getTP(){
    return ID/((float)MT/1000.0);
}
float Trial::getDr(){
    return start.distance(stop);
}
Point Trial::getStart(){
    return start;
}
Point Trial::getStop(){
    return stop;
}
//--------------------------------------------------------------------------- 
// Methods
//---------------------------------------------------------------------------
void Trial::init(){
    state=1;
}
void Trial::paint(){
    //cout<<"[trial]> paint()"<<endl;
    if(state==1){
        c1.paint();
    }else if(state==2){
        c2.paint();
    }
}
void Trial::click(Point p){
    if(c1.inside(p)){
        state=2;
        timer.start();
        start=p;
    }else if(c2.inside(p)){
        state=3;
        MT=timer.elapsed();
        stop=p;
    }
}