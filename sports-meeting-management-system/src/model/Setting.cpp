/*
Setting Model
*/
#include "../../include/main.h"

// �˶�Ա��������Ŀ����
int MAX_ATHLETE_PARTICIPATION = 3;

/*
������Ŀ��С��������
��������������㣬��ȡ��������Ŀ
*/
int MIN_EVENT_PARTICIPATION = 4;

/*
������Ŀ��������
��������������6�ˣ�ȡǰ3������һ����5�֣��ڶ�����3�֣���������2��
������������6�ˣ�ȡǰ5������һ����7�֣��ڶ�����5�֣���������3�֣���������2�֣���������1��
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
