/*
Event Header
*/
#ifndef EVENT_H
#define EVENT_H

typedef struct {
	int id;
	char* name;
	int gender; // 0.未知，1.男子，2.女子，3.其他，4.混合
	int type; // 0.未知，1.田赛，2.竞赛，3.其他
} Event;

// view
void eventView();

// controller
int addEvent(Event* a);
bool removeEvent(int id);
bool modifyEvent(int id, Event* a);
Event* queryEvent(int id);

// model
Event* newEvent();
Event** getEventList();
int* getEventCount();
#endif