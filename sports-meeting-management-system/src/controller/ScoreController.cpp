/*
Score Controller
*/
#include "../../include/main.h"

int addScore(Score *s) {
	Score** scoreList = getScoreList();
	int* pCount = getScoreCount();
	if (*pCount >= MAX_SIZE) {
		return -1;
	}
	s->id = ++(*pCount);
	scoreList[*pCount] = s;
	return *pCount; 
}

bool removeScore(int id) {
	Score** scoreList = getScoreList();
	if (id < 0 || id >= MAX_SIZE || !scoreList[id]) {
		return false;
	}
	free(scoreList[id]);
	scoreList[id] = NULL;
	return true;
}

bool modifyScore(int id, Score *s) {
	Score** scoreList = getScoreList();
	if (id < 0 || id >= MAX_SIZE || !scoreList[id]) {
		return false;
	}
	free(scoreList[id]);
	s->id = id;
	scoreList[id] = s;
	return true;
}

Score* queryScore(int id) {
	Score** scoreList = getScoreList();
	if (id < 0 || id >= MAX_SIZE) {
		return NULL;
	}
	return scoreList[id];
}