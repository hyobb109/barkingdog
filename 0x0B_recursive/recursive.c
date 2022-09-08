#include <stdio.h>

void printn(int n)
{
    if (n < 1)
    {
        return;
    }
    printf("%d ", n);
    printn(n - 1);
}

int sum(int n)
{
    if (n < 1)
        return 0;
    return (n + sum(n - 1));
}

int main()
{
    int n = 10;
    printn(n);
    printf("\n========\n");
    printf("sum = %d\n", sum(n));

}