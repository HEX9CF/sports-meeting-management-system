/*
Unit Controller
*/
#include "../../include/main.h"

int addUnit(Unit *u) {
	Unit** unitList = getUnitList();
	int* pCount = getUnitCount();
	if (*pCount >= MAX_SIZE) {
		return -1;
	}
	u->id = ++(*pCount);
	unitList[*pCount] = u;
	return *pCount; 
}

bool removeUnit(int id) {
	Unit** unitList = getUnitList();
	if (id < 1 || id >= MAX_SIZE || !unitList[id]) {
		return false;
	}
	free(unitList[id]->name);
	free(unitList[id]);
	unitList[id] = NULL;
	return true;
}

bool modifyUnit(int id, Unit *u) {
	Unit** unitList = getUnitList();
	if (id < 1 || id >= MAX_SIZE || !unitList[id]) {
		return false;
	}
	free(unitList[id]->name);
	free(unitList[id]);
	u->id = id;
	unitList[id] = u;
	return true;
}

Unit* queryUnit(int id) {
	Unit** unitList = getUnitList();
	if (id < 1 || id >= MAX_SIZE) {
		return NULL;
	}
	return unitList[id];
}