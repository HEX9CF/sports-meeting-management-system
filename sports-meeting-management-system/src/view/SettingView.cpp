/*
Setting View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 系统控制面板 -\n");
	printf("1. 查询所有配置项\n");
	printf("2. 设置运动员最大参赛项目数量\n");
	printf("3. 设置比赛项目最小参赛人数\n");
	printf("4. 设置成绩名次选取规则\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

// 查询所有配置项
static void queryAllSettings() {
	system("cls");
	printf("- 查询所有配置项 -\n");
	printf("运动员最大参赛项目数量：%d\n", MAX_ATHLETE_PARTICIPATION);
	printf("比赛项目最小参赛人数：%d\n", MIN_EVENT_PARTICIPATION);
	printf("成绩名次选取规则：\n");
	for (int i = 0; i <= 1; i++) {
		printf("第%d条规则：\n", i + 1);
		printf("参赛人数区间：%d-%d\n", RANKING_ATHLETE_RANGE[i][0], RANKING_ATHLETE_RANGE[i][1]);
		printf("名次选取数量：%d\n", RANKING_SELECT_COUNT[i]);
		printf("名次得分规则：\n");
		for (int j = 0; j < RANKING_SELECT_COUNT[i]; j++) {
			printf("第%d名，得%d分\n", j + 1, RANKING_SCORE_RULE[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

static void setAthleteMaxParticipation() {
	system("cls");
	printf("- 设置运动员最大参赛项目数量 -\n");
	printf("请输入运动员最大参赛项目数量：");
	scanf_s("%d", &MAX_ATHLETE_PARTICIPATION);
	printf("设置成功^_^\n");
	system("pause");
}

static void setEventMinParticipation() {
	system("cls");
	printf("- 设置比赛项目最小参赛人数 -\n");
	printf("请输入比赛项目最小参赛人数：");
	scanf_s("%d", &MIN_EVENT_PARTICIPATION);
	printf("设置成功^_^\n");
	system("pause");
}

static void setRankingRule() {
	system("cls");
	printf("- 设置成绩名次选取规则 -\n");
	for (int i = 1; i <= 2; i++) {
		// 设置参赛人数区间
		printf("请输入第%d个区间的最小参赛人数和最大参赛人数（输入2个数字，用空格隔开）：", i);
		scanf_s("%d %d", &RANKING_ATHLETE_RANGE[i][0], &RANKING_ATHLETE_RANGE[i][1]);
		// 设置名次选取数量
		printf("请输入第%d个区间的名次选取数量：", i);
		scanf_s("%d", &RANKING_SELECT_COUNT[i]); 
		// 设置名次得分
		printf("请输入第%d个区间的名次得分（输入%d个数字，用空格隔开）：", i, RANKING_SELECT_COUNT[i]);
		for (int j = 1; j <= RANKING_SELECT_COUNT[i]; j++) {
			scanf_s("%d", &RANKING_SCORE_RULE[i][j]);
		}
	}
	printf("设置成功^_^\n");
	system("pause");
}
 
void settingView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			queryAllSettings();
			break;
		case '2':
			setAthleteMaxParticipation();
			break;
		case '3':
			setEventMinParticipation();
			break; 
		case '4':
			setRankingRule();
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
