// 균형잡힌 세상
#include <stdio.h>
#include <string.h>

int check(char p, char *stack, int pos)
{
    // 닫는 괄호가 나왔는데 스택이 비어있으면 유효하지 않음
    if (stack[0] == '*')
        return 1;
    // 스택의 top과 짝이 맞으면 ok
    if (p == ')' && stack[pos - 1] == '(')
        return 0;
    if (p == ']' && stack[pos - 1] == '[')
        return 0;
    return 1;
}

int main()
{
    while (1)
    {
        char str[105];
        char stack[105] = {'*', };
        int pos = 0;
        int len = 0;

        scanf("%[^\n]s", &str); // 개행 입력 전까지 문자열 입력받음
        len = strlen(str);
        if (str[0] == '.' && len == 1) // .만 입력되면 종료
            break;

        int i = 0;
        int cnt = 0; // 괄호 카운트
        while (i < len)
        {
            // 여는 괄호가 나오면 스택에 추가
            if (str[i] == '(' || str[i] == '[')
            {
                // printf("opened pos = %d\n", pos);
                stack[pos++] = str[i];
                // printf("(, [ -> stack = %s\n", stack);
                cnt++;
            }
            // 닫는 괄호가 나오면
            if (str[i] == ')' || str[i] == ']')
            {
                // printf("closed pos = %d\n", pos);
                int invalid = check(str[i], stack, pos);
                // 괄호쌍 유효하지 않으면 no출력
                if (invalid)
                {
                    cnt = -1;
                    break;
                }
                if (invalid == 0)
                {
                    // 유효한 괄호쌍이면 pop
                    stack[pos - 1] = '*';
                    // printf("pop check -> stack = %s\n", stack);
                    pos--;
                }
            }
            i++;
        }
        // 문장이 끝나도 괄호가 스택에 남아있으면 올바르지 않은 괄호 쌍
        if (cnt == -1 || (cnt != 0 && stack[0] != '*'))
        {
            // printf("stack = %s\n", stack);
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
        // scanf로 입력 받은 버퍼에 저장되어있는 \n을 처리해줘야 무한루프를 돌지 않음
        // fflush(stdin); 입력 버퍼를 비우는 함수, but 표준 fflush는 출력버퍼를 비우는 함수기때문에 gcc 에서 x
        getchar(); // 버퍼에 데이터가 있을 때 가장 앞의 데이터(\n) 반환
    }
    return 0;
}