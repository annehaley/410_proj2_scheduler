/*
 *  Created on: Feb 10 2020
 *      Author: anne
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
using namespace std;

struct shortest_time_remaining {
	bool operator()(PCB one, PCB two){
		return one.remaining_cpu_time>two.remaining_cpu_time;
	}
};

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	int front_rem_time= ready_q->front().remaining_cpu_time;

	if(front_rem_time<0 || front_rem_time<=p.remaining_cpu_time){
		return true;
	}
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort(){
	priority_queue<PCB, vector<PCB>, shortest_time_remaining> pq;
	while(!ready_q->empty()){
		pq.push(ready_q->front());
		ready_q->pop();
	}
	while(!pq.empty()){
		ready_q->push(pq.top());
		pq.pop();
	}
}

