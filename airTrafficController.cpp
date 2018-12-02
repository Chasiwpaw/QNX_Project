
#include <pthread.h>
#include "trackfile.h"
#include "displayManager.h"
#include "radar.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <pthread.h>

using namespace std;

int main() {

	int h = 25000;

	int w = 100000;

	int d = 100000;

	displayManager d1;

	vector <trackfile> v;

	radar r;

	bool running = true;

	bool notfinished = true;

	int exit = 1;

	int command;

	int idcommand;

	int allcommand;

	int opcommand;

	int aircraftid;

	int altamount;

	int vxamount;

	int vyamount;

	int vzamount;

	int airid;

	int airx;

	int airy;

	int airz;

	int airvx;

	int airvy;

	int airvz;

	int airt;

	int delid;

	int logid;

	int projsec;

	while(running){

	cout << "***Air Traffic Controller***"<< endl;
	cout << "Input the command number you would like to execute:" << endl;
	cout << "1 - Run airspace" << endl;
	cout << "2 - View airspace" << endl;
	cout << "3 - Command aircraft by ID" << endl;
	cout << "4 - Command all aircrafts" << endl;
	cout << "5 - Modify airspace" << endl;
	cout << "6 - Exit" << endl;

	cin >> command;

	switch(command){

	case 1:

		r.scan(); //parses the file to hit_list
		//Start Time
		//Start Update Position
		break;

	case 2:

		while (exit != 0){


		//r.printhit();

		r.findActive(150); //find the active aircraft /add time

		r.printactive();

		v = r.getActive(); //returns active vector

		d1.displayGrid(v);

		cout << "Enter 0 to exit, any other number else to proceed" << endl;

		cin >> exit;

		}

		break;

	case 3:

		cout << "Enter the ID of the aircraft" << endl;

		cin >> aircraftid;

		cout << "Input the command number you would like to execute:"<< endl;
		cout << "1 - Change altitude" << endl;
		cout << "2 - Change speed" << endl;
		cout << "3 - Report position/pelocity" << endl;
		cout << "4 - Enter holding pattern" << endl;
		cout << "5 - Exit" << endl;

		cin >> idcommand;

		switch(idcommand){

		case 1:

			cout << "Enter the amount of change in integers ( x 1000)" << endl;

			cin >> altamount;
			r.changeAltitude(aircraftid, altamount);
			cout << "Altitude successfully changed" << endl;
			break;

		case 2:

			cout << "Enter the desired speed coordinates Vx, Vy, Vz seperated by return" << endl;
			cin >> vxamount;
			cin >> vyamount;
			cin >> vzamount;

			r.changeSpeed(aircraftid, vxamount, vyamount, vzamount);
			cout << "Speed successfully changed" << endl;
			break;


		case 3:

			r.reportCoordinates(aircraftid);
			break;

		case 4:
			cout << "Feature not available" << endl;
			break;

		case 5:
			break;
		}

	case 4:

		cout << "Input the command number you would like to execute:" << endl;
		cout << "1 - Enter holding pattern" << endl;
		cout << "2 - Report aircraft information" << endl;
		cout << "3 - Exit" << endl;

		cin >> allcommand;

		switch(allcommand){

		case 1:
			cout << "Feature not available" << endl;

			break;

		case 2:
			r.printhit();

			r.printactive();

			break;

		case 3:
			break;
		}

	case 5:

		cout << "Input the command number you would like to execute:" << endl;
		cout << "1 - Add aircraft" << endl;
		cout << "2 - Delete aircraft by id" << endl;
		cout << "3 - Display log by id" << endl;
		cout << "4 - Project aircraft positions" << endl;
		cout << "5 - Exit" << endl;

		cin >> opcommand;

		switch (opcommand){

		case 1:

			cout << "Enter aircraft ID: ";
			cin >> airid;
			cout << endl << "Enter aircraft X coordinate";
			cin >> airx;
			cout << endl << "Enter aicraft Y coordinate";
			cin >> airy;
			cout << endl << "Enter aircraft Z coordinate";
			cin >> airz;
			cout << endl << "Enter aircraft X speed";
			cin >> airvx;
			cout << endl << "Enter aircraft Y speed";
			cin >> airvy;
			cout << endl << "Enter aircraft Z speed";
			cin >> airvz;
			cout << endl << "Enter aircraft entry time";
			cin >> airt;
			r.addAircraft(airid,airx,airy,airz,airvx,airvy,airvz,1); // replace 1 with current time;
			cout << endl << "Aircraft successfully added" << endl;
			break;

		case 2:

			cout << "Enter aircraft ID:";
			cin >> delid;
			r.deleteAircraft(delid);
			cout << endl << "Aircraft with ID " << delid << " successfully deleted" << endl;
			break;

		case 3:
			cout << "Enter aircraft ID:";
			cin >> logid;
			r.getLog(logid);
			break;

		case 4:
			cout << "Enter the number of seconds for the projection:";
			cin >> projsec;
			//project positions;
			break;

		case 5:
			break;
		}
		break;
	case 6:
		running = false;
		break;
	}

	}


	//r.updatePosition(); to run in background with time (seperate thread)

	//r.checkCollision(); // to run in background with time (seperate thread)


	return 0;
}
