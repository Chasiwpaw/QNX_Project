/*
 * Demonstrate how to set up a timer that, on expiry,
 * sends us a pulse.  This example sets the first
 * expiry to 1.5 seconds and the repetition interval
 * to 1.5 seconds.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/netmgr.h>
#include <sys/neutrino.h>

#define MY_PULSE_CODE   _PULSE_CODE_MINAVAIL

typedef union {
        struct _pulse   pulse;
        /* your other message structures would go
           here too */
} my_message_t;

void* displayView(void *) {
	   printf("Display view of the plane \n");
}

void* scanView(void *) {
	   printf("Scan the plan view for new incoming plane or exiting plane \n");
}

void* logTrackFile(void *) {
	   printf("Log the trackfile to a file \n");
}

int main()
{
//  Timer variables
   struct sigevent         event;
   struct itimerspec       itime;
   timer_t                 timer_id;
   int                     chid;
   int                     rcvid;
   my_message_t            msg;
   struct sched_param      scheduling_params;
   int prio;

// Time counter
   time_t start_time, end_time;

   chid = ChannelCreate(0);

  /* Get our priority. */
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

   /*
    * As of the timer_settime(), we will receive our pulse
    * in 1.5 seconds (the itime.it_value) and every 1.5
    * seconds thereafter (the itime.it_interval)
    */

   for (;;) {
       rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL);
	   end_time = time(NULL);
	   int time_passed = (int) difftime(end_time, start_time);
	   printf("Current time is: %i \n", time_passed);
       if (rcvid == 0) { /* we got a pulse */
            if (msg.pulse.code == MY_PULSE_CODE) {
                printf("we got a pulse from our timer\n");
            } /* else other pulses ... */
       } /* else other messages ... */

       if(time_passed % 5 == 0) {
    	   pthread_t t1;
    	   pthread_attr_t thread_attrs;
    	   pthread_create(&t1, NULL, displayView, NULL);
    	   pthread_join(t1, NULL);
       }

       if(time_passed % 15 == 0) {
    	   pthread_t t2;
    	   pthread_attr_t thread_attrs;
    	   pthread_create(&t2, NULL, scanView, NULL);
    	   pthread_join(t2, NULL);
       }

       if(time_passed % 60 == 0) {
    	   pthread_t t3;
    	   pthread_attr_t thread_attrs;
    	   pthread_create(&t3, NULL, logTrackFile, NULL);
    	   pthread_join(t3, NULL);
       }
   }
   return(EXIT_SUCCESS);
}
