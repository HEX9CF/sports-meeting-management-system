/*
Score View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- �ɼ����� -\n");
	printf("1. ��ӳɼ���Ϣ\n");
	printf("2. ɾ���ɼ���Ϣ\n");
	printf("3. �޸ĳɼ���Ϣ\n");
	printf("4. ���ݳɼ�ID��ѯ�����ɼ�\n");
	printf("5. ���ݱ�����ĿID��ѯ�����ɼ�\n");
	printf("6. ���ݲ�����λID��ѯ�����ɼ��������ܵ�λ�ܷ�\n");
	printf("7. ���ݲ����˶�ԱID��ѯ�����ɼ����������˶�Ա�ܷ�\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void addScoreView() {
	Score *s = newScore();
	system("cls");
	printf("- ��ӳɼ���Ϣ -\n");
	printf("������Ҫ��ӵĳɼ���Ϣ��\n");
	int participationId;
	printf("������ϢID��");
	scanf_s("%d", &participationId);
	if (!queryParticipation(participationId)) { 
		printf("�������󣬲�����Ϣ������\n");
		system("pause");
		return;
	}
	s->participationId = participationId;
	printf("������");
	scanf_s("%lf", &(s->score));
	printf("������");
	scanf_s("%d", &(s->rank)); 
	int id = addScore(s);
	if (~id) {
		printf("��ӳɹ�^_^��ID��%d\n", id);
	}
	else {
		printf("���ʧ��\n");
	}
	system("pause");
}
 
static void removeScoreView() {
	int id;
	system("cls");
	printf("- ɾ���ɼ���Ϣ -\n");
	printf("9. ������Ŀ���ܱ����ɼ�\n");
	printf("������Ҫɾ���ĳɼ�ID��");
	scanf_s("%d", &id);
	bool ret = removeScore(id);
	if (ret) {
		printf("ɾ���ɹ�^_^\n");
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	system("pause");
}

static void modifyScoreView() {
	int id;
	system("cls");
	printf("- �޸ĳɼ���Ϣ -\n");
	printf("������Ҫ�޸ĵĳɼ�ID��");
	scanf_s("%d", &id);
	if (!queryScore(id)) {
		printf("δ�ҵ��óɼ�\n");
		system("pause");
		return;
	}
	Score *s = newScore();
	printf("������Ҫ�޸ĵĳɼ���Ϣ��\n");
	int participationId;
	printf("������ϢID��");
	scanf_s("%d", &participationId);
	if (!queryParticipation(participationId)) {
		printf("�������󣬲�����Ϣ������\n");
		system("pause");
		return;
	}
	s->participationId = participationId;
	printf("������");
	scanf_s("%lf", &(s->score));
	printf("������");
	scanf_s("%d", &(s->rank)); 
	bool ret = modifyScore(id, s);
	if (ret) {
		printf("�޸ĳɹ�^_^\n");
	}
	else {
		printf("�޸�ʧ��\n");
	}
	system("pause");
}

static void queryScoreView() {
	int id;
	system("cls");
	printf("- ���ݳɼ�ID��ѯ�����ɼ� -\n");
	printf("������Ҫ��ѯ�ĳɼ�ID��");
	scanf_s("%d", &id);
	Score *s = queryScore(id);
	if (!s) {
		printf("�������󣬳ɼ�������\n");
		system("pause");
		return;
	}
	printf("�ɼ�ID��%d\n", s->id);
	printf("������ϢID��%d\n", s->participationId);
	printf("������%lf\n", s->score);
	printf("������%d\n", s->rank);
	system("pause");
}

static void queryScoreByEventIdView() {
	int eventId;
	system("cls");
	printf("- ���ݱ�����ĿID��ѯ�����ɼ� -\n");
	printf("������Ҫ��ѯ�ı�����ĿID��");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("�������󣬱�����Ŀ������\n");
		system("pause");
		return;
	}
	printf("��Ŀ���ƣ�%s\n", queryEvent(eventId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		} 
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		if (p->eventId == eventId) {
			printf("�ɼ�ID��%d\n", s->id);
			printf("������ϢID��%d\n", s->participationId);
			printf("������%lf\n", s->score);
			printf("������%d\n", s->rank);
			printf("\n");
		}
	}
	system("pause");
}

static void queryScoreByUnitIdView() {
	int unitId;
	long double sum = 0;
	system("cls");
	printf("- ���ݲ�����λID��ѯ�����ɼ� -\n");
	printf("������Ҫ��ѯ�Ĳ�����λID��");
	scanf_s("%d", &unitId);
	if (!queryUnit(unitId)) {
		printf("�������󣬲�����λ������\n");
		system("pause");
		return;
	}
	printf("��λ���ƣ�%s\n", queryUnit(unitId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		}
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		Athlete *a = queryAthlete(p->athleteId);
		if (!a) {
			continue;
		}
		if (a->unitId == unitId) {
			sum += s->score;
			printf("�ɼ�ID��%d\n", s->id);
			printf("������ϢID��%d\n", s->participationId);
			printf("�˶�Ա������%s\n", a->name);
			printf("������%lf\n", s->score);
			printf("������%d\n", s->rank);
			printf("\n");
		}
	}
	printf("��λ�ܷ֣�%lf\n", sum);
	system("pause");
}

static void queryScoreByAthleteIdView() {
	int athleteId;
	long double sum = 0;
	system("cls");
	printf("- ���ݲ����˶�ԱID��ѯ�����ɼ� -\n");
	printf("������Ҫ��ѯ�Ĳ����˶�ԱID��");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("�������󣬲����˶�Ա������\n");
		system("pause");
		return;
	}
	printf("�˶�Ա������%s\n", queryAthlete(athleteId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		}
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		if (p->athleteId == athleteId) {
			sum += s->score;
			printf("�ɼ�ID��%d\n", s->id);
			printf("������ϢID��%d\n", s->participationId);
			printf("������%lf\n", s->score);
			printf("������%d\n", s->rank);
			printf("\n");
		}
	}
	printf("�˶�Ա�ܷ֣�%lf\n", sum);
	system("pause");	
}

void scoreView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			 addScoreView();
			break;
		case '2':
			 removeScoreView();
			break;
		case '3':
			 modifyScoreView();
			break;
		case '4':
			 queryScoreView();
			break;
		case '5':
			queryScoreByEventIdView();
			break;
		case '6':
			queryScoreByUnitIdView();
			break;
		case '7':
			queryScoreByAthleteIdView();
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