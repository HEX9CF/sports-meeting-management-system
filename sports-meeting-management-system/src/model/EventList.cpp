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

const char* getEventGenderStr(Event *e) {
	// 0.未知，1.男子，2.女子，3.其他，4.混合
	switch (e->gender)
	{
	case 1:
		return "男子";
		break;
	case 2:
		return "女子";
		break;
	case 3: 
		return "其他";
		break;
	case 4:
		return "混合";
		break;
	default:
		return "未知";
	}
}

const char* getEventTypeStr(Event *e) {
	// 0.未知，1.田赛，2.竞赛，3.其他
	switch (e->type)
	{
		case 1:
			return "田赛";
			break;
		case 2:
			return "竞赛";
			break;
		case 3:
			return "其他";
			break;
		default:
			return "未知";
	}
}
