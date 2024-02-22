#ifndef EVENT_H
#define EVENT_H
#include "wire.h"
//#include "../heap.h"

/*
    In event.h write the operator() implementation for EventLess 
    to create a functor for your heap implementation. The operator()
     will take two Event*'s as it’s input and needs to sort 
     them using the Event::time data member in such a way 
     that your heap will be a min-heap. i.e. Event's are sorted 
     by time.
*/
struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(Event* lhs, Event* rhs){
          /*
          int result;
          if(lhs->time < rhs->time){
              result = lhs->time;
          }else if(rhs->time > lhs->time){
              result = rhs->time;
          }
          return result;
          */
          return lhs->time < rhs->time;
        }
} EventLess;
	
#endif
