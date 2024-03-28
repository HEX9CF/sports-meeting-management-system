/*
Order Book View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ������Զ����� -\n");
	printf("1. �����Ԥ��\n");
	printf("2. ��������ᵽ�ļ�\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void previewOrderBookView() {
	system("cls");
	// ������Ŀ
	const int eventCount = *getEventCount();
	printf("- �˶�������� -\n");
	for (int i = 1; i <= eventCount; i++) {
		Event* e = queryEvent(i);
		if (!e) {
			continue;
		}
		printf("��ĿID��%d\n", e->id);
		printf("��Ŀ���ƣ�%s\n", e->name);
		printf("�������ͣ�%s\n", getEventGenderStr(e));
		printf("�Ա��޶���%s\n", getEventTypeStr(e));
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		printf("����ʱ�䣺%s\n", datetime);
		printf("�������أ�%s\n", e->location);
		// �˶�Ա����
		printf("�˶�Ա������");
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
				printf("%s ", a->name);
			}
		}
		printf("\n");
		printf("\n");
	}
	system("pause");
}

static void exportOrderBookView() {
	system("cls");
	bool ret = exportOrderBook();
	if (ret)
	{
		printf("����ᵼ���ɹ����ļ�����orderBook.txt\n");
	}
	else
	{
		printf("����ʧ��\n");
	}
	system("pause");
}

void orderBookView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			previewOrderBookView();
			break;
		case '2':
			exportOrderBookView();
			break;
		case '0':
			return;
			break;
		default:
			printf("δָ֪��\n");
			system("pause");
		}
	} while (1);
}