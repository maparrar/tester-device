/**
 * @file Experiment.h
 * @brief Header for class Experiment
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <qt4/QtCore/qpoint.h>
#include <QVector>
#include "Block.h"
/**
 * @class Experiment
 * Experiment allows manage the blocks of trials. 
 * - 0: The Experiment doesn't have started
 * - 1: The Experiment has started, shows the current block
 * - 2: Finished Experiment, doesn't show anything
 */
class Experiment{
private:
    //Screen size
    int width;
    int height;
    int device;                 //1: mouse, 2: Wiimote, 3: Kinect, 4: Falcon
    long document;              //Identification of participant
    int state;
    int blocksPerExperiment;    //Quantity of blocks per Experiment
    int trialsPerId;            //Quantity of trials per ID
    int current;
    QVector<Block> blocks;
    //Analisys measures
    float TP;
public:
    Experiment();
    virtual ~Experiment();
    int getDevice();
    int getCurrentBlock();
    int getCurrentTrial();
    /**
     * Starts the Experiment
     */
    void init(int _width, int _height,int _device,long _document,int _blocksPerExperiment,int _trialsPerId);
    /**
     * Draws the Experiment
     */
    void paint(int _width, int _height);
    /**
     * Send the Point click to the Blocks
     * @param p Point clicked
     * @return the state of the experiment
     */
    int click(Point p);
    /**
     * Send the Point click to the Blocks
     * @param p QPoint of QT
     * @return the state of the experiment
     */
    int click(QPoint p);
    /**
     * Calculate the Throughput for this Experiment
     */
    void calculateTP();
    /**
     * Save the data of the experiment to file
     */
    void save();
};
#endif /* EXPERIMENT_H */