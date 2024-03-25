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
	Event *e = newEvent();
	system("cls");
	printf("- ��ӱ�����Ŀ��Ϣ -\n");
	printf("������Ҫ��ӵı�����Ŀ��Ϣ��\n");
	printf("��Ŀ���ƣ�");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("��Ŀ���ͣ�0.δ֪��1.������2.������3.��������");
	scanf_s("%d", &(e->type));
	printf("�Ա��޶���0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ���");
	scanf_s("%d", &(e->gender));
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
	Event *e = newEvent();
	system("cls");
	printf("- �޸ı�����Ŀ��Ϣ -\n");
	printf("������Ҫ�޸ĵı�����ĿID��");
	scanf_s("%d", &id);
	if (!queryEvent(id)) {
		printf("δ�ҵ��ñ�����Ŀ\n");
		system("pause");
		return;
	}
	printf("������Ҫ�޸ĵı�����Ŀ��Ϣ��\n");
	printf("��Ŀ����");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("��Ŀ���ͣ�0.δ֪��1.������2.������3.��������");
	scanf_s("%d", &(e->type));
	printf("�Ա��޶���0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ���");
	scanf_s("%d", &(e->gender));
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
	Event *a = queryEvent(id);
	if (!a) {
		printf("δ�ҵ��ñ�����Ŀ\n");
		system("pause");
		return;
	}
	printf("��ĿID��%d\n", a->id);
	printf("��Ŀ���ƣ�%s\n", a->name);
	printf("��Ŀ���ͣ�0.δ֪��1.������2.������3.��������%d\n", a->type);
	printf("�Ա��޶���0.δ֪��1.���ӣ�2.Ů�ӣ�3.������4.��ϣ���%d\n", a->gender);
	system("pause");
}

void eventView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			 addEventView();
			break;
		case 2:
			 removeEventView();
			break;
		case 3:
			 modifyEventView();
			break;
		case 4:
			 queryEventView();
			break;
		case 0:
			return;
			break;
		default:
			printf("δָ֪��\n");
		}
	} while (op != 0);
}