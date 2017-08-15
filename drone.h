#ifndef __DRONE_H__
#define __DRONE_H__

struct Position {
    int ew;  //position of ew
    int ns;  //position of ns
};

struct Drone {
    Position p;  //point p
    Position step[50];  //total max of 50 step
    
    Drone();
    int index;      //position
    int totalstep;  //how many steps it is
    int record;
    
    void forward();  //go forward
    void backward();  //go back
    void left();     //turn left
    void right();    //turn right
    Position current();  //current position
    int totalDistance();  //total steps
    int manhattanDistance();  //total length between current to origin
    bool repeated();  //To judge it is repeated or not
};

#endif
