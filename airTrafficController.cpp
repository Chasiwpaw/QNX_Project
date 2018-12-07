
#include <pthread.h>
#include "trackfile.h"
#include "displayManager.h"
#include "radar.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <sys/netmgr.h>
#include <sys/neutrino.h>

#define MY_PULSE_CODE   _PULSE_CODE_MINAVAIL

using namespace std;


displayManager d1;

vector <trackfile> v;

radar r;

bool scanned = false;

bool run = true;


typedef union {
		        struct _pulse   pulse;

		} my_message_t;

		 struct sigevent         event;

		 struct itimerspec       itime;

		 timer_t                 timer_id;

		 int                     chid;

		 int                     rcvid;

		 my_message_t            msg;

		 struct sched_param      scheduling_params;

		 int prio;

		 time_t start_time, end_time;

		 int time_passed;

void* display(void *) {
	while(run) {

		if(time_passed % 5 == 0) {
			r.findActive(time_passed);
//			r.removeActive();
			r.printactive();
			v = r.getActive(); //returns active vector
			r.checkCollision();
			cout << "Current Time: " << time_passed << endl;
			d1.displayGrid(v);
			cout << "Enter 0 to exit, any other number else to proceed" << endl;
		}

		if(time_passed % 15 == 0) {
//			r.findActive(time_passed); //find the active aircraft /add time
		}

		if(time_passed % 26 == 0) {
			//logging
//			r.logginghit(time_passed);
			r.loggingactive(time_passed);
		}
	}
}

void* timer(void *){

		 		chid = ChannelCreate(0);
		 	    //Get our priority.
		 	     if (SchedGet( 0, 0, &scheduling_params) != -1)
		 	     {
		 	        prio = scheduling_params.sched_priority;
		 	     }
		 	     else
		 	     {
		 	        prio = 10;
		 	     }

		 	    event.sigev_notify = SIGEV_PULSE;
		 	    event.sigev_coid = ConnectAttach(ND_LOCAL_NODE, 0,
		 	                                     chid,
		 	                                     _NTO_SIDE_CHANNEL, 0);
		 	    event.sigev_priority = prio;
		 	    event.sigev_code = MY_PULSE_CODE;
		 	    timer_create(CLOCK_MONOTONIC, &event, &timer_id);

		 	   itime.it_value.tv_sec = 1;
		 	      itime.it_value.tv_nsec = 000000000;
		 	      itime.it_interval.tv_sec = 1;
		 	      itime.it_interval.tv_nsec = 000000000;
		 	      timer_settime(timer_id, 0, &itime, NULL);
		 	      start_time = time(NULL);


		 	    for (;;) {
		 	          rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL);
		 	   	   end_time = time(NULL);
		 	   	   time_passed = (int) difftime(end_time, start_time);
//		 	   	   printf("Current time is: %i \n", time_passed);
		 	          if (rcvid == 0) { /* we got a pulse */
		 	               if (msg.pulse.code == MY_PULSE_CODE) {
		 	                  // printf("we got a pulse from our timer\n");
		 	               } /* else other pulses ... */
		 	          }
		 	         	r.updatePosition(time_passed); //to run in background with time (seperate thread)
		 	           //r.checkCollision();

		 	    }
		 	 }


int main() {

	int h = 25000;

	int w = 100000;

	int d = 100000;


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


	pthread_t t1;
	pthread_t t2;


	r.scan(); //parses the file to hit_list

	while(running){
	v.clear();

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


		pthread_create(&t1, NULL, timer, NULL);
		//Start Time
		break;

	case 2:

		while (exit != 0){



//			r.findActive(time_passed); //find the active aircraft /add time
//
//			r.checkCollision();
//
//			cout << "Current Time: " << time_passed << endl;
//
//			r.printactive();
//
//			v = r.getActive(); //returns active vector
//
//			d1.displayGrid(v);
//
//			cout << "Enter 0 to exit, any other number else to proceed" << endl;

		pthread_create(&t2, NULL, display, NULL);



		cin >> exit;

		}

		break;

	case 3:

		cout << "Enter the ID of the aircraft" << endl;

		cin >> aircraftid;

		cout << "Input the command number you would like to execute:"<< endl;
		cout << "1 - Change altitude" << endl;
		cout << "2 - Change speed" << endl;
		cout << "3 - Report position/velocity" << endl;
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

		break;

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

		break;

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
			cout << endl << "Enter aircraft Y coordinate";
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
			cout << "Enter the number of time units for the projection:";
			cin >> projsec;
			r.projectPos(projsec);
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




	//r.checkCollision(); // to run in background with time (seperate thread)

	pthread_join(t1,NULL);
	pthread_join(t2, NULL);
	return 0;
}
