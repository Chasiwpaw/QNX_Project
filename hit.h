/*
 * hit.h
 *
 *  Created on: Nov 21, 2018
 *      Author: philippeaboukasm
 */

#ifndef HIT_H_
#define HIT_H_
#include "position.h"
class hit : public position{

public:

	hit(){}

	hit(int id, position pos, int time){
		planeid = id;

		p = pos;

		entry_time = time;
	}


	~hit(){}

	void setPosition(int x, int y, int z){

		p.setX(x);

		p.setY(y);

		p.setZ(z);
	}

	void setSpeed(int vx, int vy, int vz){

		p.setVx(vx);

		p.setVy(vy);

		p.setVz(vz);
	}

	position getPosition(){
			return p;
	}

	int getPlaneId(){
			return planeid;
	}

	int getEntryT(){
		return entry_time;
	}

private:

	int planeid;

	position p;

	int entry_time;

};



#endif
