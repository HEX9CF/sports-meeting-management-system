/*
Setting View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ϵͳ������� -\n");
	printf("1. ��ѯ����������\n");
	printf("2. �����˶�Ա��������Ŀ����\n");
	printf("3. ���ñ�����Ŀ��С��������\n");
	printf("4. ���óɼ�����ѡȡ����\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

// ��ѯ����������
static void queryAllSettings() {
	system("cls");
	printf("- ��ѯ���������� -\n");
	printf("�˶�Ա��������Ŀ������%d\n", MAX_ATHLETE_PARTICIPATION);
	printf("������Ŀ��С����������%d\n", MIN_EVENT_PARTICIPATION);
	printf("�ɼ�����ѡȡ����\n");
	for (int i = 0; i <= 1; i++) {
		printf("��%d������\n", i + 1);
		printf("�����������䣺%d-%d\n", RANKING_ATHLETE_RANGE[i][0], RANKING_ATHLETE_RANGE[i][1]);
		printf("����ѡȡ������%d\n", RANKING_SELECT_COUNT[i]);
		printf("���ε÷ֹ���\n");
		for (int j = 0; j < RANKING_SELECT_COUNT[i]; j++) {
			printf("��%d������%d��\n", j + 1, RANKING_SCORE_RULE[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

static void setAthleteMaxParticipation() {
	system("cls");
	printf("- �����˶�Ա��������Ŀ���� -\n");
	printf("�������˶�Ա��������Ŀ������");
	scanf_s("%d", &MAX_ATHLETE_PARTICIPATION);
	printf("���óɹ�^_^\n");
	system("pause");
}

static void setEventMinParticipation() {
	system("cls");
	printf("- ���ñ�����Ŀ��С�������� -\n");
	printf("�����������Ŀ��С����������");
	scanf_s("%d", &MIN_EVENT_PARTICIPATION);
	printf("���óɹ�^_^\n");
	system("pause");
}

static void setRankingRule() {
	system("cls");
	printf("- ���óɼ�����ѡȡ���� -\n");
	for (int i = 1; i <= 2; i++) {
		// ���ò�����������
		printf("�������%d���������С��������������������������2�����֣��ÿո��������", i);
		scanf_s("%d %d", &RANKING_ATHLETE_RANGE[i][0], &RANKING_ATHLETE_RANGE[i][1]);
		// ��������ѡȡ����
		printf("�������%d�����������ѡȡ������", i);
		scanf_s("%d", &RANKING_SELECT_COUNT[i]); 
		// �������ε÷�
		printf("�������%d����������ε÷֣�����%d�����֣��ÿո��������", i, RANKING_SELECT_COUNT[i]);
		for (int j = 1; j <= RANKING_SELECT_COUNT[i]; j++) {
			scanf_s("%d", &RANKING_SCORE_RULE[i][j]);
		}
	}
	printf("���óɹ�^_^\n");
	system("pause");
}
 
void settingView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			queryAllSettings();
			break;
		case '2':
			setAthleteMaxParticipation();
			break;
		case '3':
			setEventMinParticipation();
			break; 
		case '4':
			setRankingRule();
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
