#include "alphabot.h"
#include <unistd.h>
#include <cstdio>


int main(int, char**){
    AlphaBot robot;
    robot.start();
    printf("Right wheel!\n");
    robot.setLeftWheelSpeed(-1.0f);
    usleep(500000);
    robot.setLeftWheelSpeed(0.0f);
    printf("Left Wheel!\n");
    robot.setRightWheelSpeed(-1.0f);
    usleep(500000);
    robot.setRightWheelSpeed(0.0f);
    robot.stop();


}
