// 요세푸스
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxt;
}node;

void print_del(node *head, int n, int k)
{
    node *tmp = head;
    
    for (int i = 0; i < n; i++)
    {
        // k번째 전까지 넘김
        for (int j = 0; j < k - 1; j++)
        {
            tmp = tmp->nxt;
        }
        // k번째 삭제하고 메모리 해제
        node *del = tmp->nxt;
        tmp->nxt = del->nxt;
        // 삭제할 노드가 첫번째면 head노드를 첫번째 노드의 다음 노드와 연결
        if (del == head->nxt)
        {
            head->nxt = del->nxt;
        }
        printf("%d", del->data);
        free(del);
        if (i == n - 1)
        {
            break;
        }
        printf(", ");
    }
    
}

int main()
{
    node *p = NULL;
    int n = 0; // 사람 수
    int k = 0; // 제거할 사람 번호

    scanf("%d %d", &n, &k);

    node *head = malloc(sizeof(node));
    if (head == NULL)
    {
        return 1;
    }
    head->data = 0;
    head->nxt = NULL;

    node *tmp = head;

    // 번호 순서대로 연결리스트 생성
    for (int i = 1; i <= n; i++)
    {
        p = malloc(sizeof(node));
        p->data = i;
        tmp->nxt = p;
        // 마지막 노드는 첫번째 노드와 연결
        if (i == n)
        {
            p->nxt = head->nxt;
        }
        else
        {
            p->nxt = tmp->nxt;
        }
        tmp = tmp->nxt;
    }
    printf("<");
    print_del(head, n, k);
    printf(">\n");
    return 0;
}
