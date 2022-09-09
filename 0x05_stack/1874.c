// 스택 수열
#include <stdio.h>

// 수열이 내림차순인지 체크
int descending(int *arr, int pos, int n)
{
    for (int i = pos + 1; i < n; i++)
    {
        if(arr[pos] < arr[i])
        {
            return 0;
        }
        pos++;
    }
    return 1;
}

int main()
{
    int num[100005] = {0, };
    int max = 0;
    int n = 0;
    scanf("%d", &n); // n은 수열의 최댓값

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]); // 수열 배열에 저장
        if (num[i] == n)
        {
            max = i;
        }
    }

    // 최댓값 다음 수열이 내림차순이 아니면 유효하지 않음
    if (descending(num, max, n) == 0)
    {
        printf("NO\n");
        return 0;
    }

    int pos = 0;
    int i = 1;
    while (pos < n)
    {
        if (i <= num[pos]) // num[pos]가 나올 때까지 push
        {
            printf("+\n");
        }
        if (i == num[pos]) // num[pos]와 일치하면 push하고 pop
        {
            printf("-\n");
            printf("%d ", num[pos]);
            pos++;
            i--;
            // 다음 값이 현재 값보다 작으면, 그 값 찾을 때까지 pop
            if (num[pos] < num[pos - 1])
            {
                printf("-\n");
                num[pos];

            }
        }
        if (i >)
        i++;

    }
}