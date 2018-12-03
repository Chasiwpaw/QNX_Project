#include <iostream>
#include <chrono>
#include "./header/communication.h"

communication::communication(std::vector<hit> hit_list) {
	this->hit_list.clear();
	this->hit_list.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
}

communication::~communication() {

};

void communication::delete_aircraft(int craftID) {
	bool isFound = false;

	// Search and delete aircraft from hit_list
	std::vector<hit>::iterator craft_itr;
	for(craft_itr = this->hit_list.begin(); craft_itr != this->hit_list.end(); craft_itr++) {
		if(craft_itr->getPlaneId() == craftID) {
			craft_itr = this->hit_list.erase(craft_itr);
			--craft_itr;
			isFound = true;
		}
	}

	// Output ID not found if it is not in the hit list
	if(!isFound) {
		std::cout << "Cannot find ID" << std::endl;
	}
//	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count;
//	this->aircraft_deletion_timestamps.push_back(ms);
}

// Collect radar status of aircraft deletions every 10 secs
void communication::collect_aircraft_deletions(std::vector<hit> hit_list) {
	this->radar_status_collector.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
}

// Insert radar status of aircraft deletions to log file every 60 secs
void communication::log_aircraft_deletions(std::vector<hit> radar_status_collector) {
	// TODO: Implement a recipient to collect to radar status and timestamps

	// Record time upon airspace logging
//	std::chrono::milliseconds ms = std::chrono::duration_cast<milliseconds>(std::system_clock::now().time_since_epoch()).count;
//	this->aircraft_logging_timestamps.push_back(ms);
}
