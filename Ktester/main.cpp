/**
* @file main.cpp
* @brief Main for test classes
* @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
* @details BSD License @details Project info http://code.google.com/p/tester-device/
*/
using namespace std;
#include <iostream>
#include "include/tester/Viewer.h"
#include <qapplication.h>






//// ==================   OPENNI AND NITE INCLUDES AND DEFINES   =================
//#include <XnOpenNI.h>
//#include <XnCppWrapper.h>
//#include <XnVHandPointContext.h>
//#include <XnVSessionManager.h>
//#include <XnVNite.h>
//#include <ni/XnTypes.h>
////#define SAMPLE_XML_PATH "src/devices/kinect/config.xml" //XML: Configuration OpenNI
//#define SAMPLE_XML_PATH "../src/devices/kinect/config.xml" //estoy en bin
//#define nullifyHandPoint(){cursor.X = -1;cursor.Y = -1;cursor.Z = -1;} //Set cursor to NULL
//// =============================================================================
//// ======================   OPENGL INCLUDES AND DEFINES   ======================
////#include <GL/glut.h>
//#define X_MAX 640				//this is how wide my window should be
//#define Y_MAX 480				//this is how long my window should be
//#define WIN_TITLE "tester-device"
//// =============================================================================
//
//// =======================   OWN INCLUDES AND DEFINES   ========================
//#include "include/tester/tasks/pointing/Experiment.h"
//#define BLOCKS_PER_EXPERIMENT 1
//// =============================================================================
//
//
//// ==========   OPENNI AND NITE GLOBALS AND CALLBACKS DEFINITION   =============
//XnStatus rc;				//to check status of various open-ni operations
//xn::Context cxt;			//context - represents the sensor (source of image / depth info)
//xn::DepthGenerator depthGen;		//will hold the depth generator node
//xn::DepthMetaData depthMapMetaData;	//will hold the meta data for the depth generator node
//int referenceDepthVal = 0;		//reference value - last pixel's depth. used in comparison
//// NITE OBJECTS
//XnVSessionManager *sessionMgr;		//this is a pointer to a session manager object		
//XnVPointControl *pointCtrl;		//this is a pointer to a point control object		
//bool inSession = false;			//this variable indicates if we're in session on not
//XnPoint3D cursor;                      	//this variable will store the coordinates of the primary hand point
////NITE Callbacks
//void XN_CALLBACK_TYPE sessionStart(const XnPoint3D& ptPosition, void* UserCxt);	//session started event callback
//void XN_CALLBACK_TYPE sessionEnd(void* UserCxt);				//session ended event callback
//void XN_CALLBACK_TYPE pointCreate(const XnVHandPointContext *pContext, const XnPoint3D &ptFocus, void *cxt);//Pointcallback
//void XN_CALLBACK_TYPE pointUpdate(const XnVHandPointContext *pContext, void *cxt);//point updated callback
//void XN_CALLBACK_TYPE pointDestroy(XnUInt32 nID, void *cxt);			//point destroyed callback
//void XN_CALLBACK_TYPE click(XnFloat fVelocity, XnFloat fAngle, void* cxt);	//Click callback
////In line functions
//inline bool isHandPointNull(){if(cursor.X == -1) return true; else return false;}       //Return true if the cursor is NULL
//// =============================================================================
//
//
////Own Globals
////Experiment exper;
//
//
//// ============================   OPENGL FUNCTIONS   ===========================
//void drawCursor(){
//    int boxSize = 50;
//    int xBox = cursor.X - boxSize/2;
//    int yBox = cursor.Y - boxSize/2;
//    glLoadIdentity();                           //set the matrix to an identity matrix
//    glOrtho(0, X_MAX, Y_MAX, 0, -1, 1);         //set the orthogonal view. -1 and 1 define the near and far clip off points along z axis
//    if(isHandPointNull() == false){             //If the cursor is set
//        glColor3f(255,255,255);
//        //Draws a cursor and a bounding box around it
//        glBegin(GL_POLYGON);
//            int xCo = cursor.X;
//            int yCo = cursor.Y;
//            int size = 2;                       //size of this square
//            glVertex3f(xCo-size,yCo-size,0);    //plot the top left corner
//            glVertex3f(xCo+size,yCo-size,0);    //plot the top right corner
//            glVertex3f(xCo+size,yCo+size,0);    //plot the bot right corner
//            glVertex3f(xCo-size,yCo+size,0);    //plot the bot left corner
//        glEnd();
//        glBegin(GL_LINES);
//            glVertex3f(xBox,yBox,0);            //top edge
//            glVertex3f(xBox+boxSize,yBox,0);
//            glVertex3f(xBox,yBox,0);            //left edge
//            glVertex3f(xBox,yBox+boxSize,0);
//            glVertex3f(xBox+boxSize,yBox,0);    //right edge
//            glVertex3f(xBox+boxSize,yBox+boxSize,0);
//            glVertex3f(xBox,yBox+boxSize,0);    //bottom edge
//            glVertex3f(xBox+boxSize,yBox+boxSize,0);
//        glEnd();
//    }
//}
//// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   OPENGL draw   ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
//void draw(){
////    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear the gl buffers
////    exper.paint();
//    
////    switch(exper.getDevice()){
////        case '1':       //Mouse
////            break;
////        case '2':       //Wiimote
////            cout<<"Wiimote"<<endl<<endl;
////            break;
////        case '3':       //Kinect
//            rc = cxt.WaitAnyUpdateAll();        //Refresh the data coming from the sensor
//            if(rc != XN_STATUS_OK){             //if the update failed
//                cout<<"Kinect error:Read failed... Quitting!"<<endl;
//                exit(0);
//            }else if(inSession){
//                sessionMgr->Update(&cxt);       //Update the session manager
//            }
//            drawCursor();
////            break;
////        case '4':       //Falcon
////            drawCursor();
////            break;
////    }
//    
//    
//    
////    glutSwapBuffers();
//}
//// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   OPENGL HANDLERS   ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
//void keyHandler(unsigned char key, int x, int y){
//    switch (key){
//        case 27:		//escape pressed
//            exit (1);
//    }
//}
//void mouseHandler(int button, int state, int x, int y){
//    if(state==1){
//        cursor.X=x;
//        cursor.Y=y;
////        exper.click(Point(x,y));//Sends the click-point to the experiment
//    }
//}
//// ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬   OPENGL INIT   ¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
//void initGraphics(int argc, char *argv[]){
////    glutInit(&argc,argv);
////    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
////    glutInitWindowSize(X_MAX,Y_MAX);
////    glutCreateWindow(WIN_TITLE);
////    glutDisplayFunc(draw);
////    glutKeyboardFunc(keyHandler);
////    glutMouseFunc(mouseHandler);
////    glutIdleFunc(draw);
////    glDisable(GL_DEPTH_TEST);
//}
//// =============================================================================
//
//// =======================   OpenNI and NITE FUNCTIONS   =======================
//int contextInit(){
//    //Context initializations go in here
//    xn::EnumerationErrors errors;								
//    rc = cxt.InitFromXmlFile(SAMPLE_XML_PATH,&errors);  //initialize the context from the xml file
//    if(rc != XN_STATUS_OK){
//        cout<<"Failed to open: "<<xnGetStatusString(rc)<<endl;  //handle error in reading from XML
//        return rc;
//    }
//    rc = cxt.FindExistingNode(XN_NODE_TYPE_DEPTH,depthGen);     //try to find the depth node from the context
//    if(rc != XN_STATUS_OK){                                     //handle error if node is not found
//        cout<<"Failed to open Depth node"<<endl;
//        return rc;
//    }
//}
//// =============================================================================
//
//
//// =================================   MAIN   ==================================
//int main(int argc,char *argv[]){
//    char device='0';
//    long id=0;
//    
//    //Set options
//    while(device!='1'&&device!='2'&&device!='3'&&device!='4'){
//        cout<<"#################################################################"<<endl;
//        cout<<"Tester Device (http://code.google.com/p/tester-device/)"<<endl<<endl;
//        cout<<"1: Mouse"<<endl;
//        cout<<"2: Wiimote"<<endl;
//        cout<<"3: Kinect"<<endl;
//        cout<<"4: Falcon"<<endl<<endl;
//        cout<<"Select the device: ";
//        cin>>device;
//    }
//    //Read the id of the participant
//    cout<<"Insert id: ";
//    cin>>id;
//    cout<<"______________________________________________________________"<<endl;
//    cout<<"______________________________________________________________"<<endl;
//    
//    
////    exper.init(BLOCKS_PER_EXPERIMENT,device,id);
//    
//    
//    switch(device){
//        case '1':
//            cout<<"Mouse selected"<<endl<<endl;
//            break;
//        case '2':
//            cout<<"Wiimote selected"<<endl<<endl;
//            break;
//        case '3':
//            cout<<"Kinect selected. Starting sensor..."<<endl;
//            //OpenNI and NITE inicialization
//            contextInit();
//            sessionMgr = new XnVSessionManager();			//session manager is created
//            rc = sessionMgr->Initialize(&cxt,"Click,Wave","RaiseHand");	//session manager is initialized 
//            if(rc!= XN_STATUS_OK){					//check if this init operation was good
//                cout<<"Session manager couldn't be initialized"<<endl;
//                //return rc;
//            }
//            sessionMgr->RegisterSession(&cxt,sessionStart,sessionEnd);  //register the callbacks for the session manager
//            pointCtrl = new XnVPointControl("Point Tracker");		//create the point control object
//            pointCtrl->RegisterPrimaryPointCreate(&cxt,pointCreate);	//register the primary point created handler
//            pointCtrl->RegisterPrimaryPointUpdate(&cxt,pointUpdate);	//register the primary point updated handler
//            pointCtrl->RegisterPrimaryPointDestroy(&cxt,pointDestroy);	//register the primary point destroyed handler
//            sessionMgr->AddListener(pointCtrl);				//make the session manager listen to the point control object
//            cout<<"Starting the experiment:."<<endl;
//            cout<<" 1. Say hello to sensor until you see the cursor."<<endl;
//            cout<<" 2. Push the green circle and then as fast as you can push the red circle."<<endl;
//            cout<<" 3. Repeat that until the system will report that the experiment ended."<<endl;
//            break;
//        case '4':
//            cout<<"Falcon selected."<<endl<<endl;
//            break;
//    }
//    
//    //Push detector
//    XnVPushDetector pushDetector;
//    pushDetector.RegisterPush(NULL, &click);
//    sessionMgr->AddListener(&pushDetector);
//    nullifyHandPoint();						//initialize the global variable to track hand points
//    
//    //init GL routine
//    initGraphics(argc,argv);					
////    glutMainLoop();
//    return 0;
//}
//
//
//// ==============================   CALLBACKS NITE   ===========================
//void XN_CALLBACK_TYPE sessionStart(const XnPoint3D& ptPosition, void* UserCxt){
//    inSession = true;
//}
//void XN_CALLBACK_TYPE sessionEnd(void* UserCxt){
//    inSession = false;
//}
////This is called only once when the hand point is detected
//void XN_CALLBACK_TYPE pointCreate(const XnVHandPointContext *pContext, const XnPoint3D &ptFocus, void *cxt){
//    XnPoint3D coords(pContext->ptPosition);
//    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);	
//}
////Any update in the hand point coordinates are
//void XN_CALLBACK_TYPE pointUpdate(const XnVHandPointContext *pContext, void *cxt){
//    XnPoint3D coords(pContext->ptPosition);
//    depthGen.ConvertRealWorldToProjective(1,&coords,&cursor);	
//}
////When the point can no longer be tracked, this event handler is invoked.
//void XN_CALLBACK_TYPE pointDestroy(XnUInt32 nID, void *cxt){
//    nullifyHandPoint();
//}
//void XN_CALLBACK_TYPE click(XnFloat fVelocity, XnFloat fAngle, void* cxt){
////    exper.click(Point(cursor.X,cursor.Y));
//}
//// =============================================================================
//





int main(int argc, char** argv){
    // Read command lines arguments.
    QApplication application(argc,argv);
    // Instantiate the viewer.
    Viewer viewer;
#if QT_VERSION < 0x040000
    // Set the viewer as the application main widget.
    //application.setMainWidget(&viewer);
#else
    viewer.setWindowTitle("simpleViewer");
#endif
    // Make the viewer window visible on screen.
    viewer.show();
    // Run main loop.
    return application.exec();
}