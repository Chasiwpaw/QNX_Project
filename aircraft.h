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

	aircraft(float xpos, float ypos, float zpos, double syst, double v){

		id = rand() % 100 + 1;

		P.setX(xpos);
		P.setY(ypos);
		P.setZ(zpos);
		P.setT(syst);

		velocity = v;
	}

	void setID(int i){
		id = i;
	}

	int getID(){
		return id;
	}

	void setPos(float x, float y, float z){

		P.setX(x);
		P.setY(y);
		P.setZ(z);
	}

	position getPos(){
		return P;
	}

	float getPosX(){
		return P.getX();
	}

	float getPosY(){
		return P.getY();
	}

	float getPosZ(){
		return P.getZ();
	}

	void setVel(double v){
		velocity = v;
	}

	double getVel(){
		return velocity;
	}
private:

	int id;

	position P;

	double velocity;


};




#endif /* SRC_AIRCRAFT_H_ */
