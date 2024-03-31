/*
Participation View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 参赛信息管理 -\n");
	printf("1. 添加参赛信息\n");
	printf("2. 删除参赛信息\n");
	printf("3. 修改参赛信息\n");
	printf("4. 根据参赛信息ID查询参赛信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void addParticipationView() {
	Participation* p = newParticipation();
	system("cls");
	printf("- 添加参赛信息 -\n");
	printf("请输入要添加的参赛信息：\n");
	int eventId, athleteId;
	printf("比赛ID：");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("发生错误，比赛不存在\n");
		system("pause");
		return;
	}
	printf("运动员ID：");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("发生错误，运动员不存在\n");
		system("pause");
		return;
	}
	// 限制运动员参赛项目数量
	int athleteParticipationCount = 0;
	int participationCount = *getParticipationCount();
	for (int i = 1; i <= participationCount; i++)
	{
		Participation* p = queryParticipation(i);
		if (p->athleteId == athleteId)
		{
			athleteParticipationCount++;
			if (p->eventId == eventId)
			{
				// 防止运动员重复参加同一项目
				printf("该运动员已参加该项目，请勿重复报名\n");
				system("pause");
				return;
			}
		}
	}
	if (athleteParticipationCount >= MAX_ATHLETE_PARTICIPATION)
	{
		printf("运动员参赛项目数量已达上限\n");
		system("pause");
		return;
	}
	p->eventId = eventId;
	p->athleteId = athleteId;
	int id = addParticipation(p);
	if (~id) {
		printf("添加成功^_^，ID：%d\n", id);
	}
	else {
		printf("添加失败\n");
	}
	system("pause");
}

static void removeParticipationView() {
	int id;
	system("cls");
	printf("- 删除参赛信息 -\n");
	printf("请输入要删除的参赛信息ID：");
	scanf_s("%d", &id);
	bool ret = removeParticipation(id);
	if (ret) {
		printf("删除成功^_^\n");
	}
	else {
		printf("删除失败\n");
	}
	system("pause");
}

static void modifyParticipationView() {
	int id;
	system("cls");
	printf("- 修改参赛信息 -\n");
	printf("请输入要修改的参赛信息ID：");
	scanf_s("%d", &id);
	if (!queryParticipation(id)) {
		printf("发生错误，参赛信息不存在\n");
		system("pause");
		return;
	}
	Participation* p = newParticipation();
	printf("请输入要修改的参赛信息：\n");
	int eventId, athleteId;
	printf("比赛ID：");
	scanf_s("%d", &eventId);
	if (!queryEvent(eventId)) {
		printf("发生错误，比赛不存在\n");
		system("pause");
		return;
	}
	printf("运动员ID：");
	scanf_s("%d", &athleteId);
	if (!queryAthlete(athleteId)) {
		printf("发生错误，运动员不存在\n");
		system("pause");
		return;
	}
	p->eventId = eventId;
	p->athleteId = athleteId;
	bool ret = modifyParticipation(id, p);
	if (ret) {
		printf("修改成功^_^\n");
	}
	else {
		printf("修改失败\n");
	}
	system("pause");
}

static void queryParticipationView() {
	int id;
	system("cls");
	printf("- 查询参赛信息 -\n");
	printf("请输入要查询的参赛信息ID：");
	scanf_s("%d", &id);
	Participation* p = queryParticipation(id);
	if (!p) {
		printf("未找到该参赛信息\n");
		system("pause");
		return;
	}
	printf("参赛信息ID：%d\n", p->id);
	printf("比赛ID：%d\n", p->eventId);
	printf("运动员ID：%d\n", p->athleteId);
	system("pause");
}

void participationView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// 清空输入缓冲区
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			addParticipationView();
			break;
		case '2':
			removeParticipationView();
			break;
		case '3':
			modifyParticipationView();
			break;
		case '4':
			queryParticipationView();
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