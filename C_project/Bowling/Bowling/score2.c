/*#include <stdio.h>

//���� 1: ����� = �����ջ��� 10�� �����
//���� 2: ��Ʈ����ũ�� ����� �� ���� �ջ� �˰��� ����

/*���� �˰��� :
1. ��Ʈ����ũ�� 2 �ο�, ������ 1, ��Ÿ�� 0
2. i ������ ���� ��(���&��¼��� ����) -1
3. ������ 0�̸� ���

�Ѱ�: i������ �������� ������ ����Ǿ�, 10��° �������� ���� �� ������ 8, 9 �� �������� ������ ������ �ʴ´�
�ذ� ���: 


int main(void)
{
	int roll = 0;
	int board[11][4] = {0,}; //roll ���� ����
	int stack[13] = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};	//0�϶� ���� ���& ��� // 1�̳� 2 �϶� ���� ����
	int score[13] = {0};	//��� ������, index�� i�� ��ġ
	int state[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //0�̸� ��Ÿ, 1�̸� �����, 2�� ��Ʈ����ũ
	int j1 = 0;
	int c = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 3; j++) {
			if ((i < 10) && (j == 3)) {
				break;
			}
			if (i > 10) {								//////////i�� 12�� ������ ���� ��°� ����
				i = 10;
				c++;
				j = c;

			}
			else if (i == 12) {
				i = 10;
				j = 3;
				c = 1;
			}
			printf("%d frame [%d]: ", i, j);
			scanf_s("%d", &roll);
			board[i][j] = roll;
			j1 = j;
			//											<<���� ����>>
			//��Ʈ����ũ
			if ((roll == 10) && (j == 1) && (i != 10)) {
				stack[i] = 2;
				state[i] = 2;
				break;
			}
			//�����
			else if ((board[i][1] + board[i][2]) == 10 && (i != 10)) {
				stack[i] = 1;
				state[i] = 1;
				if (i == 10) {
					break;
				}
			}
			//��Ÿ
			else {
				state[i] = 0;
				if (j == 2) {
					stack[i] = 0;
				}
				if (i == 10) {
					break;
				}
			}

		}
		//											<<��� & ��� ����>>
		for (int k = 1; k <= 12; k++) {
			//������ 0�̸� �������&���
			if (stack[k] == 0 && k <= 10) {								//if~else���� ���� ������ �� ���� ��� �ñ� ����
				//��Ʈ����ũ ���&�������
				if (state[k] == 2) {
					score[k] = score[k - 1] + board[k][1] + board[k + 1][1] + board[k + 1][2] + board[k + 2][1];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//����� ���&�������
				else if (state[k] == 1) {
					score[k] = score[k - 1] + board[k][1] + board[k][2] + board[k + 1][1];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//��Ÿ[2] ���&�������
				else if (state[k] == 0 && j1 == 2) {
					score[k] = score[k - 1] + board[k][1] + board[k][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
			}
													//10 ���� ����
			else if (stack[k] == 0 && k >= 10) {								
				//��Ʈ����ũ ���&�������
				if (state[k] == 2) {
					score[10] = score[9] + board[10][1] + board[10][1] + board[10][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//����� ���&�������
				else if (state[k] == 1) {
					score[10] = score[9] + board[10][1] + board[10][2] + board[10][3];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//��Ÿ[2] ���&�������
				else if (state[k] == 0 && j1 == 3) {
					score[10] = score[9] + board[10][1] + board[10][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
			}
			//������ 0 ���� ũ�� ���� ���̱�
			else if (stack[k] > 0) {
				stack[k]--;
			}
		}
		if (c == 3) {				
			printf("stack: ");
			for (int q = 1; q <= 12; q++) {
				printf("%d ", stack[q]);
			}
			printf("\n");
			
			printf("state: ");
			for (int q = 1; q <= 12; q++) {
				printf("%d ", state[q]);
			}
			printf("\n");

			printf("score: ");
			for (int q = 1; q <= 12; q++) {
				printf("%d ", score[q]);
			}
			printf("\n");

			return 0;
		}
	}
	return 0;
}
*/