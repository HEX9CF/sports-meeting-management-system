/*
Participation Controller
*/
#include "../../include/main.h"

int addParticipation(Participation *e) {
	Participation** participationList = getParticipationList();
	int* pCount = getParticipationCount();
	if (*pCount >= MAX_SIZE) {
		return -1;
	}
	e->id = ++(*pCount);
	participationList[*pCount] = e;
	return *pCount; 
}

bool removeParticipation(int id) {
	Participation** participationList = getParticipationList();
	if (id < 0 || id >= MAX_SIZE || !participationList[id]) {
		return false;
	}
	free(participationList[id]);
	participationList[id] = NULL;
	return true;
}

bool modifyParticipation(int id, Participation *e) {
	Participation** participationList = getParticipationList();
	if (id < 0 || id >= MAX_SIZE || !participationList[id]) {
		return false;
	}
	free(participationList[id]);
	e->id = id;
	participationList[id] = e;
	return true;
}

Participation* queryParticipation(int id) {
	Participation** participationList = getParticipationList();
	if (id < 0 || id >= MAX_SIZE) {
		return NULL;
	}
	return participationList[id];
}