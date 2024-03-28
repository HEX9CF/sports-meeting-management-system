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
	fprintf(file, "- �˶�������� -\n");
	for (int i = 1; i <= eventCount; i++) {
		Event* e = queryEvent(i);
		if (!e) {
			continue;
		}
		fprintf(file, "��ĿID��%d\n", e->id);
		fprintf(file, "��Ŀ���ƣ�%s\n", e->name);
		fprintf(file, "�������ͣ�%s\n", getEventGenderStr(e));
		fprintf(file, "�Ա��޶���%s\n", getEventTypeStr(e));
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		fprintf(file, "����ʱ�䣺%s\n", datetime);
		fprintf(file, "�������أ�%s\n", e->location);
		// �˶�Ա����
		fprintf(file, "�˶�Ա������");
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