/*
Participation View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ������Ϣ���� -\n");
	printf("1. ��Ӳ�����Ϣ\n");
	printf("2. ɾ��������Ϣ\n");
	printf("3. �޸Ĳ�����Ϣ\n");
	printf("4. ���ݲ�����ϢID��ѯ������Ϣ\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void addParticipationView() {
	Participation* p = newParticipation();
	system("cls");
	printf("- ��Ӳ�����Ϣ -\n");
	printf("������Ҫ��ӵĲ�����Ϣ��\n");
	int eventId, athleteId;
	printf("����ID��");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("�������󣬱���������\n");
		system("pause");
		return;
	}
	printf("�˶�ԱID��");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("���������˶�Ա������\n");
		system("pause");
		return;
	}
	// �����˶�Ա������Ŀ����
	int athleteParticipationCount = 0;
	int participationCount = *getParticipationCount();
	for (int i = 1; i <= participationCount; i++)
	{
		Participation* p = queryParticipation(i);
		if (p->athleteId == athleteId)
		{
			athleteParticipationCount++;
			if (p->eventId == eventId)
			{
				// ��ֹ�˶�Ա�ظ��μ�ͬһ��Ŀ
				printf("���˶�Ա�ѲμӸ���Ŀ�������ظ�����\n");
				system("pause");
				return;
			}
		}
	}
	if (athleteParticipationCount >= MAX_ATHLETE_PARTICIPATION)
	{
		printf("�˶�Ա������Ŀ�����Ѵ�����\n");
		system("pause");
		return;
	}
	p->eventId = eventId;
	p->athleteId = athleteId;
	int id = addParticipation(p);
	if (~id) {
		printf("��ӳɹ�^_^��ID��%d\n", id);
	}
	else {
		printf("���ʧ��\n");
	}
	system("pause");
}

static void removeParticipationView() {
	int id;
	system("cls");
	printf("- ɾ��������Ϣ -\n");
	printf("������Ҫɾ���Ĳ�����ϢID��");
	scanf_s("%d", &id);
	bool ret = removeParticipation(id);
	if (ret) {
		printf("ɾ���ɹ�^_^\n");
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	system("pause");
}

static void modifyParticipationView() {
	int id;
	system("cls");
	printf("- �޸Ĳ�����Ϣ -\n");
	printf("������Ҫ�޸ĵĲ�����ϢID��");
	scanf_s("%d", &id);
	if (!queryParticipation(id)) {
		printf("�������󣬲�����Ϣ������\n");
		system("pause");
		return;
	}
	Participation* p = newParticipation();
	printf("������Ҫ�޸ĵĲ�����Ϣ��\n");
	int eventId, athleteId;
	printf("����ID��");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("�������󣬱���������\n");
		system("pause");
		return;
	}
	printf("�˶�ԱID��");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("���������˶�Ա������\n");
		system("pause");
		return;
	}
	p->eventId = eventId;
	p->athleteId = athleteId;
	bool ret = modifyParticipation(id, p);
	if (ret) {
		printf("�޸ĳɹ�^_^\n");
	}
	else {
		printf("�޸�ʧ��\n");
	}
	system("pause");
}

static void queryParticipationView() {
	int id;
	system("cls");
	printf("- ��ѯ������Ϣ -\n");
	printf("������Ҫ��ѯ�Ĳ�����ϢID��");
	scanf_s("%d", &id);
	Participation* p = queryParticipation(id);
	if (!p) {
		printf("δ�ҵ��ò�����Ϣ\n");
		system("pause");
		return;
	}
	printf("������ϢID��%d\n", p->id);
	printf("����ID��%d\n", p->eventId);
	printf("�˶�ԱID��%d\n", p->athleteId);
	system("pause");
}

void participationView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			addParticipationView();
			break;
		case '2':
			removeParticipationView();
			break;
		case '3':
			modifyParticipationView();
			break;
		case '4':
			queryParticipationView();
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