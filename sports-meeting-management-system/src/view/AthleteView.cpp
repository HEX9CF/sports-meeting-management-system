 #include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- 运动员信息管理 -\n");
	printf("1. 添加运动员信息\n");
	printf("2. 删除运动员信息\n");
	printf("3. 修改运动员信息\n");
	printf("4. 查询运动员信息\n");
	printf("0. 返回上级菜单\n");
	printf("请输入指令：");
}

static void addAthleteView() {
	Athlete *a = newAthlete();
	system("cls");
	printf("- 添加运动员信息 -\n");
	printf("请输入要添加的运动员信息：\n");
	printf("姓名：");
	scanf_s("%s", a->name, MAX_LENGTH);
	printf("性别：");
	scanf_s("%s", a->gender, MAX_LENGTH);
	printf("年龄：");
	scanf_s("%d", &(a->age));
	int id = addAthlete(a);
	if (~id) {
		printf("添加成功^_^，ID：%d\n", id);
	}
	else {
		printf("添加失败\n");
	}
	system("pause");
}
 
static void removeAthleteView() {
	int id;
	system("cls");
	printf("- 删除运动员信息 -\n");
	printf("请输入要删除的运动员ID：");
	scanf_s("%d", &id);
	bool ret = removeAthlete(id);
	if (ret) {
		printf("删除成功^_^\n");
	}
	else {
		printf("删除失败\n");
	}
	system("pause");
}

static void modifyAthleteView() {
	int id;
	Athlete *a = newAthlete();
	system("cls");
	printf("- 修改运动员信息 -\n");
	printf("请输入要修改的运动员ID：");
	scanf_s("%d", &id);
	if (!queryAthlete(id)) {
		printf("未找到该运动员\n");
		system("pause");
		return;
	}
	printf("请输入要修改的运动员信息：\n");
	printf("姓名：");
	scanf_s("%s", a->name, MAX_LENGTH);
	printf("性别：");
	scanf_s("%s", a->gender, MAX_LENGTH);
	printf("年龄：");
	scanf_s("%d", &(a->age));
	bool ret = modifyAthlete(id, a);
	if (ret) {
		printf("修改成功^_^\n", id);
	}
	else {
		printf("修改失败\n");
	}
	system("pause");
}

static void queryAthleteView() {
	int id;
	system("cls");
	printf("- 查询运动员信息 -\n");
	printf("请输入要查询的运动员ID：");
	scanf_s("%d", &id);
	Athlete *a = queryAthlete(id);
	if (!a) {
		printf("未找到该运动员\n");
		system("pause");
		return;
	}
	printf("ID：%d\n", id);
	printf("姓名：%s\n", a->name);
	printf("性别：%s\n", a->gender);
	printf("年龄：%d\n", a->age);
	system("pause");
}

void athleteView() {
	int op = -1;
	do {
		printMenu();
		scanf_s("%d", &op);
		printf("\n");
		switch (op) {
		case 1:
			addAthleteView();
			break;
		case 2:
			removeAthleteView();
			break;
		case 3:
			modifyAthleteView();
			break;
		case 4:
			queryAthleteView();
			break;
		case 0:
			printf("返回上级菜单\n");
			return;
			break;
		default:
			printf("未知指令\n");
		}
	} while (op != 0);
}