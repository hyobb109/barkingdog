#include <stdio.h>

int dat[1000005];
int pos = 0;

// 스택에 x 추가하는 함수
void push(int x)
{
    dat[pos++] = x;
}

// 스택의 맨 위 원소 제거
void pop()
{
    pos--;
}

// 스택의 맨 위 원소 값 확인
int top()
{
    return dat[pos - 1];
}

void test()
{
    push(5); 
    push(4); 
    push(3);
    printf("top: %d\n", top()); // 3
    pop();
    pop();
    printf("top: %d\n", top()); // 5
    push(10);
    push(12);
    printf("top: %d\n", top()); // 12
    pop();
    printf("top: %d\n", top()); // 10
}

int main()
{
    test();
}