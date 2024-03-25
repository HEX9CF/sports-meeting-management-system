/*
Order Book View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ������Զ����� -\n");
	printf("1. �����Ԥ��\n");
	printf("2. ���������\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void previewOrderBook() {
	system("cls");
	int *eventCount = getEventCount();

	for (int i = 1; i <= *eventCount; i++) {
		Event *e = queryEvent(i);
		printf("������Ŀ��%s\n", e->name);
		printf("�������ͣ�%s\n", getEventTypeStr(e));
		printf("�Ա��޶���%s\n", getEventGenderStr(e));
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		printf("����ʱ�䣺%s\n", datetime);
		printf("�����ص㣺%s\n", e->location);
		printf("\n");
	} 
	system("pause");
}

static void saveOrderBook() {
	system("cls");
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
			 previewOrderBook();
			break;
		case '2':
			 saveOrderBook();
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