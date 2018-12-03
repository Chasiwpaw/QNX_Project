#include "./header/hit.h"

hit::hit() {
	this->planeid = -1;
	this->p = position();
	this->v = -1;
}

hit::hit(int id, position p, double v) {
	this->planeid = id;
	this->p = p;
	this->v = v;
}

hit::~hit() {

}

int hit::getPlaneId() {
	return this->planeid;
}

position hit::getPosition() {
	return this->p;
}

double hit::getVelocity() {
	return this->v;
}

void hit::setPosition(position p) {
	this->p = p;
}

void hit::setVelocity(double v) {
	this->v = v;
}
