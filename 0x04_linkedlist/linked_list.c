#include <stdio.h>

const int MX = 1000005;
int dat[1000005];
int pre[1000005];
int nxt[1000005];
int unused = 1;

void insert(int addr, int num)
{
    // 새로운 원소 생성
    dat[unused] = num;
    // 새 원소의 pre값에 삽입할 위치 주소 대입
    pre[unused] = addr;
    // 새 원소의 nxt값에 삽입할 위치의 nxt값 대입
    nxt[unused] = nxt[addr];
    // 맨 마지막 원소 뒤에 새 원소 추가하는 상황이 아니면
    if (nxt[addr] != -1)
    {
        // 다음 원소의 pre값을 새 원소로 변경
        pre[nxt[addr]] = unused;
    }
    // 삽입할 위치의 nxt값을 새 원소로 변경
    nxt[addr] = unused;
    // 다음 자리로 옮김
    unused++;
}

void erase(int addr)
{
    // 이전 위치의 nxt를 삭제할 위치의 nxt로 변경
    nxt[pre[addr]] = nxt[addr];
    // 마지막 원소가 아니면
    if (nxt[addr] != -1)
    {
        // 다음 위치의 pre를 삭제할 위치의 pre로 변경
        pre[nxt[addr]] = pre[addr];
    }
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        printf("%d\n", dat[cur]);
        cur = nxt[cur];
    }
    printf("\n");
}

void insert_test()
{
    printf("****** insert_test *****\n");
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test()
{
    printf("****** erase_test *****\n");
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main()
{
    for (int i = 0; i < MX; i++)
    {
        pre[i] = -1;
        nxt[i] = -1;
    }
    insert_test();
    erase_test();
}