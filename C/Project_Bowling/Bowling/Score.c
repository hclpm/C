/*#include<stdio.h>
//���� �Է��� ��� �����ϰ�, ���� ������ �����ϸ� ������ ���.

//fstate�� 0�̸� ù�� �Ǵ� hit, 1�̸� �����, 2�� ��Ʈ����ũ
//�Լ����� score�� ���� ���� ����, fstate�� ���� ������ ���
//fscore1�� ���� ���� fscore2�� ������ ����



int main(void)
{
    int score = 0;
    int cast;
    int pcount = 0;         //���� ����� ������ �Ǵ� ��, 3 �Ǵ� 4�� �Ǹ� ���
    int frame = 1;
    int bcount = 0;
    int fscore = 0;

    for (int i = 1; i <= 21; i++) {
        printf("%d frame cast: ", (i + 1)/2);
        scanf_s("%d", &cast);
                         
        if ((i % 2 == 1) && (cast == 10)) {     //strike
            if (bcount > 0) {                   //bcount 2 �̻��̸� ���� 2��
                fscore = score + cast;
                score += cast;
                bcount -= 1;
            }
            else {
                score += cast;
            }
            bcount += 2;                        //strike �̹Ƿ� bcount 2 ����
            pcount += 1;
            i++;                                //strike �̹Ƿ� ���� ���������� �Ѿ
        }
        else if ((i % 2 == 0) && (cast == 10)) {//spare
            if (bcount > 0) {                   //bcount 2 �̻��̸� ���� 2��
                fscore = score + cast;
                score += cast;
                bcount -= 1;

            }
            else {
                score += cast;
            }
            bcount += 1;                        //spare �̹Ƿ� bcount 1 ����
            pcount += 2;
            score += cast;
        }
        else if (i % 2 == 1) {                  //n_1�����ӿ��� ��Ÿ
            if (bcount > 0) {                   //bcount 2 �̻��̸� ���� 2��
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
        else if (i % 2 == 0) {                  //n_2�����ӿ��� ��Ÿ
            if (bcount > 0) {                   //bcount 2 �̻��̸� ���� 2��
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