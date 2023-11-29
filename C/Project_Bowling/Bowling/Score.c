/*#include<stdio.h>
//점수 입력은 계속 저장하고, 일정 조건을 충족하면 점수를 출력.

//fstate가 0이면 첫구 또는 hit, 1이면 스페어, 2면 스트라이크
//함수에서 score는 현재 볼링 점수, fstate는 이전 프레임 결과
//fscore1은 전번 점수 fscore2는 전전번 점수



int main(void)
{
    int score = 0;
    int cast;
    int pcount = 0;         //점수 출력의 기준이 되는 값, 3 또는 4가 되면 출력
    int frame = 1;
    int bcount = 0;
    int fscore = 0;

    for (int i = 1; i <= 21; i++) {
        printf("%d frame cast: ", (i + 1)/2);
        scanf_s("%d", &cast);
                         
        if ((i % 2 == 1) && (cast == 10)) {     //strike
            if (bcount > 0) {                   //bcount 2 이상이면 점수 2배
                fscore = score + cast;
                score += cast;
                bcount -= 1;
            }
            else {
                score += cast;
            }
            bcount += 2;                        //strike 이므로 bcount 2 증가
            pcount += 1;
            i++;                                //strike 이므로 다음 프레임으로 넘어감
        }
        else if ((i % 2 == 0) && (cast == 10)) {//spare
            if (bcount > 0) {                   //bcount 2 이상이면 점수 2배
                fscore = score + cast;
                score += cast;
                bcount -= 1;

            }
            else {
                score += cast;
            }
            bcount += 1;                        //spare 이므로 bcount 1 증가
            pcount += 2;
            score += cast;
        }
        else if (i % 2 == 1) {                  //n_1프레임에서 평타
            if (bcount > 0) {                   //bcount 2 이상이면 점수 2배
                fscore = score + cast;
                score += cast;
                bcount -= 1;

            }
            else {
                score += cast;
            }
            score += cast;
            pcount += 1;
        }
        else if (i % 2 == 0) {                  //n_2프레임에서 평타
            if (bcount > 0) {                   //bcount 2 이상이면 점수 2배
                fscore = score + cast;
                score += cast;
                bcount -= 1;
            }
            else {
                score += cast;
            }
            score += cast;
            pcount += 2;
        }

        if ((pcount == 3) || (pcount == 4)) {
            printf("[%d frame score: %d]\n\n", frame, fscore);
            frame++;

            pcount = 0;
        }
    }


    return 0;
}
*/