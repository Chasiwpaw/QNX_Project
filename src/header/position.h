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

	position();

	position(float cx, float cy, float cz);

	~position();

	void setX(float inx);

	float getX();

	void setY(float iny);

	float getY();

	void setZ(float inz);

	float getZ();

private:

	float x;

	float y;

	float z;

};


#endif /* POSITION_H_ */
