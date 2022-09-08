// Z
#include <stdio.h>
#include <math.h>

// 2^n X 2^n 배열에서 (r, c) 방문 순서 반환
int find(int n, int r, int c)
{
    if (n == 0)
    {
        return 0;
    }
    int half = pow(2, n-1);
    // (r, c)가 1번 사각형일 때
    if (r < half && c < half)
        return find(n - 1, r, c);
    // (r, c)가 2번 사각형일 때
    if (r < half && c >= half)
        return half * half + find(n - 1, r, c - half);
    // (r, c)가 3번 사각형일 때
    if (r >= half && c < half)
        return half*half*2 + find(n - 1, r - half, c);
    // (r, c)가 4번 사각형일 때
    return half*half*3 + find(n - 1, r - half, c - half);
}

int main()
{
    int n = 0;
    int r = 0;
    int c = 0;
    scanf("%d %d %d", &n, &r, &c);
    int res = find(n, r, c);
    printf("%d\n", res);
}