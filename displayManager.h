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


		for (int p = 0; p < 101; p++){

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

		for (int i=0; i < 101; i++){

			if(i < 10) {
				cout<< "[ " << i << "]";
			} else {
				cout << "[" << i << "]" ;
			}


			for (int k=0; k < 101; k++){

				bool match_pos, unknown;

				for (int j = 0; j< v.size(); j++)
				{
					match_pos = false;
					unknown = false;
					if (((v[j].getCurrentPos().getX())/1000) == k && ((v[j].getCurrentPos().getY())/1000) == i) {
						match_pos = true;
						if (v[j].getID() == -1){
							unknown = true;
						}
						break;
					}
				}

				if(match_pos && unknown){
					cout << "[XX]";
				}
				else if(match_pos && !unknown) {
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
