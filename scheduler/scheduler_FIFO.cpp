/*
 *  Created on: Feb 10, 2020
 *      Author: anne
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"
using namespace std;

bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_FIFO::sort(){}


