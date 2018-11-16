/*
 * trackfile.h
 *
 *  Created on: Nov 5, 2018
 *      Author: philippeaboukasm
 */

#ifndef TRACKFILE_H_
#define TRACKFILE_H_

#include "position.h"
#include <vector>

using namespace std;



class trackfile : public position {

public:

	trackfile(){

		currentPos.setX(0);
		currentPos.setY(0);
		currentPos.setZ(0);
		currentPos.setT(0);
		ID = 0;
		velocity = 0;
	};

	~trackfile(){

	};

	trackfile(float x, float y, float z, double t, int d, double v){

		position prevPos = position(currentPos.getX(), currentPos.getY(), currentPos.getZ(), currentPos.getT());

		/* Save previous position*/

		posfile.push_back(prevPos);

		/* Update new position*/

		currentPos.setX(x);
		currentPos.setY(y);
		currentPos.setZ(z);
		currentPos.setT(t);
		ID = d;
		velocity = v;
	}



	double getTime(){
		return currentPos.getT();
	}

	int getID(){
		return ID;
	}

	double getVelocity(){
		return velocity;
	}

	vector<position> getPrevPos(){
		return posfile;
	}

private:

	/*Current Position*/

	position currentPos;

	int ID;
	double velocity;


	vector<position> posfile;

};




#endif /* TRACKFILE_H_ */
