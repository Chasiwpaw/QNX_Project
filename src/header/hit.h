#ifndef HIT_H_
#define HIT_H_
#include "position.h"

class hit: public position{

public:

	hit();

	hit(int id, position p, double v);

	~hit();

	int getPlaneId();

	position getPosition();

	double getVelocity();

	void setPosition(position p);

	void setVelocity(double v);


private:

	int planeid;

	position p;

	double v;
};

#endif
