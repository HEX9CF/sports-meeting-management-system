/*
Event Header
*/
#ifndef EVENT_H
#define EVENT_H

typedef struct {
	int id; // PK
	char* name;
	int gender; // 0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.���
	int type; // 0.δ֪��1.������2.������3.����
	struct tm datetime;
	char* location;
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
const char* getEventGenderStr(Event* e);
const char* getEventTypeStr(Event* e);
#endif