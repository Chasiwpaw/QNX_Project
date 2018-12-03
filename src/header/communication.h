/*
 * communication.h
 *
 *  Created on: Nov 5, 2018
 *      Author: philippeaboukasm
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
#include <vector>
#include "hit.h"

class communication{

public:

	communication(std::vector<hit> hit_list);

	~communication();

    // Delete to aircraft from airspace
    void delete_aircraft(int craftID);

    // Collect aircraft deletions from airspace
    void collect_aircraft_deletions(std::vector<hit> hit_list);

    // Delete to Airspace Log
    void log_aircraft_deletions(std::vector<hit> radar_status_collector);

private:

	std::vector<hit> hit_list, radar_status_collector;

	std::vector<std::chrono::milliseconds> aircraft_deletion_timestamps, airspace_logging_timestamps;
};




#endif /* COMMUNICATION_H_ */
