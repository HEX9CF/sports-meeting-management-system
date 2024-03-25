/*
Event View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ������Ŀ���� -\n");
	printf("1. ��ӱ�����Ŀ��Ϣ\n");
	printf("2. ɾ��������Ŀ��Ϣ\n");
	printf("3. �޸ı�����Ŀ��Ϣ\n");
	printf("4. ��ѯ������Ŀ��Ϣ\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void addEventView() {
	Event* e = newEvent();
	system("cls");
	printf("- ��ӱ�����Ŀ��Ϣ -\n");
	printf("������Ҫ��ӵı�����Ŀ��Ϣ��\n");
	printf("��Ŀ���ƣ�");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("��Ŀ���ͣ�0.δ֪��1.������2.������3.��������");
	scanf_s("%d", &(e->type));
	printf("�Ա��޶���0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ���");
	scanf_s("%d", &(e->gender));
	printf("����ʱ�䣨��-��-�� ʱ:��:�룩��");
	scanf_s("%d-%d-%d %d:%d:%d", &e->datetime.tm_year, &e->datetime.tm_mon, &e->datetime.tm_mday,
		&e->datetime.tm_hour, &e->datetime.tm_min, &e->datetime.tm_sec);
	e->datetime.tm_year -= 1900;
	e->datetime.tm_mon -= 1;
	int id = addEvent(e);
	if (~id) {
		printf("��ӳɹ�^_^��ID��%d\n", id);
	}
	else {
		printf("���ʧ��\n");
	}
	system("pause");
}

static void removeEventView() {
	int id;
	system("cls");
	printf("- ɾ��������Ŀ��Ϣ -\n");
	printf("������Ҫɾ���ı�����ĿID��");
	scanf_s("%d", &id);
	bool ret = removeEvent(id);
	if (ret) {
		printf("ɾ���ɹ�^_^\n");
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	system("pause");
}

static void modifyEventView() {
	int id;
	system("cls");
	printf("- �޸ı�����Ŀ��Ϣ -\n");
	printf("������Ҫ�޸ĵı�����ĿID��");
	scanf_s("%d", &id);
	if (!queryEvent(id)) {
		printf("δ�ҵ��ñ�����Ŀ\n");
		system("pause");
		return;
	}
	Event* e = newEvent();
	printf("������Ҫ�޸ĵı�����Ŀ��Ϣ��\n");
	printf("��Ŀ����");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("��Ŀ���ͣ�0.δ֪��1.������2.������3.��������");
	scanf_s("%d", &(e->type));
	printf("�Ա��޶���0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ���");
	scanf_s("%d", &(e->gender));
	printf("����ʱ�䣨��-��-�� ʱ:��:�룩��");
	scanf_s("%d-%d-%d %d:%d:%d", &e->datetime.tm_year, &e->datetime.tm_mon, &e->datetime.tm_mday,
		&e->datetime.tm_hour, &e->datetime.tm_min, &e->datetime.tm_sec);
	e->datetime.tm_year -= 1900;
	e->datetime.tm_mon -= 1;
	bool ret = modifyEvent(id, e);
	if (ret) {
		printf("�޸ĳɹ�^_^\n");
	}
	else {
		printf("�޸�ʧ��\n");
	}
	system("pause");
}

static void queryEventView() {
	int id;
	system("cls");
	printf("- ��ѯ������Ŀ��Ϣ -\n");
	printf("������Ҫ��ѯ�ı�����ĿID��");
	scanf_s("%d", &id);
	Event* e = queryEvent(id);
	if (!e) {
		printf("δ�ҵ��ñ�����Ŀ\n");
		system("pause");
		return;
	}
	printf("��ĿID��%d\n", e->id);
	printf("��Ŀ���ƣ�%s\n", e->name);
	printf("��Ŀ���ͣ�%d��0.δ֪��1.������2.������3.������\n", e->type);
	printf("�Ա��޶���%d��0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ�\n", e->gender);
	char datetime[20];
	strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
	printf("����ʱ�䣺%s\n", datetime);
	system("pause");
}

void eventView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			addEventView();
			break;
		case '2':
			removeEventView();
			break;
		case '3':
			modifyEventView();
			break;
		case '4':
			queryEventView();
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