#include "alphabot.h"
#include <unistd.h>
#include <cstdio>

class Callback :public AlphaBot::StepCallback { //every 100ms the callback updates the plan
    int ct=0;
    float R=0;
    float L=0;
public:
	bool end=0;

Callback(){}
void step( AlphaBot &motors){
	ct++;
	printf("ct = %i\n", ct);
	motors.setRightWheelSpeed(R);
	motors.setLeftWheelSpeed(L);
	printf("R=%f, L=%f\n", R, L);
}
};



int main(int, char**){
    AlphaBot robot;
    Callback cb;
    robot.registerStepCallback(&cb);
    robot.start();
    printf("battery level = %f\n", robot.getBatteryLevel());
    do {
	}while (!getchar());
robot.setRightWheelSpeed(0);
    robot.setLeftWheelSpeed(0);
    robot.stop();
    return 1;

}
