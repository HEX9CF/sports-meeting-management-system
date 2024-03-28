/*
Data Controller
*/
#include "../../include/main.h"

bool importData()
{
	return false;
}

bool exportUnitData()
{
	FILE* file;
	fopen_s(&file, "unit.csv", "w");
	if (!file)
	{
		return false;
	}
	fprintf(file, "��λID, ��λ����\n");
	const int unitCount = *getUnitCount();
	for (int i = 0; i < unitCount; i++)
	{
		Unit* u = queryUnit(i);
		if (!u)
		{
			continue;
		}
		fprintf(file, "%d, %s\n", u->id, u->name);
	}
	fclose(file);
	return true;
}
 
bool exportEventData()
{
	FILE* file;
	fopen_s(&file, "event.csv", "w");
	if (!file)
	{
		return false;
	}
	fprintf(file, "��ĿID, ��Ŀ����, ��������, �Ա��޶�, ����ʱ��, ��������\n");
	const int eventCount = *getEventCount();
	for (int i = 0; i < eventCount; i++)
	{
		Event* e = queryEvent(i);
		if (!e)
		{
			continue;
		}
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		fprintf(file, "%d, %s, %s, %s, %s, %s\n", e->id, e->name, getEventGenderStr(e), getEventTypeStr(e), datetime, e->location);
	}
	fclose(file);
	return true;
}

bool exportAthleteData()
{
	FILE* file;
	fopen_s(&file, "athlete.csv", "w");
	if (!file)
	{
		return false;
	}
	fprintf(file, "�˶�ԱID, ����, �Ա�, ����, ��λID\n");
	const int athleteCount = *getAthleteCount();
	for (int i = 0; i < athleteCount; i++)
	{
				Athlete* a = queryAthlete(i);
		if (!a)
		{
			continue;
		}
		fprintf(file, "%d, %s, %s, %d, %d\n", a->id, a->name, getAthleteGenderStr(a), a->age, a->unitId);
	}
	fclose(file);
	return true;
}

bool exportParticipationData() {
	FILE* file;
	fopen_s(&file, "participation.csv", "w");
	if (!file)
	{
		return false;
	}
	fprintf(file, "����ID, �˶�ԱID, ��ĿID\n");
	const int participationCount = *getParticipationCount();
	for (int i = 0; i < participationCount; i++)
	{
		Participation* p = queryParticipation(i);
		if (!p)
		{
			continue;
		}
		fprintf(file, "%d, %d, %d\n", p->id, p->athleteId, p->eventId);
	}
	fclose(file);
	return true;
}

bool exportScoreData()
{
	FILE* file;
	fopen_s(&file, "score.csv", "w");
	if (!file)
	{
				return false;
	}
	fprintf(file, "�ɼ�ID, ������ϢID, ����, ����\n");
	const int scoreCount = *getScoreCount();
	for (int i = 0; i < scoreCount; i++)
	{
		Score* s = queryScore(i);
		if (!s)
		{
			continue;
		}
		fprintf(file, "%d, %d, %lf, %d\n", s->id, s->participationId, s->score, s->rank);
	}
	fclose(file);
	return true;
}
