// 곱셈
#include <stdio.h>

/*
    a^n X a^n = a^2n
    12^58 % 67 = 4
    12^116 % 67 = 4^2
*/

long long powmod(int a, int b, int c)
{
    if (b  == 1)
        return a % c;
    long long val = powmod(a, b / 2, c);
    val = val * val % c;
    // b가 짝수일 때
    if (b % 2 == 0)
        return val;
    // b가 홀수일 때
    return val * a % c;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);
    printf("%lld\n", powmod(a, b, c));
}