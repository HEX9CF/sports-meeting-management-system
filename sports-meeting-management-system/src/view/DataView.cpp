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
	bool ret = exportData();
	if (ret)
	{
		printf("导出成功^_^\n");
	}
	else
	{
		printf("导出失败\n");
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
