/*#include <stdio.h>

//문제 1: 스페어 = 점수합산이 10인 경우임
//문제 2: 스트라이크나 스페어 시 점수 합산 알고리즘 수정

/*스택 알고리즘 :
1. 스트라이크면 2 부여, 스페어면 1, 평타면 0
2. i 루프가 끝날 때(계산&출력세션 이후) -1
3. 스택이 0이면 출력

한계: i루프를 기준으로 스택이 적용되어, 10번째 프레임이 전부 돌 때까지 8, 9 번 프레임의 스택이 계산되지 않는다
해결 방법: 


int main(void)
{
	int roll = 0;
	int board[11][4] = {0,}; //roll 내역 보드
	int stack[13] = {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};	//0일때 점수 계산& 출력 // 1이나 2 일때 스택 감소
	int score[13] = {0};	//계산 점수판, index는 i랑 일치
	int state[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //0이면 평타, 1이면 스페어, 2면 스트라이크
	int j1 = 0;
	int c = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 3; j++) {
			if ((i < 10) && (j == 3)) {
				break;
			}
			if (i > 10) {								//////////i를 12번 돌리기 위해 출력값 조정
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
			//											<<스택 세션>>
			//스트라이크
			if ((roll == 10) && (j == 1) && (i != 10)) {
				stack[i] = 2;
				state[i] = 2;
				break;
			}
			//스페어
			else if ((board[i][1] + board[i][2]) == 10 && (i != 10)) {
				stack[i] = 1;
				state[i] = 1;
				if (i == 10) {
					break;
				}
			}
			//평타
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
		//											<<계산 & 출력 세션>>
		for (int k = 1; k <= 12; k++) {
			//스택이 0이면 점수계산&출력
			if (stack[k] == 0 && k <= 10) {								//if~else문을 통해 프레임 별 점수 출력 시기 결정
				//스트라이크 출력&점수계산
				if (state[k] == 2) {
					score[k] = score[k - 1] + board[k][1] + board[k + 1][1] + board[k + 1][2] + board[k + 2][1];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//스페어 출력&점수계산
				else if (state[k] == 1) {
					score[k] = score[k - 1] + board[k][1] + board[k][2] + board[k + 1][1];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//평타[2] 출력&점수계산
				else if (state[k] == 0 && j1 == 2) {
					score[k] = score[k - 1] + board[k][1] + board[k][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
			}
													//10 개별 연산
			else if (stack[k] == 0 && k >= 10) {								
				//스트라이크 출력&점수계산
				if (state[k] == 2) {
					score[10] = score[9] + board[10][1] + board[10][1] + board[10][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//스페어 출력&점수계산
				else if (state[k] == 1) {
					score[10] = score[9] + board[10][1] + board[10][2] + board[10][3];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
				//평타[2] 출력&점수계산
				else if (state[k] == 0 && j1 == 3) {
					score[10] = score[9] + board[10][1] + board[10][2];
					printf("\n[%d frame score: %d]\n\n", k, score[k]);
					stack[k] -= 1;
				}
			}
			//스택이 0 보다 크면 스택 줄이기
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