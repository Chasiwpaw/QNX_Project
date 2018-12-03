#include <iostream>
#include <chrono>
#include "./header/radar.h"

radar::radar() {

};

radar::radar(std::vector<hit> hit_list) {
	this->hit_list.clear();
	this->hit_list.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
}

// Get current radar status
std::vector<hit> radar::get_current_airspace_status() {
	return this->hit_list;
}

// TODO: Get radar status at specific time
//std::vector<hit> radar::get_specific_airspace_status(min) {
//
//}

radar::~radar() = default;

// Insert new aircraft to airspace
void radar::insert_aircraft(hit h) {
	// Add new hit to hit list
	this->hit_list.push_back(h);

	// Record time upon radar detection
//	std::chrono::milliseconds ms = std::chrono::duration_cast<milliseconds>(std::system_clock::now().time_since_epoch()).count;
//	this->aircraft_insertion_timestamps.push_back(ms);
}

// Update the airspace with new aircraft position every 3 sec
void update_airspace_status() {

}

// Collect radar status of aircraft insertions every 10 secs
void radar::collect_aircraft_insertions(std::vector<hit> hit_list) {
	this->radar_status_collector.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
}

// Insert radar status of aircraft insertions in a log file every 60 secs
void radar::log_aircraft_insertions(std::vector<hit> radar_status_collector) {
	// TODO: Implement a recipient to collect to radar status and timestamps

	// Record time upon airspace logging
//	std::chrono::milliseconds ms = std::chrono::duration_cast<std::milliseconds>(std::system_clock::now().time_since_epoch()).count;
//	this->aircraft_logging_timestamps.push_back(ms);
}
