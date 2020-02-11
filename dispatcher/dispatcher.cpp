/*
 * Dispatcher.cpp
 *
 *  Created on: Feb 10, 2020
 *      Author: anne
 */

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU(){
	if (!isValidJobOnCPU())
		return PCB();
	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB &process){
	if(!isValidJobOnCPU())
		cpu->put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU(){
	is_valid_job_on_cpu= !cpu->get_COPY_of_Current_Process().isEmpty();
	return is_valid_job_on_cpu;
}
