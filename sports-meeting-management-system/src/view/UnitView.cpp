/*
Unit View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ��λ���� -\n");
	printf("1. ��ӵ�λ��Ϣ\n");
	printf("2. ɾ����λ��Ϣ\n");
	printf("3. �޸ĵ�λ��Ϣ\n");
	printf("4. ��ѯ��λ��Ϣ\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void addUnitView() {
	Unit *u = newUnit();
	system("cls");
	printf("- ��ӵ�λ��Ϣ -\n");
	printf("������Ҫ��ӵĵ�λ��Ϣ��\n");
	printf("��Ŀ���ƣ�");
	scanf_s("%s", u->name, MAX_LENGTH);
	int id = addUnit(u);
	if (~id) {
		printf("��ӳɹ�^_^��ID��%d\n", id);
	}
	else {
		printf("���ʧ��\n");
	}
	system("pause");
}
 
static void removeUnitView() {
	int id;
	system("cls");
	printf("- ɾ����λ��Ϣ -\n");
	printf("������Ҫɾ���ĵ�λID��");
	scanf_s("%d", &id);
	bool ret = removeUnit(id);
	if (ret) {
		printf("ɾ���ɹ�^_^\n");
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	system("pause");
}

static void modifyUnitView() {
	int id;
	Unit *u = newUnit();
	system("cls");
	printf("- �޸ĵ�λ��Ϣ -\n");
	printf("������Ҫ�޸ĵĵ�λID��");
	scanf_s("%d", &id);
	if (!queryUnit(id)) {
		printf("δ�ҵ��õ�λ\n");
		system("pause");
		return;
	}
	printf("������Ҫ�޸ĵĵ�λ��Ϣ��\n");
	printf("��Ŀ����");
	scanf_s("%s", u->name, MAX_LENGTH);
	bool ret = modifyUnit(id, u);
	if (ret) {
		printf("�޸ĳɹ�^_^\n");
	}
	else {
		printf("�޸�ʧ��\n");
	}
	system("pause");
}

static void queryUnitView() {
	int id;
	system("cls");
	printf("- ��ѯ��λ��Ϣ -\n");
	printf("������Ҫ��ѯ�ĵ�λID��");
	scanf_s("%d", &id);
	Unit *e = queryUnit(id);
	if (!e) {
		printf("δ�ҵ��õ�λ\n");
		system("pause");
		return;
	}
	printf("��ĿID��%d\n", e->id);
	printf("��Ŀ���ƣ�%s\n", e->name);
	system("pause");
}

void unitView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			 addUnitView();
			break;
		case 2:
			 removeUnitView();
			break;
		case 3:
			 modifyUnitView();
			break;
		case 4:
			 queryUnitView();
			break;
		case 0:
			return;
			break;
		default:
			printf("δָ֪��\n");
			system("pause");
		}
	} while (op != 0);
}