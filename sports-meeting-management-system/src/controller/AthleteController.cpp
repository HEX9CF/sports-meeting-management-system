#include "../../include/main.h"

int addAthlete(Athlete *a) {
	return insertAthleteList(a);
}

bool removeAthlete(int id) {
	return deleteAthleteList(id);
}

bool modifyAthlete(int id, Athlete *a) {
	return updateAthleteList(id, a);
}

Athlete* queryAthlete(int id) {
	return selectAthleteList(id);
}