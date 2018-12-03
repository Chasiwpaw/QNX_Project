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

		vx = 0;

		vy = 0;

		vz = 0;


	}

	position(int cx, int cy, int cz, int vcx, int vcy, int vcz){

		x = cx;

		y = cy;

		z = cz;

		vx = vcx;

		vy = vcy;

		vz = vcz;

	}

	~position(){

	}

	void setX(int inx){
		x = inx;
	}

	int getX() {
		return x;
	}

	void setY(int iny){
		y = iny;
	}

	int getY(){
		return y;
	}

	void setZ(int inz){
		z = inz;
	}

	int getZ() {
		return z;
	}

	void setVx(int invx){
		vx = invx;
	}

	int getVx(){
		return vx;
	}

	void setVy(int invy){
		vy = invy;
	}

	int getVy(){
		return vy;
	}

	void setVz(int invz){
		vz = invz;
	}

	int getVz(){
		return vz;
	}

	void setTime(int t){

		time = t;
	}

	int getTime() {
		return time;
	}

private:

	int x;

	int y;

	int z;

	int vx;

	int vy;

	int vz;

	int time;
};


#endif /* POSITION_H_ */
