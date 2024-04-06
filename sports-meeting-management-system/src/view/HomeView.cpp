/*
Home View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 运动会管理系统 -\n");
	printf("1. 单位信息管理\n");
	printf("2. 运动员信息管理\n");
	printf("3. 比赛项目管理\n");
	printf("4. 参赛信息管理\n");
	printf("5. 秩序册自动生成\n");
	printf("6. 比赛成绩管理\n");
	printf("7. 数据导入导出\n");
	printf("8. 系统控制面板\n");
	printf("0. 退出管理系统\n");
	printf("请输入指令：");
}
 
void homeView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			unitView();
			break;
		case '2':
			athleteView();
			break;
		case '3':
			eventView();
			break;
		case '4':
			participationView();
			break;
		case '5':
			orderBookView();
			break;
		case '6':
			scoreView();
			break;
		case '7':
			dataView();
			break;
		case '8':
			settingView();
			break;
		case '0':
			printf("退出系统\n");
			system("pause");
			return;
			break;
		default:
			printf("未知指令\n");
			system("pause");
		}
	} while (1);
}