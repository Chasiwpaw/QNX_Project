#include <iostream>
#include "Position.h"

class Radar {
        int plane_id, x, y, z;
        Position p;
    public:
        Radar(int plane_id, int x, int y, int z) : p(x, y, z){
            this->plane_id = plane_id;
        }

        // Insert to Airspace Status
        void status_insert();

        // Insert to Airspace Log
        void log_insert();
};
