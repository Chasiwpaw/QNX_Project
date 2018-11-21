/*
 * displayManager.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_

#include <iostream>
#include <vector>

using namespace std;

class displayManager : public trackfile{


public:

	void displayGrid(vector<trackfile> v){

		cout << "***Air Traffic Controller***";

		for (int p = 0; p < 100; p++){

			cout << " " << p;
		}

		for (int i=0; i < 100; i++){

			cout << i << " " ;

			for (int k=0; k < 100; k++){

				for (int j = 0; j< v.size(); j++)
				{
				if (v[j].getCurrentPos().getX() == i && v[j].getCurrentPos().getY() == k) {
					cout << "*";
				}
				else {
					cout << "#";
				}

				}
			}

			cout << endl;

		}


	}

private:



};

#endif /* DISPLAYMANAGER_H_ */
