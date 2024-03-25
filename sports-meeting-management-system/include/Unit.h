/*
Unit Header
*/
#ifndef UNIT_H
#define UNIT_H

typedef struct {
	int id;
	char* name;
} Unit;

// view
void unitView();

// controller
int addUnit(Unit* a);
bool removeUnit(int id);
bool modifyUnit(int id, Unit* a);
Unit* queryUnit(int id);

// model
Unit* newUnit();
Unit** getUnitList();
int* getUnitCount();
#endif
