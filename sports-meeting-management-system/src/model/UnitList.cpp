/*
Unit Model
*/
#include "../../include/main.h"

static int count = 0;
static Unit *unitList[MAX_SIZE];

Unit* newUnit() {
	Unit *u = (Unit *)malloc(sizeof(Unit));
	if (!u) {
		return NULL;
	}
	u->name = (char*)malloc(MAX_LENGTH * sizeof(char));
	return u;
}

Unit** getUnitList() {
	return unitList;
}

int* getUnitCount() {
	return &count;
}
