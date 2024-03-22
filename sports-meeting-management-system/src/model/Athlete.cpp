#include "../../include/main.h"

static int count = 0;
static Athlete *athleteList[MAX_SIZE];

Athlete* newAthlete() {
	Athlete *a = (Athlete *)malloc(sizeof(Athlete));
	a->name = (char*)malloc(MAX_LENGTH * sizeof(char));
	a->gender = (char*)malloc(MAX_LENGTH * sizeof(char));
	return a;
}

int insertAthleteList(Athlete *a) {
	if (count >= MAX_SIZE) {
		return -1;
	}
	athleteList[count++] = a;
	return count - 1;
}

bool deleteAthleteList(int i) {
	if (i < 0 || i >= MAX_SIZE || !athleteList[i]) {
		return false;
	}
	free(athleteList[i]->name);
	free(athleteList[i]->gender);
	free(athleteList[i]);
	athleteList[i] = NULL;
	return true;
}

bool updateAthleteList(int i, Athlete *a) {
	if (i < 0 || i >= MAX_SIZE || !athleteList[i]) {
		return false;
	}
	free(athleteList[i]->name);
	free(athleteList[i]->gender);
	free(athleteList[i]);
	athleteList[i] = a;
	return true;
}
 
Athlete* selectAthleteList(int i) {
	if (i < 0 || i >= MAX_SIZE) {
		return NULL;
	}
	return athleteList[i];
}

