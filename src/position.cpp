#include "./header/position.h"

position::position() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

position::position(float cx, float cy, float cz) {
	this->x = cx;
	this->y = cy;
	this->z = cz;
}

position::~position() {

}

void position::setX(float inx){
	this->x = inx;
}

float position::getX() {
	return this->x;
}

void position::setY(float iny){
	this->y = iny;
}

float position::getY(){
	return this->y;
}

void position::setZ(float inz){
	z = inz;
}

float position::getZ() {
	return z;
}
