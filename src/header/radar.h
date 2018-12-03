/*
 * radar.h
 *
 *  Created on: Nov 15, 2018
 *      Author: philippeaboukasm
 */

#ifndef SRC_RADAR_H_
#define SRC_RADAR_H_
#include <vector>
#include "hit.h"

class radar: public hit{

public:

	radar();

	radar(std::vector<hit> hit_list);

	~radar();

	// Get current airspace status
	std::vector<hit> get_current_airspace_status();

	// Get airspace status at specific time in min
	std::vector<hit> get_specific_airspace_status(int min);

    // Insert new aircraft to radar
    void insert_aircraft(hit h);

    // Update the airspace with new aircraft position every 3 sec
    void update_airspace_status();

    // Collect radar status of aircraft insertions every 10 sec
    void collect_aircraft_insertions(std::vector<hit> hit_list);

    // Insert to aircraft insertions to airspace in log file every 60 sec
    void log_aircraft_insertions(std::vector<hit> radar_status_collector);

private:

	std::vector<hit> hit_list, radar_status_collector;

	std::vector<std::chrono::milliseconds> aircraft_insertion_timestamps, airspace_logging_timestamps;

};



#endif /* SRC_RADAR_H_ */
