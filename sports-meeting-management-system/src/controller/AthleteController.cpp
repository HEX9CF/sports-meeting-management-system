/*
Athlete Controller
*/
#include "../../include/main.h"

int addAthlete(Athlete *a) {
	Athlete** athleteList = getAthleteList();
	int* pCount = getAthleteCount();
	if (*pCount >= MAX_SIZE) {
		return -1;
	}
	a->id = ++(*pCount);
	athleteList[*pCount] = a;
	return *pCount; 
}

bool removeAthlete(int id) {
	Athlete** athleteList = getAthleteList();
	if (id < 1 || id >= MAX_SIZE || !athleteList[id]) {
		return false;
	}
	free(athleteList[id]->name);
	free(athleteList[id]);
	athleteList[id] = NULL;
	return true;
}

bool modifyAthlete(int id, Athlete *a) {
	Athlete** athleteList = getAthleteList();
	if (id < 1 || id >= MAX_SIZE || !athleteList[id]) {
		return false;
	}
	free(athleteList[id]->name);
	free(athleteList[id]);
	a->id = id;
	athleteList[id] = a;
	return true;
}

Athlete* queryAthlete(int id) {
	Athlete** athleteList = getAthleteList();
	if (id < 1 || id >= MAX_SIZE) {
		return NULL;
	}
	return athleteList[id];
}