// N과 M(1) - 1 ~ N 자연수 중에서 중복 없이 M개를 고른 수열
#include <stdio.h>

int n;
int m;
int arr[10];
int isused[10];

// k는 현재까지 택한 수
void perm(int k)
{
    if (k == m) // m개를 모두 택했으면
    {
        for (int i = 0; i < m; i++)
        {
            // arr에 저장한 수 출력
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]) // i가 아직 사용되지 않았으면
        {
            // k번째 수를 i로 넣고 사용했다는 표시
            arr[k] = i;
            //printf("arr[%d] = %d\n", k, i);
            isused[i] = 1;
            // 다음 수를 정함
            perm(k + 1);
            // k번째 수를 i로 정한 모든 경우에 대해 다 확인 후 i 사용되지않음 표시
            // printf("i = %d unused\n", i);
            isused[i] = 0;
        }
        // i가 사용되었으면 다음 수로 넘어감
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    perm(0);
}