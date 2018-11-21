/*
 * radar.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#include "hit.h"

#ifndef SRC_RADAR_H_
#define SRC_RADAR_H_

using namespace std;

class radar: public hit {

public:

	radar() {

	};

	radar(){

		hit_list.clear();
		hit_list.insert(end(radar_status_collector), begin(hit_list), end(hit_list));

	};

	~radar();

	// Get current airspace status
	vector<hit> get_current_airspace_status(){
		return hit_list;
	};

	// Get airspace status at specific time in min


    // Insert new aircraft to radar
    void insert_aircraft(hit h){
    	hit_list->push_back(h);
    };

    // Collect radar status of aircraft insertions every 10 sec
    void collect_aircraft_insertions(std::vector<hit> hit_list){
    	radar_status_collector.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
    }

    // Insert to aircraft insertions to airspace in log file every 60 sec
    void log_aircraft_insertions(std::vector<hit> radar_status_collector){

    }

private:

	vector<hit> hit_list, radar_status_collector;

	vector<std::chrono::milliseconds> aircraft_insertion_timestamps, airspace_logging_timestamps;

};



#endif /* SRC_RADAR_H_ */
