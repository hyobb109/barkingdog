// 스택
#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0; // 명령의 수
    int stack[10005] = {0, }; // 스택 0으로 초기화
    int pos = 0; // 스택 현재 position
    int size = 0; // 스택 정수 개수 카운트

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char cmd[6]; // 명령
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0)
        {
            int x = 0;
            scanf("%d", &x);
            stack[pos++] = x;
            size++;
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            if (stack[0] == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", stack[--pos]);
                stack[pos] = 0;
                size--;
            }
        }
        else if (strcmp(cmd, "size") == 0)
        {
            printf("%d\n", size);
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            if (stack[0] == 0) // 비어있으면 -1
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp(cmd, "top") == 0)
        {
            if (stack[0] == 0)
                printf("-1\n");
            else
                printf("%d\n", stack[pos - 1]);
        }
    }
}