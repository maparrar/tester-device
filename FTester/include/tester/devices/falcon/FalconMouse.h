/**
 * @file FalconMouse.h
 * @brief Header for class FalconMouse.
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef FALCONMOUSE_H
#define FALCONMOUSE_H
#include <iostream>
#include <string>
#include <csignal>
#include <ctime>
#include <boost/program_options.hpp>
#include "falcon/core/FalconDevice.h"
#include "falcon/firmware/FalconFirmwareNovintSDK.h"
#include "falcon/grip/FalconGripFourButton.h"
#include "falcon/kinematic/FalconKinematicStamper.h"
#include "falcon/util/FalconCLIBase.h"
#include "falcon/util/FalconDeviceBoostThread.h"
#include "../../util/Point.h"
using namespace libnifalcon;
namespace po = boost::program_options;
/**
 * @class FalconMouse
 * FalconMouse allows use Novint's Falcon like a standard mouse. Allows capture the Falcon sphere and is mapped to the cursor. Also provides a method to set force and capture the four buttons.
 * FalconMouse class is based on the example FalconMouse of the library libnifalcon created by Kile Machulis (http://qdot.github.com/libnifalcon/).
 */
class FalconMouse:public FalconCLIBase{
private:
    boost::shared_ptr<FalconGrip> grip; 	//Button handdle
    boost::array<double, 3> force;		//Set force to the Falcon
    boost::array<double, 3> pos;
    int height;
    int width;
    double posX;
    double posY;
public:
    FalconMouse();
    virtual ~FalconMouse();
    void addOptions(int value);
    bool parseOptions(int argc, char** argv);
    void runMouseLoop();
    void init(int _width, int _height);
    double getX();
    double getY();
    /**
     * Returns the position of the Falcon's sphere
     * @return Point p with the sphere position
     */
    Point getPos();
    /**
     * Shows if the button is pressed
     * @param button a number between 0 and 3, it represents one of the Falcon's buttons
     * @return true if the button is pressed, false in otherwise
     */
    bool getClick(int button);
    /**
     * Sets the force vector of the Falcon
     * @param x force in x-axis (-3,3)
     * @param y force in y-axis (-3,3)
     * @param z force in z-axis (-3,3)
     */
    void setForce(double x,double y,double z);
};
#endif /* FALCONMOUSE_H */
