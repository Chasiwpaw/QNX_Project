#ifndef TRACKER_H_
#define TRACKER_H_

#include <vector>
#include "hit.h"

using namespace std;

class tracker {

public:

	tracker() {

	}

	~tracker() {

	}

private:
	trackfile tf;
	vector<hit> hit_list;
};

#endif
