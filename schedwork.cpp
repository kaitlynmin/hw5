#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool backtrack(int day, int worker, std::vector<int> shifts, const AvailabilityMatrix& avail,
               size_t dailyNeed, size_t maxShifts, DailySchedule& sched);
// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    sched.resize(avail.size(), std::vector<Worker_T>());
    // Add your code below

    if (dailyNeed == 0) {
        return true;
    }
    std::vector<int> shifts(avail[0].size());
    
    int day = 0;
    int worker = 0;
    return backtrack(day, worker, shifts, avail, dailyNeed, maxShifts, sched);
  
}

// pass in current day and current worker
// keep day constant and iterate through worker until the daily need is met 
// once daily need is met, ++ day and make worker 0
// keep track of the shifts using a map
bool backtrack(int day, int worker, std::vector<int> shifts, const AvailabilityMatrix& avail,
               size_t dailyNeed, size_t maxShifts, DailySchedule& sched) {

  if (day == avail.size()) { // if we've scheduled every day
    return true;
  }
  if (worker == avail[0].size()) {
    return false;
  }

  if (avail[day][worker] == 0 || shifts[worker] == maxShifts) {
    return backtrack(day, worker+1, shifts, avail, dailyNeed, maxShifts, sched);
  }

  sched[day].push_back(worker);
  shifts[worker]++;
  
  // the worker can work today
  // 2 options here
  // worker works
  // worker does not work

  bool success;
  if (dailyNeed == sched[day].size()) {
    success = backtrack(day+1, 0, shifts, avail, dailyNeed, maxShifts, sched);
  } else {
    success = backtrack(day, worker+1, shifts, avail, dailyNeed, maxShifts, sched);
  }
  if (success) {
    return true;
  }

  sched[day].pop_back();
  shifts[worker]--;

  return backtrack(day, worker+1, shifts, avail, dailyNeed, maxShifts, sched);
}
//iterate col -> col , row -> row
//check shifts and how many shifts that day so far 
