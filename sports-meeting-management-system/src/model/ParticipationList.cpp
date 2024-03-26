/*
Participation Model
*/
#include "../../include/main.h"

static int count = 0;
static Participation *participationList[MAX_SIZE];

Participation* newParticipation() {
	Participation *p = (Participation *)malloc(sizeof(Participation));
	if (!p) {
		return NULL;
	}
	return p;
}

Participation** getParticipationList() {
	return participationList;
}

int* getParticipationCount() {
	return &count;
}
