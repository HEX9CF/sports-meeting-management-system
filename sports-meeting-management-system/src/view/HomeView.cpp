#include "../../include/main.h"

 static void printMenu() {
	system("cls");
	printf("- 运动会管理系统 -\n");
	printf("1. 参赛项目管理\n");
	printf("2. 运动员信息管理\n");
	printf("3. 参赛信息管理\n");
	printf("4. 秩序册自动生成\n");
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
			printf("参赛项目管理\n");
			break;
		case 2:
			athleteView();
			break;
		case 3:
			printf("参赛信息管理\n");
			break;
		case 4:
			printf("秩序册自动生成\n");
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