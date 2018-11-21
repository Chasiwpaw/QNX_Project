/*
 * hit.h
 *
 *  Created on: Nov 21, 2018
 *      Author: philippeaboukasm
 */

#ifndef HIT_H_
#define HIT_H_

class hit: public position{

public:

	hit(int id, position p){

		planeid = id;
		this->p = p;

	}

	position getPosition() {
		return p;
	}

	int getPlaneId() {
		return planeid;
	}

private:

	int planeid;

	position p;

};



#endif
