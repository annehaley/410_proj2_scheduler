/*
 * Stats.cpp
 *
 *  Created on: Feb 10, 2020
 *      Author: anne
 */

#include "../includes/stats.h"
using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector){
	vec=&finished_vector;
	av_wait_time=0.2;
	av_turnaround_time=0.4;
	av_response_time=0.6;
}

void Stats::showAllProcessInfo(){
	for(PCB p : *vec){
	cout<<"Process "<<p.process_number
					<<" Required CPU time:"<<p.required_cpu_time
					<<" arrived:"<<p.arrival_time
					<<" started:"<<p.start_time
					<<" finished:"<<p.finish_time<<endl;
	}
}

float Stats::get_av_response_time(){
	float sum=0;
	for(PCB p : *vec){
		sum+=p.start_time-p.arrival_time;
	}
	return sum/vec->size();
}

float Stats::get_av_turnaround_time(){
	float sum=0;
	for(PCB p : *vec){
		sum+=p.finish_time-p.arrival_time;
	}
	return sum/vec->size();
}

float Stats::get_av_wait_time(){
	float sum=0;
	for(PCB p : *vec){
		sum+=p.finish_time-p.arrival_time-p.required_cpu_time;
	}
	return sum/vec->size();
}
