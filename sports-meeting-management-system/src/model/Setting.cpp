/*
Setting Model
*/
#include "../../include/main.h"

// 运动员最大参赛项目数量
int MAX_ATHLETE_PARTICIPATION = 3;

/*
比赛项目最小参赛人数
如果参赛人数不足，则取消比赛项目
*/
int MIN_EVENT_PARTICIPATION = 4;

/*
比赛项目排名规则：
参赛人数不超过6人，取前3名：第一名得5分，第二名得3分，第三名得2分
参数人数超过6人，取前5名：第一名得7分，第二名得5分，第三名得3分，第四名得2分，第五名得1分
*/
int RANKING_ATHLETE_RANGE[MAX_LENGTH][2] = {
	{0, 6},
	{7, MAX_SIZE}
};
int RANKING_SELECT_COUNT[MAX_LENGTH] = {3, 5};
int RANKING_SCORE_RULE[MAX_LENGTH][MAX_SIZE] = {
	{5, 3, 2, 0, 0},
	{7, 5, 3, 2, 1}
};
