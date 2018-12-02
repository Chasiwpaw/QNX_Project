
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

	std::ofstream outfile ("awufgoqwheq.txt");

	outfile << "my text here!" << std::endl;

	outfile.close();

	r.scan();

	r.findActive(150);

	r.print();

	v = r.getActive();

//	d1.displayGrid(v);




	return 0;
}
