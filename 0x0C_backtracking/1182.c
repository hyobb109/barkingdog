// 부분수열의 합
#include <stdio.h>
#include <math.h>

int arr[25];
int cnt;
int n;
int s;

void check(int k, int total)
{
    if (k == n)
    {
        // 부분수열의 합이 s와 같아지면 카운트
        if (total == s)
            cnt++;
        return;
    }
    check(k + 1, total);
    check(k + 1, total + arr[k]);
}

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    check(0, 0);
    // 공집합인 경우 제외
    if (s == 0)
        cnt--;
    printf("%d\n", cnt);
}