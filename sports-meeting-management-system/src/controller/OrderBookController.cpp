/*
Order Book Controller
*/
#include "../../include/main.h"

bool exportOrderBook()
{
	FILE* file;
	fopen_s(&file, "orderBook.txt", "w");
	if (!file)
	{
		return false;
	}
	const int eventCount = *getEventCount();
	fprintf(file, "- 运动会秩序册 -\n");
	for (int i = 1; i <= eventCount; i++) {
		Event* e = queryEvent(i);
		if (!e) {
			continue;
		}
		fprintf(file, "项目ID：%d\n", e->id);
		fprintf(file, "项目名称：%s\n", e->name);
		fprintf(file, "比赛类型：%s\n", getEventGenderStr(e));
		fprintf(file, "性别限定：%s\n", getEventTypeStr(e));
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		fprintf(file, "比赛时间：%s\n", datetime);
		fprintf(file, "比赛场地：%s\n", e->location);
		// 运动员名单
		fprintf(file, "运动员名单：");
		const int participationCount = *getParticipationCount();
		for (int i = 1; i <= participationCount; i++) {
			Participation* p = queryParticipation(i);
			if (!p) {
				continue;
			}
			if (p->eventId == e->id) {
				Athlete* a = queryAthlete(p->athleteId);
				if (!a) {
					continue;
				}
				fprintf(file, "%s ", a->name);
			}
		}
		fprintf(file, "\n");
		fprintf(file, "\n");
	}
	fclose(file);
	return true;
}