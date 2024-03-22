#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../include/Athlete.h"
#include "../include/Event.h"
#include "../include/Unit.h"

static void printMenu() {
	system("cls");
	printf("- 运动会管理系统 -\n");
	printf("1. 参赛项目发布\n");
	printf("2. 运动员管理\n");
	printf("3. 参赛信息查询\n");
	printf("4. 秩序册自动生成\n");
	printf("0. 退出系统\n");
	printf("请输入指令：");
}

int main() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			printf("参赛项目发布\n");
			break;
		case 2:
			athleteView();
			break;
		case 3:
			printf("参赛信息查询\n");
			break;
		case 4:
			printf("秩序册自动生成\n");
			break;
		case 0:
			printf("退出系统\n");
			system("pause");
			return 0;
			break;
		default:
			printf("未知指令\n");
		}
	} while (op != 0);
	return 0;
}