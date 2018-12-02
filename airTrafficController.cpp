
#include <pthread.h>
#include "trackfile.h"
#include "displayManager.h"
#include "radar.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <pthread.h>

using namespace std;

int main() {

	int h = 25000;

	int w = 100000;

	int d = 100000;

	displayManager d1;

	vector <trackfile> v;

	radar r;

	r.scan(); //parses the file to hit_list

	r.findActive(150); //find the active aircraft

	r.print(); //print current active list

	v = r.getActive(); //returns active vector

	d1.displayGrid(v);


	return 0;
}
