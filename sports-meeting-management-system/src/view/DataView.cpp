/*
Data View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 数据导入导出 -\n");
	printf("1. 从文件导入数据\n");
	printf("2. 导出数据到文件\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void dataImportView()
{
	system("cls");
	bool ret = importData();
	if (ret)
	{
		printf("导入成功^_^\n");
	}
	else
	{
		printf("导入失败\n");
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
			printf("单位信息导出成功，文件名：unit.csv\n");
		}
		else
		{
			printf("单位信息导出失败\n");
			break;
		}
		ret = exportEventData();
		if (ret)
		{
			printf("比赛项目导出成功，文件名：event.csv\n");
		}
		else
		{
			printf("比赛项目导出失败\n");
			break;
		}
		ret = exportAthleteData();
		if (ret)
		{
			printf("运动员信息导出成功，文件名：athlete.csv\n");
		}
		else
		{
			printf("运动员信息导出失败\n");
			break;
		}
		// ret = exportParticipationData();
		// if (ret)
		// {
		// 	printf("参赛信息导出成功，文件名：participation.csv\n");
		// }
		// else
		// {
		// 	printf("参赛信息导出失败\n");
		// 	break;
		// }
		// ret = exportScoreData();
		// if (ret)
		// {
		// 	printf("成绩信息导出成功，文件名：score.csv\n");
		// }
		// else
		// {
		// 	printf("成绩信息导出失败\n");
		// 	break;
		// }
	} while (0);
	if (ret)
	{
		printf("所有文件导出成功^_^\n");
	}
	else
	{
		printf("发生错误，导出失败\n");
	}
	system("pause");
}

void dataView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
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
			printf("未知指令\n");
			system("pause");
		}
	} while (1);
}
