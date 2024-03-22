#include <stdio.h>
#include <stdlib.h>

static void printMenu() {
	system("cls");
	printf("- 运动员管理 -\n");
	printf("1. 添加运动员\n");
	printf("2. 删除运动员\n");
	printf("3. 修改运动员信息\n");
	printf("4. 查询运动员信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

int athleteView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			printf("添加运动员\n");
			break;
		case 2:
			printf("删除运动员\n");
			break;
		case 3:
			printf("修改运动员信息\n");
			break;
		case 4:
			printf("查询运动员信息\n");
			break;
		case 0:
			printf("返回上级菜单\n");
			return 1;
			break;
		default:
			printf("未知指令\n");
		}
	} while (op != 0);
	return 1;
}