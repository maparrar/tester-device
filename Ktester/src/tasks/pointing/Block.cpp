/**
 * @file Block.cpp
 * @brief Block Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
using namespace std;
#include "../../../include/tester/tasks/pointing/Block.h"
#include <iostream>
#include <algorithm> // sort, max_element, random_shuffle
#include <qt4/QtCore/qvector.h>
#define RADIUS_C1 20    //Radius of the start circle C1
Block::Block(){
    state=0;
    trialsPerId=3;
    current=0;
}
Block::Block(int _trialsPerId){
    state=0;
    trialsPerId=_trialsPerId;
    current=0;
}
Block::~Block(){}
void Block::setState(int _state){
    state=_state;
}
int Block::getState(){
    return state;
}
int Block::getCurrentTrial(){
    return current;
}
QVector<Trial> Block::getTrials(){
    return trials;
}
float Block::getTP(){
    return TP;
}
//---------------------------------------------------------------------------
// Methods
//---------------------------------------------------------------------------
void Block::init(int _width, int _height){
    width=_width;
    height=_height;
    ids.clear();
    trials.clear();
    fillId();
    generateTrials();
    state=1;
    current=0;                  //Current trial    
    trials[current].init();
}
void Block::paint(){
    if(state==1&&current<trials.size()){
        trials[current].paint();
    }
}
void Block::click(Point p){
    if(state==1&&current<trials.size()){
        trials[current].click(p);
        if(trials[current].getState()==3){
            current++;
            if(current<trials.size()){
                trials[current].init();
            }else if(current==trials.size()){
                calculateTP();
                state=2;
            }
        }
    }
}
void Block::fillId(){
    ids.append(Difficulty(30,200));
    ids.append(Difficulty(30,400));
    ids.append(Difficulty(30,600));
    ids.append(Difficulty(50,200));
    ids.append(Difficulty(50,400));
    ids.append(Difficulty(50,600));
    ids.append(Difficulty(80,200));
    ids.append(Difficulty(80,400));
    ids.append(Difficulty(80,600));
}
void Block::generateTrials(){
    srand(time(NULL));
    for(int i=0;i<trialsPerId;i++){
        for(int j=0;j<ids.size();j++){
            //Randomize the center of trial
            Point p(randomizeCenter(ids[j].getDistance(),RADIUS_C1,ids[j].getWidth()/2));
            trials.append(Trial(p,ids[j].getWidth(),ids[j].getDistance(),rand()%359,RADIUS_C1));
        }
    }
    //Randomize the list of trials
    random_shuffle(trials.begin(), trials.end());
}
void Block::calculateTP(){
    float sumID=0,avgID=0,avgTime=0;
    long sumTime=0;
    //std::cout<<"Int\tW\tD\t\tMT\tID\t\tDr"<<std::endl;
    for(int i=0;i<trials.size();i++){
        //std::cout<<i<<"\t"<<trials[i].getW()<<"\t"<<trials[i].getD()<<"\t\t"<<trials[i].getMT()<<"\t"<<trials[i].getID()<<"\t\t"<<trials[i].getDr()<<std::endl;
        sumID+=trials[i].getID();
        sumTime+=trials[i].getMT();
    }
    avgID=sumID/trials.size();
    avgTime=((float)sumTime/1000.0)/trials.size();
    TP=avgID/avgTime;
    //std::cout<<"TP: "<<TP<<" bps"<<std::endl;
}
//This function returns a ramdomized center Point for a trial in the scene, using the parameters of a trial
Point Block::randomizeCenter(float distance,float radiusC1,float radiusC2){
    //calculates the width of the trial, since start extreme of c1 to end extreme of c2
    float widthTrial=distance+radiusC1+radiusC2;
    float randX=rand()%(int)(width-widthTrial);
    float randY=rand()%(int)(height-widthTrial);
    //    float x=randX+((widthTrial/2));
//    float y=randY+((widthTrial/2));
    
    //Testing to keep the center of trial in the center of screen
    float x=width/2;
    float y=height/2;
    return Point(x,y);
}