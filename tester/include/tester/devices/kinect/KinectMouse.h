/**
 * @file KinectMouse.h
 * @brief Header for class KinectMouse.
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef KINECTMOUSE_H
#define KINECTMOUSE_H


#include <iostream>
#include <stdio.h>
#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <XnVHandPointContext.h>
#include <XnVSessionManager.h>
#include <XnVNite.h>
#include <ni/XnTypes.h>


using namespace xn;

/**
 * @class KinectMouse
 * KinectMouse allows use the Microsoft Kinect like a mouse. Is based in OpenNi framework, see (http://www.openni.org/).
 * 
 * NOTE: This class is unused because the callbacks didn't work
 */
class KinectMouse{
private:
    XnStatus rc;				//to check status of various open-ni reld operations
    Context cxt;                            //context - represents the sensor (source of image / depth info)
    DepthGenerator depthGen;		//will hold the depth generator node
    DepthMetaData depthMapMetaData;         //will hold the meta data for the depth generator node
    int referenceDepthVal;                  //reference value - last pixel's depth. used in comparison
    //                                   NITE OBJECTS  //
    XnVSessionManager *sessionMgr;		//this is a pointer to a session manager object		
    XnVPointControl *pointCtrl;                 //this is a pointer to a point control object		
    bool inSession;			//this variable indicates if we're in session on not
    XnPoint3D cursor;                      	//this variable will store the coordinates of the primary hand point
    
    int height;                                 //height of the screen
    int width;                                  //wide of the screen
    //double posX;
    //double posY;
public:
    KinectMouse();
    virtual ~KinectMouse();
    
    void init();
    void draw();
    bool isHandPointNull();
    
    /**
     * Callbacks for NITE
     */
    void XN_CALLBACK_TYPE sessionStart(const XnPoint3D& ptPosition, void* UserCxt);	//session started event callback
    void XN_CALLBACK_TYPE sessionEnd(void* UserCxt);                                    //session ended event callback
    void XN_CALLBACK_TYPE pointCreate(const XnVHandPointContext *pContext, const XnPoint3D &ptFocus, void *cxt);//Pointcallback
    void XN_CALLBACK_TYPE pointUpdate(const XnVHandPointContext *pContext, void *cxt);  //point updated callback
    void XN_CALLBACK_TYPE pointDestroy(XnUInt32 nID, void *cxt);			//point destroyed callback
    void XN_CALLBACK_TYPE click(XnFloat fVelocity, XnFloat fAngle, void* cxt);          //Click callback
    
};
#endif /* KINECTMOUSE_H */
