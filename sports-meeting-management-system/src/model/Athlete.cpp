/*
Athlete Model
*/
#include "../../include/main.h"

static int count = 0;
static Athlete *athleteList[MAX_SIZE];

Athlete* newAthlete() {
	Athlete *a = (Athlete *)malloc(sizeof(Athlete));
	if (!a) {
		return NULL;
	}
	a->name = (char*)malloc(MAX_LENGTH * sizeof(char));
	return a;
}

Athlete** getAthleteList() {
	return athleteList;
}

int* getAthleteCount() {
	return &count;
}
