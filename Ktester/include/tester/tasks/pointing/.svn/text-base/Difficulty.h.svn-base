/**
 * @file Difficulty.h
 * @brief Header for class Difficulty.
 * @author Miguel Alejandro Parra Romero (maparrar@unal.edu.co) @author Jean Pierre Charalambos @author Universidad Nacional de Colombia - 2011
 * @details BSD License @details Project info http://code.google.com/p/tester-device/
 */
#ifndef DIFFICULTY_H
#define DIFFICULTY_H
/**
 * @class Difficulty
 * It has a wide target and the distance between points, from these values, calculated on each trial the ID (index of difficulty). The value of each difficulty must be planned according to the hardware used in the experiment.
 */
class Difficulty{
private:
    int width;
    int distance;
public:
    Difficulty();
    Difficulty(int _width,int _distance);
    virtual ~Difficulty();
    void setWidth(int _width);
    int getWidth();
    void setDistance(int _distance);
    int getDistance();
};
#endif /* DIFFICULTY_H */