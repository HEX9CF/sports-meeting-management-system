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
	printf("4. ��ѯ�ɼ���Ϣ\n");
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
	printf("- ��ѯ�ɼ���Ϣ -\n");
	printf("������Ҫ��ѯ�ĳɼ�ID��");
	scanf_s("%d", &id);
	Score *s = queryScore(id);
	if (!s) {
		printf("δ�ҵ��óɼ�\n");
		system("pause");
		return;
	}
	printf("�ɼ�ID��%d\n", s->id);
	printf("������ϢID��%d\n", s->participationId);
	printf("������%lf\n", s->score);
	printf("������%d\n", s->rank);
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
		case '0':
			return;
			break;
		default:
			printf("δָ֪��\n");
			system("pause");
		}
	} while (1);
}