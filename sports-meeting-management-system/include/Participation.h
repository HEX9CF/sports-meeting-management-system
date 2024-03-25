/*
Participation Header
*/
#ifndef PARTICIPATION_H
#define PARTICIPATION_H

typedef struct {
	int id;
	int eventId;
	int athleteId; 
}Participation;

// view
void participationView();

// controller
int addParticipation(Participation *a);
bool removeParticipation(int id);
bool modifyParticipation(int id, Participation *a);
Participation* queryParticipation(int id);

// model
Participation* newParticipation();
Participation** getParticipationList(); 
int* getParticipationCount();
#endif
