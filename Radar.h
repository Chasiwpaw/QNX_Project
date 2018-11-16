/*
 * radar.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#ifndef SRC_RADAR_H_
#define SRC_RADAR_H_

class radar : public position{


public:

	radar(int id, float x, float y, float z, double t){

		planeid = id;

		p.setX(x);
		p.setY(y);
		p.setZ(z);
		p.setT(t);

	}



private:

	int planeid;

	position p;

};



#endif /* SRC_RADAR_H_ */
