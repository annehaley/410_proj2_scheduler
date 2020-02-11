/*
 * scheduler.cpp
 *
 *  Created on: Feb 10, 2020
 *      Author: anne
 */

#include "../includes/scheduler.h"
using namespace std;

void Scheduler::add(PCB p){
	ready_q->push(p);
}

PCB Scheduler::getNext(){
	if(ready_q->empty())
		return PCB();
	PCB ret=ready_q->front();
	ready_q->pop();
	return ret;
}

bool Scheduler::isEmpty(){
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	if(p.remaining_cpu_time<=0){
		return true;
	}
	return false;
}







