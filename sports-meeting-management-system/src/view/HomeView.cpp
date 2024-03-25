/*
Home View
*/
#include "../../include/main.h"

 static void printMenu() {
	system("cls");
	printf("- 运动会管理系统 -\n");
	printf("1. 比赛项目管理\n");
	printf("2. 运动员信息管理\n");
	printf("3. 单位信息管理\n");
	printf("4. 参赛信息管理\n");
	printf("5. 秩序册自动生成\n");
	printf("6. 比赛成绩管理\n");
	printf("7. 系统信息备份\n");
	printf("0. 退出系统\n");
	printf("请输入指令：");
}
 
void homeView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			eventView();
			break;
		case 2:
			athleteView();
			break;
		case 3:
			printf("单位管理\n");
			break;
		case 4:
			printf("参赛信息管理\n");
			break;
		case 5:
			printf("秩序册自动生成\n");
			break;
		case 6:
			printf("比赛成绩管理\n");
			break;
		case 7:
			printf("系统信息备份\n");
			break;
		case 0:
			printf("退出系统\n");
			system("pause");
			return;
			break;
		default:
			printf("未知指令\n");
		}
	} while (op != 0);
}