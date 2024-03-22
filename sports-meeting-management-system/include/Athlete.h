#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct {
	char* name;
	char* gender;
	int age;
}Athlete;

void athleteView();

int addAthlete(Athlete *a);
bool removeAthlete(int id);
bool modifyAthlete(int id, Athlete *a);
Athlete* queryAthlete(int id);

Athlete* newAthlete();
int insertAthleteList(Athlete *a);
bool deleteAthleteList(int i);
bool updateAthleteList(int i, Athlete *a);
Athlete* selectAthleteList(int i);

#endif
