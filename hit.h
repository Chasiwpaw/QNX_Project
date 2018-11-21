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

	hit();

	hit(int id, position p);

	~hit();

	position getPosition(){
			return p;
	}

	int getPlaneId(){
			return planeid;
	};

private:

	int planeid;

	position p;

};



#endif
