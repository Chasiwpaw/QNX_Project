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
		currentPos.setVx(0);
		currentPos.setVy(0);
		currentPos.setVz(0);
		ID = 0;
	}

	trackfile(int x, int y, int z, int vx, int vy, int vz, int d){

			currentPos.setX(x);
			currentPos.setY(y);
			currentPos.setZ(z);
			currentPos.setVx(vx);
			currentPos.setVy(vy);
			currentPos.setVz(vz);
			ID = d;

		}

	~trackfile(){

	}

	void setTrackfile(int x, int y, int z, int vx, int vy, int vz){

		position prevPos = position(currentPos.getX(), currentPos.getY(), currentPos.getZ(), currentPos.getVx(), currentPos.getVy(), currentPos.getVz());

		/* Save previous position*/

		posfile.push_back(prevPos);

		/* Update new position*/

		currentPos.setX(x);
		currentPos.setY(y);
		currentPos.setZ(z);
		currentPos.setVx(vx);
		currentPos.setVy(vy);
		currentPos.setVz(vz);

	}


	int getID(){
		return ID;
	}


	position getCurrentPos(){
		 return currentPos;
	}

	vector<position> getPrevPos(){
		return posfile;
	}

private:

	/*Current Position*/

	position currentPos;

	int ID;

	vector<position> posfile;

};




#endif /* TRACKFILE_H_ */
