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
	// 0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.���
	switch (e->gender)
	{
	case 1:
		return "����";
		break;
	case 2:
		return "Ů��";
		break;
	case 3: 
		return "����";
		break;
	case 4:
		return "���";
		break;
	default:
		return "δ֪";
	}
}

const char* getEventTypeStr(Event *e) {
	// 0.δ֪��1.������2.������3.����
	switch (e->type)
	{
		case 1:
			return "����";
			break;
		case 2:
			return "����";
			break;
		case 3:
			return "����";
			break;
		default:
			return "δ֪";
	}
}
