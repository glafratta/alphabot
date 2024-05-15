#include "alphabot.h"
#include <unistd.h>
#include <cstdio>

class Callback :public AlphaBot::StepCallback { //every 100ms the callback updates the plan
    public:
	int ct=0;
    float R=.5;
    float L=.5;
	bool end=0;

Callback(int &_ct){
	ct=_ct;
	}
void step( AlphaBot &motors){
	ct++;
	printf("ct = %i\n", ct);
	motors.setRightWheelSpeed(R);
	motors.setLeftWheelSpeed(L);
	printf("R=%f, L=%f\n", R, L);
	if (ct>64){
	motors.setRightWheelSpeed(0);
    motors.setLeftWheelSpeed(0);
}
}
};



int main(int, char**){
    AlphaBot robot;
	int ct=0;
    Callback cb(ct);
    robot.registerStepCallback(&cb);
    robot.start();

	while(ct<51){
}
//    usleep(10000000);
robot.setRightWheelSpeed(0);
    robot.setLeftWheelSpeed(0);
    robot.stop();
    return 1;

}
//.66cm in 51 steps at 1.0PMW
