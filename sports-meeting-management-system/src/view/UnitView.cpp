/*
Unit View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 单位管理 -\n");
	printf("1. 添加单位信息\n");
	printf("2. 删除单位信息\n");
	printf("3. 修改单位信息\n");
	printf("4. 查询单位信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void addUnitView() {
	Unit *u = newUnit();
	system("cls");
	printf("- 添加单位信息 -\n");
	printf("请输入要添加的单位信息：\n");
	printf("项目名称：");
	scanf_s("%s", u->name, MAX_LENGTH);
	int id = addUnit(u);
	if (~id) {
		printf("添加成功^_^，ID：%d\n", id);
	}
	else {
		printf("添加失败\n");
	}
	system("pause");
}
 
static void removeUnitView() {
	int id;
	system("cls");
	printf("- 删除单位信息 -\n");
	printf("请输入要删除的单位ID：");
	scanf_s("%d", &id);
	bool ret = removeUnit(id);
	if (ret) {
		printf("删除成功^_^\n");
	}
	else {
		printf("删除失败\n");
	}
	system("pause");
}

static void modifyUnitView() {
	int id;
	Unit *u = newUnit();
	system("cls");
	printf("- 修改单位信息 -\n");
	printf("请输入要修改的单位ID：");
	scanf_s("%d", &id);
	if (!queryUnit(id)) {
		printf("未找到该单位\n");
		system("pause");
		return;
	}
	printf("请输入要修改的单位信息：\n");
	printf("项目名：");
	scanf_s("%s", u->name, MAX_LENGTH);
	bool ret = modifyUnit(id, u);
	if (ret) {
		printf("修改成功^_^\n");
	}
	else {
		printf("修改失败\n");
	}
	system("pause");
}

static void queryUnitView() {
	int id;
	system("cls");
	printf("- 查询单位信息 -\n");
	printf("请输入要查询的单位ID：");
	scanf_s("%d", &id);
	Unit *e = queryUnit(id);
	if (!e) {
		printf("未找到该单位\n");
		system("pause");
		return;
	}
	printf("项目ID：%d\n", e->id);
	printf("项目名称：%s\n", e->name);
	system("pause");
}

void unitView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			 addUnitView();
			break;
		case 2:
			 removeUnitView();
			break;
		case 3:
			 modifyUnitView();
			break;
		case 4:
			 queryUnitView();
			break;
		case 0:
			return;
			break;
		default:
			printf("未知指令\n");
			system("pause");
		}
	} while (op != 0);
}