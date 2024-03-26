/*
Score Model
*/
#include "../../include/main.h"

static int count = 0;
static Score *scoreList[MAX_SIZE];

Score* newScore() {
	Score *u = (Score *)malloc(sizeof(Score));
	if (!u) {
		return NULL;
	}
	return u;
}

Score** getScoreList() {
	return scoreList;
}

int* getScoreCount() {
	return &count;
}
