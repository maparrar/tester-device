/**
 * @file Viewer.cpp
 * @brief Viewer Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */

#include "../include/tester/Viewer.h"
#include <stdio.h>
#include <qmessagebox.h>
#include <QInputDialog>
#include <qt4/QtCore/qpoint.h>

// =======================   OWN INCLUDES AND DEFINES   ========================
#include "../include/tester/tasks/pointing/Experiment.h"
#define BLOCKS_PER_EXPERIMENT 4
#define TRIALS_PER_ID 1
#define STARTWIDTH 1920
#define STARTHEIGHT 1080 //1024
// =============================================================================

using namespace qglviewer;
using namespace std;

Experiment exper;
int clicks=0;

FalconMouse falcon;

//SELECTION
void Viewer::postSelection(const QPoint& point){
    int experimentState=0;
    // Compute orig and dir, used to draw a representation of the intersecting line
    //camera()->convertClickToLine(point, orig, dir);
        
    
    //Click and returns the state of the experiment:
    //- 0: The Experiment doesn't have started
    //- 1: The Experiment has started, shows the current block
    //- 2: Finished Experiment, doesn't show anything
    experimentState=exper.click(point);
    
    if(experimentState==2){
        thanks();
    }
    
    
    addMessage("click x: ",point.x(),2);
    addMessage("click y: ",point.y(),3);
    
    clicks++;
    addMessage("Clicks: ",clicks,4);
    
    addMessage("Experiment state: ",experimentState,5);
    
    addMessage("Block: ",exper.getCurrentBlock(),6);
    addMessage("Trial: ",exper.getCurrentTrial(),7);
    
}

void Viewer::init(){
    int type,device;
    long document;
    bool okType=false, okDevice=false, okDocument=false;
    /*Size of window
     * The size of window has an initial value for unsupported screens and fullScreen
     * for the rest.
     * **/
    resize(STARTWIDTH,STARTHEIGHT);
    setFullScreen(true);
    //Select type of experiment. '1' for 2D, '2' for 3D
    qglviewer::AxisPlaneConstraint* constraint;
    constraint = new LocalConstraint();
    if(type=='1'){
        constraint->setRotationConstraintType(AxisPlaneConstraint::FORBIDDEN);
    }else{
        constraint->setRotationConstraintType(AxisPlaneConstraint::FREE);
    }
    //Constraint the zoom
    constraint->setTranslationConstraintType(AxisPlaneConstraint::FORBIDDEN);
    camera()->frame()->setConstraint(constraint);
    showEntireScene();
    
    
    //Inicialization vars
    countMessages=0;
    
    
    
    addMessage("Inicializando Viewer ",0,9);
    
    //Ask for user data
    while(!okType){
        type=QInputDialog::getInt (this,
            tr("Type of experiment"),
            tr("Select the type of experiment:"
                "\n   1. Pointing experiment"
                "\n   2. 3D drag and drop"),
            1,1,2,1,&okType);
    }
    while(!okDevice){
        device=QInputDialog::getInt (this,
            tr("Device to test"),
            tr("Select the device for the experiment:"
                "\n   1. Mouse"
                "\n   2. Wiimote"
                "\n   3. Kinect"
                "\n   4. Falcon"),
            4,1,4,1,&okDevice);
    }
    while(!okDocument){
        document=QInputDialog::getInt (this,
            tr("Document of the participant"),
            tr("Type the document of the participant"),
            0,0,2147483647,1,&okDocument);
    }
    if(type==1){
        //Experiment inicialization    
        exper.init(width(),height(),device,document,BLOCKS_PER_EXPERIMENT,TRIALS_PER_ID);
        // Click on the right button to make a selection
        setMouseBinding(Qt::LeftButton,SELECT);
        
        
        falcon.init(width(),height());
        falcon.addOptions(FalconMouse::DEVICE_OPTIONS | FalconMouse::COMM_OPTIONS | FalconMouse::FIRMWARE_OPTIONS);
        
        
        startAnimation();
    }else{
        QMessageBox::information(this,
                "Under construction",
                "The 3D experiment is under construction");
        init();
    }
}
void Viewer::setVars(int argc, char** argv){
    if(!falcon.parseOptions(argc, argv));
}
void Viewer::addMessage(QString message){
    messages[countMessages]=message;
    countMessages++;
}
void Viewer::addMessage(QString message,float n){
    messages[countMessages]=message+QString::number(n);
    countMessages++;
}
void Viewer::addMessage(QString message,float n,int index){
    messages[index]=message+QString::number(n);
}
void Viewer::displayMessages(){
    int msgY=35;
    int msgX=10;
    int msgSpace=12;
    qglColor(foregroundColor());
    glDisable(GL_LIGHTING);
    for(int i=0;i<maxMessages;i++){
        drawText(msgX,msgY,messages[i]);
        msgY+=msgSpace;
    }
    glEnable(GL_LIGHTING);
}
void Viewer::draw(){
    startScreenCoordinatesSystem();
    exper.paint(width(),height());
    stopScreenCoordinatesSystem();
    cursor=falcon.getPos();
    if(falcon.getClick(0)||falcon.getClick(1)||falcon.getClick(2)||falcon.getClick(3)){
        const QPoint point((int)cursor.getX(),(int)cursor.getY());
        postSelection(point);
    }
    drawCursor();
    addMessage("Width: ",width(),0);
    addMessage("Height: ",height(),1);
    displayMessages();
}
void Viewer::animate(){}
void Viewer::thanks(){
    QMessageBox msgBox;
    msgBox.setText("The experiment is over. Thanks for your help.");
    msgBox.setInformativeText("Do you want to start again?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Yes:
            init();
        break;
        case QMessageBox::No:
            exit(0);
        break;
    }
}
void Viewer::drawCursor(){
    Circle c1=Circle(cursor,10,QColor(0,0,255,120));
    startScreenCoordinatesSystem();
    c1.paint();
    stopScreenCoordinatesSystem();
}