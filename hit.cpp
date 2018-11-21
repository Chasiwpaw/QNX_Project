#include "hit.h"

hit::hit() = default;

hit::hit(int id, position p) {
	planeid = id;
	this->p = p;
}

hit::~hit() = default;

int hit::getPlaneId() {
	return planeid;
}

position hit::getPosition() {
	return p;
}
