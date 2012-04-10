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
void FalconMouse::runMouseLoop(){
//    m_falconDevice->setFalconKinematic<FalconKinematicStamper>();
//    //APLICACIÓN DE FUERZAS: FUNCIONANDO
//    boost::array<double, 3> fuerza;
//    fuerza[0]=2.0;
//    fuerza[1]=2.0;
//    fuerza[2]=2.0;
//    m_falconDevice->setForce(fuerza);
//    //MANEJO DE LOS BOTONES: FUNCIONANDO
//    m_falconDevice->setFalconGrip<FalconGripFourButton>();
//    boost::shared_ptr<FalconGrip> grip = m_falconDevice->getFalconGrip();
//    //CAPTURA DE POSICIÓN: FUNCIONANDO
//    boost::array<double, 3> d;
//    int y = 0;
//    int x = 0;
//    int width = 800;
//    int height = 600;
//    while(1){
//        //This math doesn't map the workspace to the window properly yet.
//        if(!m_falconDevice->runIOLoop())
//                continue;
//        d = m_falconDevice->getPosition();
//        x = ((d[0] + .06) / .12) * width;
//        y = (((.12 - (d[1] + .06)) / .12) * height);
//        std::cout<<"Botones: [b1="<<grip->getDigitalInput(0)<<"][b2="<<grip->getDigitalInput(1)<<"][b3="<<grip->getDigitalInput(2)<<"][b4="<<grip->getDigitalInput(3)<<"]"<<"  -  pos:["<<x<<","<<y<<"]"<<std::endl;
//    }
}
void FalconMouse::init(int _width, int _height){
    m_falconDevice->setFalconKinematic<FalconKinematicStamper>();
    m_falconDevice->setFalconGrip<FalconGripFourButton>();
    grip = m_falconDevice->getFalconGrip();
    height = _height;
    width = _width;
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
//        std::cout<<"En loop"<<std::endl;
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
