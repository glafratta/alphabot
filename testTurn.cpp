#include "alphabot.h"
#include <unistd.h>
#include <cstdio>

class Callback :public AlphaBot::StepCallback { //every 100ms the callback updates the plan
    int ct=0;
public:
	bool end=0;

Callback(){}
void step( AlphaBot &motors){
	if (ct<15){
		printf("finished L\n");	
		motors.setRightWheelSpeed(0.5);
		motors.setLeftWheelSpeed(-0.5);
	}
	else if(ct<15+15){
	motors.setRightWheelSpeed(0);
	motors.setLeftWheelSpeed(0);
}
	else if(ct<30+15){
	       motors.setRightWheelSpeed(-0.5);
	       motors.setLeftWheelSpeed(0.5);
	}
	else{end=1;
	motors.setRightWheelSpeed(0);
	motors.setLeftWheelSpeed(0);
}
	ct++;
}
};



int main(int, char**){
    AlphaBot robot;
    Callback cb;
    robot.registerStepCallback(&cb);
    robot.start();
    do {
	}while (!getchar());
    robot.stop();
    return 1;

}
