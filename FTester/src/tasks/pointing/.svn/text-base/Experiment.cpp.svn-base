/**
 * @file Experiment.cpp
 * @brief Experiment Class
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
using namespace std;
#include "../../../include/tester/tasks/pointing/Experiment.h"
#include <iostream>
#include <fstream>
#include <qt4/QtCore/qvector.h>
Experiment::Experiment(){
    state=0;
    blocksPerExperiment=2;
    trialsPerId=5;
    current=0;           
}
Experiment::~Experiment(){}
int Experiment::getDevice(){
    return device;
}
int Experiment::getCurrentBlock(){
    return current;
}
int Experiment::getCurrentTrial(){
    return blocks[current].getCurrentTrial();
}
//---------------------------------------------------------------------------
// Methods
//---------------------------------------------------------------------------
void Experiment::init(int _width, int _height,int _device,long _document,int _blocksPerExperiment,int _trialsPerId){
    width=_width;
    height=_height;
    document=_document;
    device=_device;
    blocksPerExperiment=_blocksPerExperiment;
    trialsPerId=_trialsPerId;
    blocks.clear();
    state=1;
    current=0;                  //Current block
    for(int i=0;i<blocksPerExperiment;i++){
        blocks.append(Block(trialsPerId));
    }
    blocks[current].init(width,height);
}
void Experiment::paint(int _width, int _height){
    width=_width;
    height=_height;
    if(state==1&&current<blocks.size()){
        blocks[current].paint();
    }
}
int Experiment::click(Point p){
    if(state==1&&current<blocks.size()){
        blocks[current].click(p);
        if(blocks[current].getState()==2){
            current++;
            if(current<blocks.size()){
                blocks[current].init(width,height);
            }else if(current==blocks.size()){
                calculateTP();
                save();
                state=2;
            }
        }
    }
    return state;
}
int Experiment::click(QPoint p){
    Point punto(p.x(),p.y());
    return click(punto);
}
void Experiment::calculateTP(){
    float sumTP=0,avgTP=0;
    cout<<"THROUGHPUT"<<endl;
    for(int i=0;i<blocks.size();i++){
        cout<<"Block "<<i<<"\t"<<blocks[i].getTP()<<endl;
        sumTP+=blocks[i].getTP();
    }
    avgTP=sumTP/blocks.size();
    TP=avgTP;
    cout<<"Average TP: "<<TP<<" bps"<<endl;
    
}
void Experiment::save(){
    ofstream file;
    ofstream summary;
    QString documentChar=QString::number(document);
    QString deviceChar=QString::number(device);
    QString string = "../data/"+documentChar+"_"+deviceChar+".txt";
    QByteArray bytes = string.toAscii();
    const char * fileName = bytes.data();
    file.open(fileName);
    file<<  "Block\t"
            "Trial\t"
            "W\t"
            "D\t"
            "MT\t"
            "ID\t"
            "c1.x\t"
            "c1.y\t"
            "c2.x\t"
            "c2.y\t"
            "Dr"<<endl;
    for(int i=0;i<blocks.size();i++){
        QVector<Trial> trials=blocks[i].getTrials();
        for(int j=0;j<trials.size();j++){
            file<<
                    i<<"\t"<<
                    j<<"\t"<<
                    trials[j].getW()<<"\t"<<
                    trials[j].getD()<<"\t"<<
                    trials[j].getMT()<<"\t"<<
                    trials[j].getID()<<"\t"<<
                    trials[j].getStart().getX()<<"\t"<<
                    trials[j].getStart().getY()<<"\t"<<
                    trials[j].getStop().getX()<<"\t"<<
                    trials[j].getStop().getY()<<"\t"<<
                    trials[j].getDr()<<
                    endl;
        }
    }
    file.close();
    //Append the personal measures to summary.txt file
    summary.open("../data/summary.txt",ios::app);
        summary<<document<<"\t"<<device<<"\t"<<TP<<endl;
    summary.close();
}