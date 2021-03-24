#include "stdio.h"
#include "string.h"

// Mujoco header files
#include "mujoco.h"
#include "mjmodel.h"
#include "mjdata.h"
#include "mjvisualize.h"
#include "mjrender.h"
#include "mjui.h"
#include "mjxmacro.h"
#include "glfw3.h"

char error[1000];
mjModel* m;
mjData* d;

int main(void){
	// activate Mujoco
	mj_activate("mjkey.txt");
	
	//load model from file and check for errors
	m = mj_loadXML("humanoid.xml", NULL, error, 1000);
	if (!m) {
		printf("%s\n", error);
		return 1;
	}
	
	// make data corresponding to model
	d = mj_makeData(m);
	
	// run simulation for 10 seconds
	while(d->time <10){
		mj_step(m,d);
	}
	// free model and data, deactivate
	mj_deleteData(d);
	mj_deleteModel(m);
	mj_deactivate();
	return 0;
}