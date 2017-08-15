# robotic-drone

In this exercise, you will write a C++ class (implemented as a struct) to control a simple
robotic drone exploring some terrain. Your drone will start at coordinates (0,0), facing north.
Use the following structure denition for coordinates:
struct Position {
int ew, ns;
};
The east-west direction shall be the rst component of a position, and the north-south direc-
tion shall be the second. Your Drone class must be properly initialized via a constructor, and
must provide the following methods:
 void forward(); { move one unit forward
 void backward(); { move one unit backward
 void left(); { turn 90 degrees to the left, while remaining in the same location
 void right(); { turn 90 degrees to the right, while remaining in the same location
 Position current(); { returns the current position
 int totalDistance() { total units of distance travelled by the drone
 int manhattanDistance() { Manhattan distance between current position and origin
(Manhattan distance is absolute north-south displacement plus absolute east-west dis-
placement).
 bool repeated() { true if the current position is one that the drone has previously
visited
For simplicity, you may assume that the drone will never visit more than 50 positions before
running out of fuel. In other words, once the drone has made 50 moves, forward, backward,
left and right are considered invalid input and the program behaviour is undened.
A test harness is provided (a3q1.cc), by which you may interact with your drone for testing
purposes. Incorrect usage of the test harness should not be part of your test cases i.e. you
do not need to write tests to try to break the test harness.
