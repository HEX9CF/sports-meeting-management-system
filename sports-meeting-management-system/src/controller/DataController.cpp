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
