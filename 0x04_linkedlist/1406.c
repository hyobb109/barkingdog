// 에디터
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val;
    struct node *pre;
    struct node *nxt;
} node;

node *create_node(node *new)
{
    new = malloc(sizeof(node));
    if (new == NULL)
    {
        return new;
    }
    new->val = '*';
    new->nxt = NULL;
    new->pre = NULL;
    return new;
}

// 연결리스트에 새로운 node 추가
node *insert(node *head, char x)
{
    // 새로운 노드위한 공간 동적 할당
    node *new = malloc(sizeof(node));
    // 널가드
    if (new == NULL)
    {
        return new;
    }
    // 노드에 값 대입하고 앞, 뒤 연결
    new->val = x;
    new->pre = head;
    new->nxt = head->nxt;
    // 마지막 노드가 아니면 다음 노드의 pre와 연결(이 부분을 빼먹어서 런타임 에러 발생)
    if (head->nxt != NULL)
    {
        head->nxt->pre = new;
    }
    head->nxt = new;

    return new;
}

void delete (node *target)
{
    // 이전 노드의 nxt를 삭제할 노드의 다음 노드로 변경
    target->pre->nxt = target->nxt;
    if (target->nxt != NULL)
    {
        // 다음 노드의 pre를 삭제할 노드의 전 노드로 변경
        target->nxt->pre = target->pre;
    }
}

void print_node(node *head)
{
    while (head != NULL)
    {
        // 첫번째 노드가 아니면 출력하기
        if (head->val != '*')
            printf("%c", head->val);
        node *tmp;
        tmp = head;
        head = head->nxt;
        // 출력한 노드 메모리 free
        free(tmp);
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    node *cursor = NULL;
    node *tmp = NULL;

    // 명령어 개수
    int m = 0;
    char str[100001];

    // 문자열 입력
    scanf("%s", str);
    // head 노드 생성
    head = create_node(head);

    // 입력한 문자열 길이
    int n = strlen(str);
    // 문자열 연결리스트 생성
    node *curr = head;
    for (int i = 0; i < n; i++)
    {
        cursor = insert(curr, str[i]);
        curr = cursor;
    }
    // 명령어 개수 입력
    scanf("%d", &m);
    // 명령어 입력
    for (int i = 0; i < m; i++)
    {
        char cmd;
        scanf("\n%c", &cmd);
        // 커서 왼쪽으로 한 칸 옮김
        if (cmd == 'L' && cursor->pre != NULL)
        {
            cursor = cursor->pre;
        }
        // 커서 오른쪽으로 한 칸 옮김
        else if (cmd == 'D' && cursor->nxt != NULL)
        {
            cursor = cursor->nxt;
        }
        // 커서 왼쪽에 있는 문자 삭제
        else if (cmd == 'B' && cursor->pre != NULL)
        {
            delete (cursor);
            tmp = cursor;
            // 커서는 전 문자 위치로 변경
            cursor = cursor->pre;
            // 삭제한 노드 메모리 해제
            free(tmp);
        }
        // 커서 왼쪽에 문자 추가
        else if (cmd == 'P')
        {
            char x;
            scanf(" %c", &x);
            cursor = insert(cursor, x);
        }
    }
    print_node(head);
    return 0;
}