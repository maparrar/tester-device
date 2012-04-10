/**
 * @file FalconMouse.cpp
 * @brief FalconMouse Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../../include/tester/devices/falcon/FalconMouse.h"
#include <iostream>
FalconMouse::FalconMouse(){}
FalconMouse::~FalconMouse(){}
//---------------------------------------------------------------------------
// Methods
//---------------------------------------------------------------------------
void FalconMouse::addOptions(int value){
    FalconCLIBase::addOptions(value);
}
bool FalconMouse::parseOptions(int argc, char** argv){
    if(!FalconCLIBase::parseOptions(argc, argv)) return false;
    return true;
}
void FalconMouse::init(){
    m_falconDevice->setFalconKinematic<FalconKinematicStamper>();
    m_falconDevice->setFalconGrip<FalconGripFourButton>();
    grip = m_falconDevice->getFalconGrip();
    height = 600;
    width = 800;
}
double FalconMouse::getX(){
    if(m_falconDevice->runIOLoop()){
        pos = m_falconDevice->getPosition();
        posX=((pos[0] + .06) / .12) * width;
        return posX;
    }else{
        return posX;
    }
}
double FalconMouse::getY(){
    if(m_falconDevice->runIOLoop()){
        pos = m_falconDevice->getPosition();
        posY=(((.12 - (pos[1] + .06)) / .12) * height);
        return posY;
    }else{
        return posY;
    }
}
Point FalconMouse::getPos(){
    if(m_falconDevice->runIOLoop()){
        pos = m_falconDevice->getPosition();
        posX=((pos[0] + .06) / .12) * width;
        posY=(((.12 - (pos[1] + .06)) / .12) * height);
    }
    Point p(posX,posY);
    return p;
}
bool FalconMouse::getClick(int button){
    return grip->getDigitalInput(button);
}
void FalconMouse::setForce(double x,double y,double z){
    if(m_falconDevice->runIOLoop()){
        force[0]=x;
        force[1]=y;
        force[2]=z;
    }
    m_falconDevice->setForce(force);
}
