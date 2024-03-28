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
	bool ret = 1;
	do
	{
		ret = exportUnitData();
		if (ret)
		{
			printf("��λ��Ϣ�����ɹ����ļ�����unit.csv\n");
		}
		else
		{
			printf("��λ��Ϣ����ʧ��\n");
			break;
		}
		ret = exportEventData();
		if (ret)
		{
			printf("������Ŀ�����ɹ����ļ�����event.csv\n");
		}
		else
		{
			printf("������Ŀ����ʧ��\n");
			break;
		}
		ret = exportAthleteData();
		if (ret)
		{
			printf("�˶�Ա��Ϣ�����ɹ����ļ�����athlete.csv\n");
		}
		else
		{
			printf("�˶�Ա��Ϣ����ʧ��\n");
			break;
		}
		// ret = exportParticipationData();
		// if (ret)
		// {
		// 	printf("������Ϣ�����ɹ����ļ�����participation.csv\n");
		// }
		// else
		// {
		// 	printf("������Ϣ����ʧ��\n");
		// 	break;
		// }
		// ret = exportScoreData();
		// if (ret)
		// {
		// 	printf("�ɼ���Ϣ�����ɹ����ļ�����score.csv\n");
		// }
		// else
		// {
		// 	printf("�ɼ���Ϣ����ʧ��\n");
		// 	break;
		// }
	} while (0);
	if (ret)
	{
		printf("�����ļ������ɹ�^_^\n");
	}
	else
	{
		printf("�������󣬵���ʧ��\n");
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
