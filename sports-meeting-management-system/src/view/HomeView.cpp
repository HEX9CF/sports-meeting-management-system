/*
Home View
*/
#include "../../include/main.h"

static void printMenu() {
	system("cls");
	printf("- �˶������ϵͳ -\n");
	printf("1. ��λ��Ϣ����\n");
	printf("2. �˶�Ա��Ϣ����\n");
	printf("3. ������Ŀ����\n");
	printf("4. ������Ϣ����\n");
	printf("5. ������Զ�����\n");
	printf("6. �����ɼ�����\n");
	printf("7. ���ݵ��뵼��\n");
	printf("8. ϵͳ�������\n");
	printf("0. �˳�����ϵͳ\n");
	printf("������ָ�");
}
 
void homeView() {
	char op;
	do {
		printMenu();
		scanf_s(" %c", &op);
		// ������뻺����
		while (getchar() != '\n');
		printf("\n");
		switch (op) {
		case '1':
			unitView();
			break;
		case '2':
			athleteView();
			break;
		case '3':
			eventView();
			break;
		case '4':
			participationView();
			break;
		case '5':
			orderBookView();
			break;
		case '6':
			scoreView();
			break;
		case '7':
			dataView();
			break;
		case '8':
			settingView();
			break;
		case '0':
			printf("�˳�ϵͳ\n");
			system("pause");
			return;
			break;
		default:
			printf("δָ֪��\n");
			system("pause");
		}
	} while (1);
}