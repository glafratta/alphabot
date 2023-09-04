#include "alphabot.h"
#include <unistd.h>
#include <cstdio>

class Callback :public AlphaBot::StepCallback { //every 100ms the callback updates the plan
    int ct=0;
    bool end=0;
public:

Callback(Configurator *conf): c(conf){
}
void step( AlphaBot &motors){
	ct++;
	if (int(ct/15)==1){
		printf("finished L\n");	
		motors.setRightWheelSpeed(-0.5);
		motors.setLeftWheelSpeed(0.5);
	}
	else if (int(ct/15)==2){
		printf("finished R\n");
		motors.setRightWheelSpeed(0);
		motors.setLeftWheelSpeed(0);
		end=1;
	}
	else{end=1;}
}
};



int main(int, char**){
    AlphaBot robot;
    Callback cb;
    robot.registerStepCallback(&cb);
    robot.start();
    do {
	}while (!cb.end);

    robot.stop();

}
