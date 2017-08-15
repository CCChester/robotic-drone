#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cstdlib>
#include "drone.h"

using namespace std;

//initialize the field Drone.
Drone::Drone():index(0),totalstep(0),p({0,0}){}

/*********** forward **********
      Purpose: Contain nothing, to do go forward.
         different value depends to different location.
      Returns: NULL 
***********************************/

void Drone::forward(){
    step[index].ew = p.ew; //to recorde ew position
    step[index].ns = p.ns; //to recorde ns position
    index++;       //increment index 
    totalstep++;  //increment totalstep
    //to see if value is 0
    if (record == 0){   
        p.ns = p.ns + 1;  //increment p. ns
    } //if
    //to see if value is 1
    else if (record == 1){
        p.ew = p.ew + 1;  //increment p.ew
    } //if
    //to see if value is 2
    else if (record == 2){
        p.ns = p.ns - 1; 
    }//if
    //to see if value is 3
    else if (record == 3){
        p.ew = p.ew - 1;
    }//if
}

/*********** backward  **********
      Purpose: Contain nothing, to do go backward.
         different value depends to different location.
      Returns: NULL 
***********************************/

void Drone::backward(){
    step[index].ew = p.ew; //to recorde ew position
    step[index].ns = p.ns; //to recorde ns position
    index++;  //increment index
    totalstep++; //increment totalstep
    //to see if value is 0
    if (record == 0){ 
        p.ns = p.ns - 1;
    } //if
    //to see if value is 1
    else if (record == 1){
        p.ew = p.ew - 1;
    } //if
    //to see if value is 2
    else if (record == 2){
        p.ns = p.ns + 1;  //increment p.ns
    } //if
    //to see if value is 3
    else if (record == 3){
        p.ew = p.ew + 1; //increment p.ew
    } //if
}

/*********** left  **********
      Purpose: Contain nothing, to do turn left.
         different value depends to different location.
      Returns: NULL 
***********************************/

void Drone::left(){
    //to see if value is 0
    if (record == 0){
        record = 3;  //resign value is 3
    } //if
    else {
        record = record - 1;//value = value-1
    } //if
}

/*********** right  **********
      Purpose: Contain nothing, to do turn right.
         different value depends to different location.
      Returns: NULL 
***********************************/

void Drone::right(){
    //to see if value is 3
    if (record == 3){
        record = 0; //resign value is 3
    } //if
    else {
        record = record + 1; //increment value
    } //if
}

/*********** current **********
      Purpose: Contain nothing, to do show current pos.
      Returns: position
***********************************/

Position Drone::current(){
    return p;
}

/*********** totalDistance **********
       Purpose: Contain nothing.
       Returns: return int.
***********************************/

int Drone::totalDistance(){
    return totalstep;
}

/************* absolute **********************
      Purpose: Contains a int num, to take the
           absolute value of num.
           if num is positive, nothing change
      Returns: an integer
***********************************/
int absolute(int num){
    // if num is negative
    if (num < 0){
       num = -(num);
    }//if
    //if num is positive 
    else{ num = num; } //if
    return num;
}

/************* manhattanDistance **********************
      Purpose: contains nothing
      Returns: an integer
***********************************/
int Drone::manhattanDistance(){
    return absolute(p.ns) + absolute(p.ew);
}

/************* repeated **********************
      Purpose: contains nothing
      Returns: returns false and true
***********************************/
bool Drone::repeated(){
    int pos = 0;
    while (pos < index){
        if (p.ns == step[pos].ns && p.ew == step[pos].ew){
            return true;
        } //if
        ++pos;
    } //while
    return false;
}
