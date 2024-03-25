/*
Event Model
*/
#include "../../include/main.h"

static int count = 0;
static Event *eventList[MAX_SIZE];

Event* newEvent() {
	Event *e = (Event *)malloc(sizeof(Event));
	if (!e) {
		return NULL;
	}
	e->name = (char*)malloc(MAX_LENGTH * sizeof(char));
	e->location = (char*)malloc(MAX_LENGTH * sizeof(char));
	return e;
}

Event** getEventList() {
	return eventList;
}

int* getEventCount() {
	return &count;
}
