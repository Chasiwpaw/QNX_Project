/*
 * aircraft.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#ifndef SRC_AIRCRAFT_H_
#define SRC_AIRCRAFT_H_

class aircraft : public position{


public:

	aircraft(){

		id = 0;

		P.setX(0);
		P.setY(0);
		P.setZ(0);
		velocity = 0;
	}

	aircraft(int id, position p, double v){

//		id = rand() % 100 + 1;

		this->id = id;

		this->p = p;

		velocity = v;
	}

	void setID(int i){
		id = i;
	}

	int getID(){
		return id;
	}

	void setPos(float x, float y, float z){

		p.setX(x);
		p.setY(y);
		p.setZ(z);
	}

	Position getPos(){
		return p;
	}

	float getPosX(){
		return p.getX();
	}

	float getPosY(){
		return p.getY();
	}

	float getPosZ(){
		return p.getZ();
	}

	void setVel(double v){
		velocity = v;
	}

	double getVel(){
		return velocity;
	}
private:

	int id;

	position p;

	double velocity;


};




#endif /* SRC_AIRCRAFT_H_ */
