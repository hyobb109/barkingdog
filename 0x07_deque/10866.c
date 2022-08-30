// 덱
#include <stdio.h>
#include <string.h>

int main()
{
    int deq[20001] = {0, }; // (2 * MAX + 1) 크기의 배열 만듦
    int head = 10000; // n의 최댓값으로 지정
    int tail = 10000;
    int n = 0;
    scanf("%d", &n); // 명령 수
    for (int i = 0; i < n; i++)
    {
        char cmd[11];
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front") == 0)
        {
            int x = 0;
            scanf("%d", &x);
            deq[--head] = x;
        }
        else if (strcmp(cmd, "push_back") == 0)
        {
            int x = 0;
            scanf("%d", &x);
            deq[tail++] = x;
        }
        else if (strcmp(cmd, "pop_front") == 0)
        {
            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", deq[head++]);
        }
        else if (strcmp(cmd, "pop_back") == 0)
        {
            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", deq[--tail]);
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
                printf("%d\n", deq[head]);
        }
        else if (strcmp(cmd, "back") == 0)
        {
            if (tail - head == 0)
                printf("-1\n");
            else
                printf("%d\n", deq[tail - 1]);
        }
    }
}