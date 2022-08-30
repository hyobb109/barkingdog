// 키로거
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char data;
    struct node *pre;
    struct node *nxt;
}node;

node *create(node *head, char a)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return new;
    }
    // 헤드 노드
    if (a == '*')
    {
        new->data = a;
        new->pre = NULL;
        new->nxt = NULL;

        return new;
    }
    // 새로운 노드 연결
    new->data = a;
    new->pre = head;
    new->nxt = head->nxt;
    if (head->nxt != NULL)
    {
        head->nxt->pre = new;
    }
    head->nxt = new;

    return new;
}

void delete(node *cur)
{
    cur->pre->nxt = cur->nxt;
    if (cur->nxt != NULL)
    {
        cur->nxt->pre = cur->pre;
    }
}

void print(node *head)
{
    while (head != NULL)
    {
        // 첫번째 노드가 아니면 출력하기
        if (head->data != '*')
            printf("%c", head->data);
        node *tmp = head;
        head = head->nxt;
        free(tmp);
    }
}

int main()
{
    node *head = NULL;
    node *tmp = NULL;
    node *cursor = NULL;

    int t = 0; // 테스트 케이스 수
    int l = 0; // 문자열 길이
    char s[1000001];

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        // 문자열 입력
        scanf("%s", s);
        l = strlen(s);

        // 문자열 이중연결리스트 생성
        head = create(head, '*');
        cursor = head;
        for (int j = 0; j < l; j++)
        {
            if (s[j] == '<' && cursor->pre != NULL)
            {
                cursor = cursor->pre;
            }
            else if (s[j] == '>' && cursor->nxt != NULL)
            {
                cursor = cursor->nxt;
            }
            // 맨 앞 노드인 경우 예외처리 빼먹어서 런타임에러(AccessNullPointer) 발생했음
            else if (s[j] == '-' && cursor->pre != NULL)
            {
                delete(cursor);
                tmp = cursor;
                cursor = cursor->pre;
                free(tmp);
            }
            else if(isalnum(s[j]))
            {
                cursor = create(cursor, s[j]);
            }
        }
        print(head);
        printf("\n");
    }
    return 0;
}