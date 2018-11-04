#include <iostream>

class Radar {
    public:
        int plane_id;
        Position p;
        Radar(int plane_id, Position p) {
            this.plane_id = plane_id;
            this.p = p;
        }

        // Insert to Airspace Status
        void status_insert();

        // Insert to Airspace Log
        void log_insert();
};
