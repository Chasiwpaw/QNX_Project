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

		cout << "***Air Traffic Controller***" << endl;

		for (int p = 0; p < 100; p++){

			if (p == 0) {
				cout << "[  ][ 0]";
			}

			else if(p < 10){
				cout << "[ " << p <<"]";
			}

			else {
			cout << "[" << p << "]";
			}
		}

			cout << endl;

		for (int i=0; i < 100; i++){

			if(i < 10) {
				cout<< "[ " << i << "]";
			} else {
				cout << "[" << i << "]" ;
			}


			for (int k=0; k < 100; k++){
				bool match_pos = false;
				for (int j = 0; j< v.size(); j++)
				{
					if (v[j].getCurrentPos().getX() == k && v[j].getCurrentPos().getY() == i) {
						match_pos = true;
					}
				}

				if(match_pos) {
					cout << "[**]";
				} else {
					cout << "[  ]";
				}
			}

			cout << endl;

		}

		cout << endl;
	}

private:



};

#endif /* DISPLAYMANAGER_H_ */
