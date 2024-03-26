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
 
 const char* getAthleteGenderStr(Athlete *a) {
	 // 0.δ֪��1.���ԣ�2.Ů�ԣ�3.����
	switch (a->gender)
	{
	case 1:
		return "����";
		break;
	case 2:
		return "Ů��";
		break;
	case 3: 
		return "����";
		break;
	default:
		return "δ֪";
	}
}
