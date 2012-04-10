/**
 * @file Circle.cpp
 * @brief Circle Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#include "../../../include/tester/devices/kinect/KinectMouse.h"
#include <GL/glut.h>

#define SAMPLE_XML_PATH "SamplesConfig.xml"                     //XML with OpenNI configuration
#define nullifyHandPoint(){cursor.X = -1;cursor.Y = -1;cursor.Z = -1;}

KinectMouse::KinectMouse() {
}
KinectMouse::~KinectMouse() {
}


void KinectMouse::init(){
    referenceDepthVal=0;
    inSession=false;
    
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

    //-------------------- Init Nite objects -----------------------
    sessionMgr = new XnVSessionManager();			//session manager is created
    rc = sessionMgr->Initialize(&cxt,"Click,Wave","RaiseHand");	//session manager is initialized 
    if(rc!= XN_STATUS_OK){					//check if this init operation was good
        printf("Session manager couldn't be initialized");
        //return rc;
    }
    sessionMgr->RegisterSession(&cxt,sessionStart,sessionEnd);  //register the callbacks for the session manager

    pointCtrl = new XnVPointControl("Point Tracker");		//create the point control object
    
    
    pointCtrl->RegisterPrimaryPointCreate(&cxt,pointCreate);	//register the primary point created handler
    
    pointCtrl->RegisterPrimaryPointUpdate(&cxt,pointUpdate);	//register the primary point updated handler
    pointCtrl->RegisterPrimaryPointDestroy(&cxt,pointDestroy);	//register the primary point destroyed handler
    
    //Se agrega el detector de Presión
    XnVPushDetector pushDetector;
    pushDetector.RegisterPush(NULL, &click);
    sessionMgr->AddListener(&pushDetector);
    
    sessionMgr->AddListener(pointCtrl);				//make the session manager listen to the point control object
    nullifyHandPoint();						//initialize the global variable to track hand points

}




void KinectMouse::draw(){
    rc = cxt.WaitAnyUpdateAll();                //first update the context - refresh the depth/image data coming from the sensor
    if(rc != XN_STATUS_OK){                     //if the update failed, i.e. couldn't be read
        printf("\nERROR:Read failed... Quitting!\n");//print error message
        exit(0);                                //exit the program
    }else if(inSession){
        sessionMgr->Update(&cxt);               //NEW ADDITION - update the session manager
        depthGen.GetMetaData(depthMapMetaData); //grab the depth map meta data
        long xSize = depthMapMetaData.XRes();   //this meta data will give us the true width
        long ySize = depthMapMetaData.YRes();   //and height of the scene
        long totalSize = xSize * ySize;         //total size of the depth map is gotten this way
        const XnDepthPixel* depthMapData;       //this array will contain the value of depth of each pixel in depth map
        depthMapData = depthMapMetaData.Data(); //this will grab the depth values and store it into the array

        glLoadIdentity();                       //set the matrix to an identity matrix
        glOrtho(0, xSize, ySize, 0, -1, 1);     //set the orthogonal view. -1 and 1 define the near and far clip off points along z axis*/
	

	glLoadIdentity();                       //set the matrix to an identity matrix
	glOrtho(0, 640, 480, 0, -1, 1);     //set the orthogonal view. -1 and 1 define the near and far clip off points along z axis

        /********************************* Dibuja la mano ***************************************/

        if(isHandPointNull() == false){
          
	    glColor3f(255,255,255);
            glBegin(GL_POLYGON);
            int xCo = cursor.X;
            int yCo = cursor.Y;
            int size = 2;                       //size of this square
            glVertex3f(xCo-size,yCo-size,0);    //plot the top left corner
            glVertex3f(xCo+size,yCo-size,0);    //plot the top right corner
            glVertex3f(xCo+size,yCo+size,0);    //plot the bot right corner
            glVertex3f(xCo-size,yCo+size,0);    //plot the bot left corner
            glEnd();                            //stop drawing the polygon

            //draws a bounding box around the hand using lines
            int boxSize = 50;
            int xBox = cursor.X - boxSize/2;
            int yBox = cursor.Y - boxSize/2;

            glBegin(GL_LINES);
            glVertex3f(xBox,yBox,0);            //top edge
            glVertex3f(xBox+boxSize,yBox,0);

            glVertex3f(xBox,yBox,0);            //left edge
            glVertex3f(xBox,yBox+boxSize,0);

            glVertex3f(xBox+boxSize,yBox,0);    //right edge
            glVertex3f(xBox+boxSize,yBox+boxSize,0);

            glVertex3f(xBox,yBox+boxSize,0);    //bottom edge
            glVertex3f(xBox+boxSize,yBox+boxSize,0);
            glEnd();
        }
    }

    glutSwapBuffers();				//for double buffering
}




bool KinectMouse::isHandPointNull(){
	if(cursor.X == -1){
            return true;
        }else{
            return false;
        }
}

/************************************ CALLBACKS NITE ********************************/

/**********************************************************************************
Session started event handler. Session manager calls this when the session begins
**********************************************************************************/
void XN_CALLBACK_TYPE KinectMouse::sessionStart(const XnPoint3D& ptPosition, void* UserCxt){
    inSession = true;
//    printf("\nin session");
}

/**********************************************************************************
session end event handler. Session manager calls this when session ends
**********************************************************************************/
void XN_CALLBACK_TYPE KinectMouse::sessionEnd(void* UserCxt){
    inSession = false;
//    printf("\nnot in session");
}

/**********************************************************************************
point created event handler. this is called when the pointControl detects the creation
of the hand point. This is called only once when the hand point is detected
**********************************************************************************/
void XN_CALLBACK_TYPE KinectMouse::pointCreate(const XnVHandPointContext *pContext, const XnPoint3D &ptFocus, void *cxt){
    XnPoint3D coords(pContext->ptPosition);
    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);	
}
/**********************************************************************************
Following the point created method, any update in the hand point coordinates are 
reflected through this event handler
**********************************************************************************/
void XN_CALLBACK_TYPE KinectMouse::pointUpdate(const XnVHandPointContext *pContext, void *cxt){
    XnPoint3D coords(pContext->ptPosition);
    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);	
}
/**********************************************************************************
when the point can no longer be tracked, this event handler is invoked. Here we 
nullify the hand point variable 
**********************************************************************************/
void XN_CALLBACK_TYPE KinectMouse::pointDestroy(XnUInt32 nID, void *cxt){
    nullifyHandPoint();
//    printf("\nDead");
}

void XN_CALLBACK_TYPE KinectMouse::click(XnFloat fVelocity, XnFloat fAngle, void* cxt){
    //exper.click(Punto(cursor.X,cursor.Y));
    std::cout<<"point: "<<cursor.X<<","<<cursor.Y<<std::endl;
}