// 하노이 탑 이동순서
#include <stdio.h>
#include <math.h>

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력
void hanoi(int a, int b, int n)
{
    // 종료조건
    if (n == 1)
    {
        printf("disc 1 : %d %d\n", a, b);
        return;
    }
    // n-1 개 원판을 나머지 기둥으로 옮김
    hanoi(a, 6 - a - b, n - 1);
    printf("disc %d : %d %d\n", n, a, b);
    // n-1개 원판을 목적지 기둥으로 옮김
    hanoi(6 - a - b, b, n - 1);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    // n개의 돌 이동 횟수 : An = 2A(n-1) + 1 => 2^n - 1
    int k = pow(2, n) - 1;
    printf("%d\n", k);
    hanoi(1, 3, n);
}