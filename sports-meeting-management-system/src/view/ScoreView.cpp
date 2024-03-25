/*
Score View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 成绩管理 -\n");
	printf("1. 添加成绩信息\n");
	printf("2. 删除成绩信息\n");
	printf("3. 修改成绩信息\n");
	printf("4. 查询成绩信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void addScoreView() {
	Score *s = newScore();
	system("cls");
	printf("- 添加成绩信息 -\n");
	printf("请输入要添加的成绩信息：\n");
	int participationId;
	printf("参赛信息ID：");
	scanf_s("%d", &participationId);
	if (!queryParticipation(participationId)) { 
		printf("发生错误，参赛信息不存在\n");
		system("pause");
		return;
	}
	s->participationId = participationId;
	printf("分数：");
	scanf_s("%lf", &(s->score));
	printf("排名：");
	scanf_s("%d", &(s->rank)); 
	int id = addScore(s);
	if (~id) {
		printf("添加成功^_^，ID：%d\n", id);
	}
	else {
		printf("添加失败\n");
	}
	system("pause");
}
 
static void removeScoreView() {
	int id;
	system("cls");
	printf("- 删除成绩信息 -\n");
	printf("请输入要删除的成绩ID：");
	scanf_s("%d", &id);
	bool ret = removeScore(id);
	if (ret) {
		printf("删除成功^_^\n");
	}
	else {
		printf("删除失败\n");
	}
	system("pause");
}

static void modifyScoreView() {
	int id;
	system("cls");
	printf("- 修改成绩信息 -\n");
	printf("请输入要修改的成绩ID：");
	scanf_s("%d", &id);
	if (!queryScore(id)) {
		printf("未找到该成绩\n");
		system("pause");
		return;
	}
	Score *s = newScore();
	printf("请输入要修改的成绩信息：\n");
	int participationId;
	printf("参赛信息ID：");
	scanf_s("%d", &participationId);
	if (!queryParticipation(participationId)) {
		printf("发生错误，参赛信息不存在\n");
		system("pause");
		return;
	}
	s->participationId = participationId;
	printf("分数：");
	scanf_s("%lf", &(s->score));
	printf("排名：");
	scanf_s("%d", &(s->rank)); 
	bool ret = modifyScore(id, s);
	if (ret) {
		printf("修改成功^_^\n");
	}
	else {
		printf("修改失败\n");
	}
	system("pause");
}

static void queryScoreView() {
	int id;
	system("cls");
	printf("- 查询成绩信息 -\n");
	printf("请输入要查询的成绩ID：");
	scanf_s("%d", &id);
	Score *s = queryScore(id);
	if (!s) {
		printf("未找到该成绩\n");
		system("pause");
		return;
	}
	printf("成绩ID：%d\n", s->id);
	printf("参赛信息ID：%d\n", s->participationId);
	printf("分数：%lf\n", s->score);
	printf("排名：%d\n", s->rank);
	system("pause");
}

void scoreView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			 addScoreView();
			break;
		case '2':
			 removeScoreView();
			break;
		case '3':
			 modifyScoreView();
			break;
		case '4':
			 queryScoreView();
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