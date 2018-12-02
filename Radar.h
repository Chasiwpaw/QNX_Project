/*
 * radar.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#include "hit.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#ifndef SRC_RADAR_H_
#define SRC_RADAR_H_

using namespace std;

class radar: public hit, trackfile{

public:


	radar(){

	}

	~radar(){}

	// Get current airspace status

	// Get airspace status at specific time in min


    void scan(){

    	ifstream infile;

    	infile.open("inputs.txt");

    		if (!infile) {

    			cout << "Unable to open file" << endl;

    			exit(1);
    		}

    		while (infile) {

    		getline(infile, tempid, ',');

    		getline(infile, tempvx, ',');

    		getline(infile, tempvy, ',');

    		getline(infile, tempvz, ',');

    		getline(infile, tempx, ',');

    		getline(infile, tempy, ',');

    		getline(infile, tempz, ',');

    		getline(infile, tempentrytime, ',');

    		hit_list.push_back(hit(stoi(tempid), position(stoi(tempx),stoi(tempy),stoi(tempz),stoi(tempvx),stoi(tempvy),stoi(tempvz)),stoi(tempentrytime)));

    			if (infile.eof()){
    			break;
    			}

    		}

    }

    void print(){

    	for (int i = 0; i < active_list.size(); i++){
    		cout << "X: " << active_list[i].getCurrentPos().getX() << " Y: " << active_list[i].getCurrentPos().getY() << " Z: " << active_list[i].getCurrentPos().getZ() << endl;
    	}
    }


    void findActive(int time){

    	for (int i = 0; i< hit_list.size(); i++){

    		if (hit_list[i].getEntryT() <= time){

    			if((hit_list[i].getPosition().getX() > 0 && hit_list[i].getPosition().getX() < 100000) &&
    				(hit_list[i].getPosition().getY() > 0 && hit_list[i].getPosition().getY() < 100000) &&
					(hit_list[i].getPosition().getZ() > 0 && hit_list[i].getPosition().getZ() < 25000)){

    			trackfile t(hit_list[i].getPosition().getX(),
    						hit_list[i].getPosition().getY(),
							hit_list[i].getPosition().getZ(),
							hit_list[i].getPosition().getVx(),
							hit_list[i].getPosition().getVy(),
							hit_list[i].getPosition().getVz(),
							hit_list[i].getPlaneId());

    			hit_list.erase(hit_list.begin() + i);

    			active_list.push_back(t);

    			}
    		}
    	}
    }

    vector<trackfile> getActive(){
    	return active_list;
    }

    //Run every 3 seconds at least
    void updatePosition(){

    	for (int k = 0; k<hit_list.size(); k++){

    		hit_list[k].setPosition(hit_list[k].getPosition().getX() + hit_list[k].getPosition().getVx(), hit_list[k].getPosition().getY() + hit_list[k].getPosition().getVy(), hit_list[k].getPosition().getZ() + hit_list[k].getPosition().getVz() );
    	}

    	for (int i = 0; i<active_list.size(); i++){

    		active_list[i].setTrackfile(active_list[i].getCurrentPos().getX() + active_list[i].getCurrentPos().getVx(), active_list[i].getCurrentPos().getY() + active_list[i].getCurrentPos().getVy(), active_list[i].getCurrentPos().getZ() + active_list[i].getCurrentPos().getVz(), active_list[i].getCurrentPos().getVx(), active_list[i].getCurrentPos().getVy(),active_list[i].getCurrentPos().getVz());
    	}
    }


    void checkCollision(){

    	// Check for vertical collisions

    	for (int i = 0; i < active_list.size(); i++){


    	}



    	// Check for horizontal collisions

    	for (int k = 0; k < active_list.size(); k++){

    	}
    }




private:

vector<hit> hit_list;

vector<trackfile> active_list;

string tempid;

string tempvx;

string tempvy;

string tempvz;

string tempx;

string tempy;

string tempz;

string tempentrytime;


};



#endif /* SRC_RADAR_H_ */
