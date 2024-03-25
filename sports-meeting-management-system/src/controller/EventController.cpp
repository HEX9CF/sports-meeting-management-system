/*
Event Controller
*/
#include "../../include/main.h"

int addEvent(Event *e) {
	Event** eventList = getEventList();
	int* pCount = getEventCount();
	if (*pCount >= MAX_SIZE) {
		return -1;
	}
	e->id = ++(*pCount);
	eventList[*pCount] = e;
	return *pCount; 
}

bool removeEvent(int id) {
	Event** eventList = getEventList();
	if (id < 0 || id >= MAX_SIZE || !eventList[id]) {
		return false;
	}
	free(eventList[id]->name);
	free(eventList[id]);
	eventList[id] = NULL;
	return true;
}

bool modifyEvent(int id, Event *e) {
	Event** eventList = getEventList();
	if (id < 0 || id >= MAX_SIZE || !eventList[id]) {
		return false;
	}
	free(eventList[id]->name);
	free(eventList[id]);
	eventList[id] = e;
	return true;
}

Event* queryEvent(int id) {
	Event** eventList = getEventList();
	if (id < 0 || id >= MAX_SIZE) {
		return NULL;
	}
	return eventList[id];
}