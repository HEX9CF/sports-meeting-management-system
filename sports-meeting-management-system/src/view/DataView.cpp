/*
Data View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- ���ݵ��뵼�� -\n");
	printf("1. ���ļ���������\n");
	printf("2. �������ݵ��ļ�\n");
	printf("0. �����ϼ��˵�\n");
	printf("������ָ�");
}

static void dataImportView()
{
	system("cls");
	bool ret = importData();
	if (ret)
	{
		printf("����ɹ�^_^\n");
	}
	else
	{
		printf("����ʧ��\n");
	}
	system("pause");
}

static void dataExportView()
{
	system("cls");
	bool ret = exportData();
	if (ret)
	{
		printf("�����ɹ�^_^\n");
	}
	else
	{
		printf("����ʧ��\n");
	}
	system("pause");
}

void dataView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			dataImportView();
			break;
		case '2':
			dataExportView();
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
