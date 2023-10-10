#ifndef PATH_H
#define PATH_H
#include <vector>

struct Path {
    struct Waypoint {
        int x;
        int y;
    };

std::vector<Waypoint> pathWaypoints = {
    {100, 200}, // Waypoint 1
    {300, 200}, // Waypoint 2
    {500, 300}, // Waypoint 3
    {700, 300}, // Waypoint 4
    // Add more waypoints as needed
};

};
#endif