// N-Queen
#include <stdio.h>

int cnt = 0;
int isused1[40]; // 열 체크 (y가 동일)
int isused2[40]; // 대각선 / 방향 체크 (x + y가 같은지)
int isused3[40]; // 대각선 \ 방향 체크 (x - y가 같은지)
int n;

// x번째 행에 말 배치
void queen(int x)
{
    if(x == n) // n번째 행까지 다 놓았다면 리턴
    {
        cnt++;
        return;
    }
    // (x, y)에 퀸을 놓음
    for (int y = 0; y < n; y++)
    {
        // 열, /, \ 대각선 방향에 퀸이 있다면 넘김
        if (isused1[y] || isused2[x + y] || isused3[x - y + n - 1])
            continue;
        // printf("(x, y) = (%d, %d)\n", x, y);
        isused1[y] = 1;
        isused2[x + y] = 1;
        isused3[x - y + n - 1] = 1;
        queen(x + 1);
        isused1[y] = 0;
        isused2[x + y] = 0;
        isused3[x - y + n - 1] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    queen(0);
    printf("%d\n", cnt);
}