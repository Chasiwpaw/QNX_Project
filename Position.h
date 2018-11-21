/*
 * Position.h
 *
 *  Created on: Nov 7, 2018
 *      Author: philippeaboukasm
 */

#ifndef POSITION_H_
#define POSITION_H_

class position{

public:

	position(){

		x = 0;

		y = 0;

		z = 0;


	}

	position(float cx, float cy, float cz){

		x = cx;

		y = cy;

		z = cz;

	}

	~position(){

	}

	void setX(float inx){
		x = inx;
	}

	float getX() {
		return x;
	}

	void setY(float iny){
		y = iny;
	}

	float getY(){
		return y;
	}

	void setZ(float inz){
		z = inz;
	}

	float getZ() {
		return z;
	}


private:

	float x;

	float y;

	float z;

};


#endif /* POSITION_H_ */
