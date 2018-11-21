
#include <pthread.h>
#include "trackfile.h"
#include "displayManager.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

	trackfile tf((float)1,(float) 2,(float)2, (int)3, (double)300);

	trackfile tf2((float)3,(float) 6,(float)7, (int)3, (double)300);

	trackfile tf3((float)6,(float) 6,(float)9, (int)3, (double)300);

	displayManager d1;

	vector <trackfile> v;

	v.push_back(tf);

	v.push_back(tf2);

	v.push_back(tf3);

	d1.displayGrid(v);



	return 0;
}
