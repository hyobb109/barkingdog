// 큐
#include <stdio.h>
#include <string.h>

int main()
{
    int q[20010] = {0, };
    int head = 0;
    int tail = 0;
    int n = 0;
    scanf("%d", &n); // 명령 수
    for (int i = 0; i < n; i++)
    {
        char cmd[6];
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0)
        {
            int x = 0;
            scanf("%d", &x);
            q[tail++] = x;
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", q[head++]);
        }
        else if (strcmp(cmd, "size") == 0)
        {
            printf("%d\n", tail - head);
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            if (tail - head == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp(cmd, "front") == 0)
        {
            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", q[head]);
        }
        else if (strcmp(cmd, "back") == 0)
        {

            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", q[tail - 1]);
        }
    }
}