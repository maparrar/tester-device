/**
 * @file Block.h
 * @brief Header for class Block
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef BLOCK_H
#define BLOCK_H
#include <QVector>
#include "Trial.h"
#include "Difficulty.h"
/**
 * @class Block
 * Block allows manage the trials.
 * State of the Block
 * - 0: The Block doesn't have started
 * - 1: The Block has started, shows the current trial
 * - 2: Finished block, doesn't show anything
 */
class Block{
private:
    //Screen size
    int width;
    int height;
    int state;
    int trialsPerId;            //Quantity of trials per ID
    QVector<Trial> trials;      //Trials array
    QVector<Difficulty> ids;    //IDs to apply to the trials
    int current;
    //Analisys measures
    float TP;
public:
    Block();
    Block(int _trialsPerId);
    virtual ~Block();
    void setState(int _state);
    int getState();
    int getCurrentTrial();
    QVector<Trial> getTrials();
    /**
     * Returns the Throughput of the Block
     * @return TP of the Block
     */
    float getTP();
    /**
     * Starts the Block
     */
    void init(int _width, int _height);
    /**
     * Draws the Block
     */
    void paint();
    /**
     * Send the Point click to the Trials
     * @param p Point clicked
     */
    void click(Point p);
    //Methods to fill the IDs
    /**
     * Fill the IDs array
     */
    void fillId();
    /**
     * Calculate the trials using the IDs array and the quantity of trials
     */
    void generateTrials();
    /**
     * Calculate the Throughput for this Block
     */
    void calculateTP();
    /**
     * Returns a ramdomized center Point in the scene, using the parameters of a trial
     */
    Point randomizeCenter(float distance,float radiusC1,float radiusC2);
}; 
#endif /* BLOCK_H */