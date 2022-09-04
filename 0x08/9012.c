// 괄호
#include <stdio.h>
#include <string.h>

int main()
{
    int t = 0;

    scanf("%d", &t);
    while (t--)
    {
        char par[52];
        char stack[52] = {'*', };
        int len = 0;
        int pos = 0;
        int checked = 1;

        scanf("%s", par);
        len = strlen(par);
        for (int i = 0; i < len; i++)
        {
            if (par[i] == '(')
            {
                stack[pos++] = par[i];
            }
            // 닫는 괄호
            else if (par[i] == ')')
            {
                // 매칭할 괄호가 스택에 없으면 no
                if (stack[0] == '*')
                {
                    printf("NO\n");
                    checked = 0;
                    break;
                }
                // 여는 괄호가 있으면 pop하고 비워줌
                stack[--pos] = '*';
            }
        }
        // 매칭이 끝나고 스택에 괄호가 남아있으면 no
        if (stack[0] != '*')
            printf("NO\n");
        else if (checked)
            printf("YES\n");
    }
}