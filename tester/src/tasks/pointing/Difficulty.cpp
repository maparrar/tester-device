/**
 * @file Difficulty.cpp
 * @brief Difficulty Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../../include/tester/tasks/pointing/Difficulty.h"
Difficulty::Difficulty(){
    width=0;
    distance=0;
}
Difficulty::Difficulty(int _width,int _distance){
    width=_width;
    distance=_distance;
}
Difficulty::~Difficulty(){}
void Difficulty::setWidth(int _width){
    width=_width;
}
int Difficulty::getWidth(){
    return width;
}
void Difficulty::setDistance(int _distance){
    distance=_distance;
}
int Difficulty::getDistance(){
    return distance;
}