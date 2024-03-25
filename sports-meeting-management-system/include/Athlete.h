/*
Athlete Header
*/
#ifndef ATHLETE_H
#define ATHLETE_H

typedef struct {
	int id; // PK
	char* name;
	int gender; // 0.未知，1.男性，2.女性，3.其他
	int age;
	int unitId; // FK
}Athlete;

// view
void athleteView();

// controller
int addAthlete(Athlete *a);
bool removeAthlete(int id);
bool modifyAthlete(int id, Athlete *a);
Athlete* queryAthlete(int id);

// model
Athlete* newAthlete();
Athlete** getAthleteList(); 
int* getAthleteCount();
#endif
