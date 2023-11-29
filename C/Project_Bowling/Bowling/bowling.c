#include <stdio.h>

int roll = 0;
int board[13][3] = { 0 }; 
int stack[11] = { -2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2 };	
int score[11] = { 0 };	
int state[11] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; 

int br=0;
int brscore[4] = {0};

void scorePrint() {
	for (int k = 1; k <= 10; k++) {
		if (stack[k] == 0) {

			if (state[k] == 2) {
				score[k] = score[k - 1] + board[k][1] + board[k + 1][1] + board[k + 1][2] + board[k + 2][1] + brscore[2]+ brscore[3];
				printf("\n[%d frame score: %d]\n\n", k, score[k]);
				stack[k] = -2;

			}

			else if (state[k] == 1) {
				score[k] = score[k - 1] + board[k][1] + board[k][2] + board[k + 1][1] + brscore[2]+ +brscore[3];
				printf("\n[%d frame score: %d]\n\n", k, score[k]);
				stack[k] = -2;

			}

			else if (state[k] == 0) {
				score[k] = score[k - 1] + board[k][1] + board[k][2];
				printf("\n[%d frame score: %d]\n\n", k, score[k]);
				stack[k] = -2;
			}
		}
		else if (stack[k] > 0) {
			stack[k]--;
		}
	}
};

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 2; j++) {
			printf("%d frame [%d]: ", i, j);
			scanf_s("%d", &roll);
			board[i][j] = roll;
			if (i == 10) {
				if ((roll == 10) && (j == 1)) {
					stack[i] = 3;
					state[i] = 2;
					br = 2;
					scorePrint();
					break;
				}
 				else if ((board[i][1] + board[i][2]) == 10) {
					stack[i] = 1;
					state[i] = 1;
					br = 3;
				}
 				else {
					if (j == 2) {
						stack[i] = 0;
						state[i] = 0;
					}
				}
			}
			else if ((roll == 10) && (j == 1)) {
				stack[i] = 2;
				state[i] = 2;
				scorePrint();
				break;
			}

			else if ((board[i][1] + board[i][2]) == 10) {
				stack[i] = 1;
				state[i] = 1;
			}
			else {
				if (j == 2) {
					stack[i] = 0;
					state[i] = 0;
				}
			}
			scorePrint(); 

	}
	for (int g = br; g <= 3; g++) {
		if (state[10] == 0 && br == 0) {
			break;
		}
		printf("10 frame [%d]: ", g);
		scanf_s("%d", &brscore[g]);
		scorePrint();

	}
	scorePrint();
	return 0;
}