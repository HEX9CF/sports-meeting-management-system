/*
Unit Header
*/
#ifndef UNIT_H
#define UNIT_H

typedef struct {
	int id;	// PK
	char* name;
} Unit;

// view
void unitView();

// controller
int addUnit(Unit* u);
bool removeUnit(int id);
bool modifyUnit(int id, Unit* u);
Unit* queryUnit(int id);

// model
Unit* newUnit();
Unit** getUnitList();
int* getUnitCount();
#endif
