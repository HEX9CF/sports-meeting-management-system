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
	fprintf(file, "单位ID, 单位名称\n");
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
	fprintf(file, "项目ID, 项目名称, 比赛类型, 性别限定, 比赛时间, 比赛场地\n");
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
	fprintf(file, "运动员ID, 姓名, 性别, 年龄, 单位ID\n");
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
