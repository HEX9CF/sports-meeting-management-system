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
	printf("4. 根据成绩ID查询比赛成绩\n");
	printf("5. 根据比赛项目ID查询比赛成绩\n");
	printf("6. 根据参赛单位ID查询比赛成绩，并汇总单位总分\n");
	printf("7. 根据参赛运动员ID查询比赛成绩，并汇总运动员总分\n");
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
	printf("9. 根据项目汇总比赛成绩\n");
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
	printf("- 根据成绩ID查询比赛成绩 -\n");
	printf("请输入要查询的成绩ID：");
	scanf_s("%d", &id);
	Score *s = queryScore(id);
	if (!s) {
		printf("发生错误，成绩不存在\n");
		system("pause");
		return;
	}
	printf("成绩ID：%d\n", s->id);
	printf("参赛信息ID：%d\n", s->participationId);
	printf("分数：%lf\n", s->score);
	printf("排名：%d\n", s->rank);
	system("pause");
}

static void queryScoreByEventIdView() {
	int eventId;
	system("cls");
	printf("- 根据比赛项目ID查询比赛成绩 -\n");
	printf("请输入要查询的比赛项目ID：");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("发生错误，比赛项目不存在\n");
		system("pause");
		return;
	}
	printf("项目名称：%s\n", queryEvent(eventId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		} 
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		if (p->eventId == eventId) {
			printf("成绩ID：%d\n", s->id);
			printf("参赛信息ID：%d\n", s->participationId);
			printf("分数：%lf\n", s->score);
			printf("排名：%d\n", s->rank);
			printf("\n");
		}
	}
	system("pause");
}

static void queryScoreByUnitIdView() {
	int unitId;
	long double sum = 0;
	system("cls");
	printf("- 根据参赛单位ID查询比赛成绩 -\n");
	printf("请输入要查询的参赛单位ID：");
	scanf_s("%d", &unitId);
	if (!queryUnit(unitId)) {
		printf("发生错误，参赛单位不存在\n");
		system("pause");
		return;
	}
	printf("单位名称：%s\n", queryUnit(unitId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		}
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		Athlete *a = queryAthlete(p->athleteId);
		if (!a) {
			continue;
		}
		if (a->unitId == unitId) {
			sum += s->score;
			printf("成绩ID：%d\n", s->id);
			printf("参赛信息ID：%d\n", s->participationId);
			printf("运动员姓名：%s\n", a->name);
			printf("分数：%lf\n", s->score);
			printf("排名：%d\n", s->rank);
			printf("\n");
		}
	}
	printf("单位总分：%lf\n", sum);
	system("pause");
}

static void queryScoreByAthleteIdView() {
	int athleteId;
	long double sum = 0;
	system("cls");
	printf("- 根据参赛运动员ID查询比赛成绩 -\n");
	printf("请输入要查询的参赛运动员ID：");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("发生错误，参赛运动员不存在\n");
		system("pause");
		return;
	}
	printf("运动员姓名：%s\n", queryAthlete(athleteId)->name);
	printf("\n");
	int *scoreCount = getScoreCount();
	for (int i = 1; i <= *scoreCount; i++) {
		Score *s = queryScore(i);
		if (!s) {
			continue;
		}
		Participation *p = queryParticipation(s->participationId);
		if (!p) {
			continue;
		}
		if (p->athleteId == athleteId) {
			sum += s->score;
			printf("成绩ID：%d\n", s->id);
			printf("参赛信息ID：%d\n", s->participationId);
			printf("分数：%lf\n", s->score);
			printf("排名：%d\n", s->rank);
			printf("\n");
		}
	}
	printf("运动员总分：%lf\n", sum);
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
		case '5':
			queryScoreByEventIdView();
			break;
		case '6':
			queryScoreByUnitIdView();
			break;
		case '7':
			queryScoreByAthleteIdView();
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