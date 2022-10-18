#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        bool operator()(Event* x, Event* y)
        {
                uint64_t T1 = x -> time;
                uint64_t T2 = y -> time;
                return T1 < T2;
        } 
        //write the operator() required to make this a functor that compares Events by time
} EventLess;
	
#endif
