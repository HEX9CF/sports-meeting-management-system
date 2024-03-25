/*
Order Book View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 秩序册自动生成 -\n");
	printf("1. 秩序册预览\n");
	printf("2. 保存秩序册\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void previewOrderBook() {
	system("cls");
	int *eventCount = getEventCount();

	for (int i = 1; i <= *eventCount; i++) {
		Event *e = queryEvent(i);
		printf("比赛项目：%s\n", e->name);
		printf("比赛类型：%s\n", getEventTypeStr(e));
		printf("性别限定：%s\n", getEventGenderStr(e));
		char datetime[20];
		strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
		printf("比赛时间：%s\n", datetime);
		printf("比赛地点：%s\n", e->location);
		printf("\n");
	} 
	system("pause");
}

static void saveOrderBook() {
	system("cls");
	system("pause");
}
 
void orderBookView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			 previewOrderBook();
			break;
		case '2':
			 saveOrderBook();
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