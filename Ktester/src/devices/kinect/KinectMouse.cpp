/**
 * @file Circle.cpp
 * @brief Circle Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../../include/tester/devices/kinect/KinectMouse.h"
//#include <GL/glut.h>

#define SAMPLE_XML_PATH "../src/devices/kinect/config.xml" 

// ==============================   CALLBACKS NITE   ===========================
void XN_CALLBACK_TYPE sessionStart(const XnPoint3D& ptPosition, void* UserCxt){
    cout<<"kinect::empieza sesion: "<<endl;
//    inSession = true;
    KinectMouse::startSession();
}
void XN_CALLBACK_TYPE sessionEnd(void* UserCxt){
//    inSession = false;
    KinectMouse::endSession();
}
//This is called only once when the hand point is detected
void XN_CALLBACK_TYPE pointCreate(const XnVHandPointContext *pContext, const XnPoint3D &ptFocus, void *cxt){
    cout<<"kinect::crea un punto"<<endl;
    XnPoint3D coords(pContext->ptPosition);
//    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);	
}
//Any update in the hand point coordinates are
void XN_CALLBACK_TYPE pointUpdate(const XnVHandPointContext *pContext, void *cxt){
//    cout<<"kinect::actualiza el punto"<<endl;
    XnPoint3D coords(pContext->ptPosition);
    
//    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);
    KinectMouse::setCoords(coords);
}
//When the point can no longer be tracked, this event handler is invoked.
void XN_CALLBACK_TYPE pointDestroy(XnUInt32 nID, void *cxt){
//    nullifyHandPoint();
}
void XN_CALLBACK_TYPE click(XnFloat fVelocity, XnFloat fAngle, void* cxt){
//    exper.click(Point(cursor.X,cursor.Y));
}


KinectMouse::KinectMouse() {
}
KinectMouse::~KinectMouse() {
}

bool KinectMouse::inSession=false;
XnPoint3D KinectMouse::coords;

void KinectMouse::init(int _width, int _height){
    width=_width;
    height=_height;
    
    cout<<"Iniciando KinectMouse::init"<<endl;
    
    referenceDepthVal = 0;		//reference value - last pixel's depth. used in comparison
    inSession = false;
    
     //OpenNI and NITE inicialization
//            contextInit();
    xn::EnumerationErrors errors;
    rc = cxt.InitFromXmlFile(SAMPLE_XML_PATH,&errors);          //initialize the context from the xml file
    
    if(rc != XN_STATUS_OK){
        printf("Failed to open:%s", xnGetStatusString(rc));     //handle error in reading from XML
        //return rc;
    }
    
    rc = cxt.FindExistingNode(XN_NODE_TYPE_DEPTH,depthGen);     //try to find the depth node from the context
    if(rc != XN_STATUS_OK){                                     //handle error if node is not found
        printf("Failed to open Depth node!");
        //return rc;
    }
    
    cout<<endl<<">>> MARKER 0"<<endl;
    
    sessionMgr = new XnVSessionManager();			//session manager is created
    rc = sessionMgr->Initialize(&cxt,"Click,Wave","RaiseHand");	//session manager is initialized 
    if(rc!= XN_STATUS_OK){					//check if this init operation was good
        cout<<"Session manager couldn't be initialized"<<endl;
        //return rc;
    }
    
    cout<<endl<<">>> MARKER 1"<<endl;
    
    sessionMgr->RegisterSession(&cxt,sessionStart,sessionEnd);  //register the callbacks for the session manager
    pointCtrl = new XnVPointControl("Point Tracker");		//create the point control object
    pointCtrl->RegisterPrimaryPointCreate(&cxt,pointCreate);	//register the primary point created handler
    pointCtrl->RegisterPrimaryPointUpdate(&cxt,pointUpdate);	//register the primary point updated handler
    pointCtrl->RegisterPrimaryPointDestroy(&cxt,pointDestroy);	//register the primary point destroyed handler
    sessionMgr->AddListener(pointCtrl);				//make the session manager listen to the point control object
    //Push detector
    XnVPushDetector pushDetector;
    pushDetector.RegisterPush(NULL,&click);
    sessionMgr->AddListener(&pushDetector);
    nullifyHandPoint();						//initialize the global variable to track hand points
    nullifyPClick();						//initialize the global variable to track hand points
    
    cout<<endl<<">>> MARKER 5"<<endl;
}
void KinectMouse::draw(){
    rc = cxt.WaitAnyUpdateAll();                //first update the context - refresh the depth/image data coming from the sensor
    if(rc != XN_STATUS_OK){                     //if the update failed, i.e. couldn't be read
        cout<<"ERROR:Read failed... Quitting!"<<endl;//print error message
    }else if(KinectMouse::getSession()){
        sessionMgr->Update(&cxt);               //NEW ADDITION - update the session manager
        depthGen.GetMetaData(depthMapMetaData); //grab the depth map meta data
        long xSize = depthMapMetaData.XRes();   //this meta data will give us the true width
        long ySize = depthMapMetaData.YRes();   //and height of the scene
        const XnDepthPixel* depthMapData;       //this array will contain the value of depth of each pixel in depth map
        depthMapData = depthMapMetaData.Data(); //this will grab the depth values and store it into the array
        updateCursor(xSize,ySize);
    }
}
void KinectMouse::nullifyHandPoint(){
    cursor.X = -1;
    cursor.Y = -1;
    cursor.Z = -1;
    cursorAnt.X = -1;
    cursorAnt.Y = -1;
    cursorAnt.Z = -1;
}
void KinectMouse::nullifyPClick(){
    pClick.X = -1;
    pClick.Y = -1;
    pClick.Z = -1;
}
void KinectMouse::updateCursor(long resX,long resY){
    cursorAnt.X=cursor.X;
    cursorAnt.Y=cursor.Y;
    cursorAnt.Z=cursor.Z;
    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);
    cursor.X=cursor.X*((float)width/(float)resX);
    cursor.Y=cursor.Y*((float)height/(float)resY);
    if((cursorAnt.Z-cursor.Z)>30){
        pClick.X = cursorAnt.X ;
        pClick.Y = cursorAnt.Y ;
        pClick.Z = cursor.Z ;
    }else{
        nullifyPClick();
    }
}