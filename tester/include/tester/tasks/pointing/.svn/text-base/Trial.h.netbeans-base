/**
 * @file Trial.h
 * @brief Header for class Trial
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef TRIAL_H
#define TRIAL_H
#include <QTime>
#include <math.h>
#include "../../util/Circle.h"
/**
 * @class Trial
 * Trial is one attempt to do the task, for example, do click in the start Point and then do click in the end Point is a Trial.
 * Trial description
 *      state:
 * - 0: The Trial doesn't have started
 *      - Doesn't display anything
 * - 1: The Trial has started
 *      - Display c1 (circle 1)
 * - 2: Click in c1 
 *      - Hide c1
 *      - Display c2
 *      - Waiting click in c2
 *      - Start timer
 * - 3: Click in c2
 *      - Hide c2
 *      - Return data
 *      - Stop timer
 * 
 * Trial class provides measures of the test, these measures allow generate the statistic information of the experiment. The ID is based in the Fitts' Law.
 */
class Trial{
private:
    int state;
    QTime timer;
    Circle c1;
    Circle c2;
    //Analisys measures
    float ID;           //Difficulty index calculated of the circles
                        //ID=log2((D/W)+1) Fitts' Law
    float W;            //Width of the end circle (c2)
    float D;            //Distance between c1 and c2
    long MT;            //Time to complete the trial (milliseconds)
    Point start;        //Point of the first click to start
    Point stop;         //Point of the second click to stop
    void calculateId(); //Calculate the ID based in the input circles
public:
    Trial();
    Trial(Point p,float width,float distance,float angle,float raduisC1);
    virtual ~Trial();
    void setState(int _state);
    int getState();
    /**
     * Returns the width of the Circle c2 (is the end or stop circle)
     * @return width of c2
     */
    float getW();
    /**
     * Distance between c1 (start circle) and c2 (stop circle)
     * @return distance between c1 and c2
     */
    float getD();
    /**
     * Time to complete the Trial in milliseconds
     * @return time of the Trial
     */
    long getMT();
    /**
     * Difficulty index calculated of the circles. The ID is based in the Fitts' Law.
     * \f$ID=log_2(\frac{D}{W}+1)\f$
     * @return ID of the Trial.
     */
    float getID();
    /**
     * Throughput
     * \f$ID=\frac{ID}{MT}\f$
     * @return TP of the Trial.
     */
    float getTP();
    /**
     * Returns the real distance between the two clicks, not necessarily equals to D.
     * @return Distance between clicks
     */
    float getDr();
    /**
     * Returns the start point
     * @return Point of the first click
     */
    Point getStart();
    /**
     * Returns the stop point
     * @return Point of the last click
     */
    Point getStop();
    
    /**
     * Set the state to 1
     */
    void init();
    /**
     * Draw the circles according to state using OpenGL
     */
    void paint();
    /**
     * Change the state based in Point p 
     * @param p Point where did click
     */
    void click(Point p);
}; 
//--------------------------------------------------------------------------- 
#endif /* TRIAL_H */