/*
Event View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 比赛项目管理 -\n");
	printf("1. 添加比赛项目信息\n");
	printf("2. 删除比赛项目信息\n");
	printf("3. 修改比赛项目信息\n");
	printf("4. 查询比赛项目信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void addEventView() {
	Event* e = newEvent();
	system("cls");
	printf("- 添加比赛项目信息 -\n");
	printf("请输入要添加的比赛项目信息：\n");
	printf("项目名称：");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("项目类型（0.未知，1.田赛，2.竞赛，3.其他）：");
	scanf_s("%d", &(e->type));
	printf("性别限定（0.未知，1.男子，2.女子，3.其他，4.混合）：");
	scanf_s("%d", &(e->gender));
	printf("比赛时间（年-月-日 时:分:秒）：");
	scanf_s("%d-%d-%d %d:%d:%d", &e->datetime.tm_year, &e->datetime.tm_mon, &e->datetime.tm_mday,
		&e->datetime.tm_hour, &e->datetime.tm_min, &e->datetime.tm_sec);
	e->datetime.tm_year -= 1900;
	e->datetime.tm_mon -= 1;
	int id = addEvent(e);
	if (~id) {
		printf("添加成功^_^，ID：%d\n", id);
	}
	else {
		printf("添加失败\n");
	}
	system("pause");
}

static void removeEventView() {
	int id;
	system("cls");
	printf("- 删除比赛项目信息 -\n");
	printf("请输入要删除的比赛项目ID：");
	scanf_s("%d", &id);
	bool ret = removeEvent(id);
	if (ret) {
		printf("删除成功^_^\n");
	}
	else {
		printf("删除失败\n");
	}
	system("pause");
}

static void modifyEventView() {
	int id;
	system("cls");
	printf("- 修改比赛项目信息 -\n");
	printf("请输入要修改的比赛项目ID：");
	scanf_s("%d", &id);
	if (!queryEvent(id)) {
		printf("未找到该比赛项目\n");
		system("pause");
		return;
	}
	Event* e = newEvent();
	printf("请输入要修改的比赛项目信息：\n");
	printf("项目名：");
	scanf_s("%s", e->name, MAX_LENGTH);
	printf("项目类型（0.未知，1.田赛，2.竞赛，3.其他）：");
	scanf_s("%d", &(e->type));
	printf("性别限定（0.未知，1.男子，2.女子，3.其他，4.混合）：");
	scanf_s("%d", &(e->gender));
	printf("比赛时间（年-月-日 时:分:秒）：");
	scanf_s("%d-%d-%d %d:%d:%d", &e->datetime.tm_year, &e->datetime.tm_mon, &e->datetime.tm_mday,
		&e->datetime.tm_hour, &e->datetime.tm_min, &e->datetime.tm_sec);
	e->datetime.tm_year -= 1900;
	e->datetime.tm_mon -= 1;
	bool ret = modifyEvent(id, e);
	if (ret) {
		printf("修改成功^_^\n");
	}
	else {
		printf("修改失败\n");
	}
	system("pause");
}

static void queryEventView() {
	int id;
	system("cls");
	printf("- 查询比赛项目信息 -\n");
	printf("请输入要查询的比赛项目ID：");
	scanf_s("%d", &id);
	Event* e = queryEvent(id);
	if (!e) {
		printf("未找到该比赛项目\n");
		system("pause");
		return;
	}
	printf("项目ID：%d\n", e->id);
	printf("项目名称：%s\n", e->name);
	printf("项目类型：%d（0.未知，1.田赛，2.竞赛，3.其他）\n", e->type);
	printf("性别限定：%d（0.未知，1.男子，2.女子，3.其他，4.混合）\n", e->gender);
	char datetime[20];
	strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", &e->datetime);
	printf("比赛时间：%s\n", datetime);
	system("pause");
}

void eventView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			addEventView();
			break;
		case '2':
			removeEventView();
			break;
		case '3':
			modifyEventView();
			break;
		case '4':
			queryEventView();
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