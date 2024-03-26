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
	 // 0.未知，1.男性，2.女性，3.其他
	switch (a->gender)
	{
	case 1:
		return "男性";
		break;
	case 2:
		return "女性";
		break;
	case 3: 
		return "其他";
		break;
	default:
		return "未知";
	}
}
