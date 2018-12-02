/*
 * communication.h
 *
 *  Created on: Nov 5, 2018
 *      Author: philippeaboukasm
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

using namespace std;

class communication : public hit{

public:

	communication(){

		hit_list.clear();
		hit_list.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));
	}

	~communication()

    // Delete to aircraft from airspace
    void delete_aircraft(int craftID){
    	bool isFound = false;

    		// Search and delete aircraft from hit_list
    		std::vector<hit>::iterator craft_itr;
    		for(craft_itr = this->hit_list.begin(); craft_itr != this-->hit_list.end(); craft_itr++) {
    			if(craft_itr->planeid == craftID) {
    				craft_itr = this->hit_list.erase(craft_itr);
    				--craft_itr;
    				isFound = true;
    			}
    		}

    		// Output ID not found if it is not in the hit list
    		if(!isFound) {
    			cout << "Cannot find ID" << endl;
    		}
    		std::chrono::milliseconds ms = std::chrono::duration_cast<milliseconds>(std::system_clock::now().time_since_epoch()).count;
    		this->aircraft_deletion_timestamps.push_back(ms);
    }



    // Collect aircraft deletions from airspace
    void collect_aircraft_deletions(){
    	radar_status_collector.insert(std::end(radar_status_collector), std::begin(hit_list), std::end(hit_list));

    }

    // Delete to Airspace Log
    void log_aircraft_deletions(){

    };

private:

	vector<hit> hit_list, radar_status_collector;

	vector<std::chrono::milliseconds> aircraft_deletion_timestamps, airspace_logging_timestamps;
};




#endif /* COMMUNICATION_H_ */
