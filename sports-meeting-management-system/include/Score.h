/*
Score Header
*/
#ifndef SCORE_H
#define SCORE_H

typedef struct {
	int id; // PK
	int participationId; // FK
	double score;
	int rank;
}Score;

// view
void scoreView();

// controller
int addScore(Score *a);
bool removeScore(int id);
bool modifyScore(int id, Score *a);
Score* queryScore(int id);

// model
Score* newScore();
Score** getScoreList(); 
int* getScoreCount();
#endif
