#include <stdio.h>

int dat[2000011];
int head = 1000005;
int tail = 1000005;

void push_front(int x)
{
    dat[--head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int front()
{
    return dat[head];
}

int back()
{
    return dat[tail - 1];
}

void test()
{
    push_back(30); // 30
    printf("%d\n", front()); // 30
    printf("%d\n", back()); // 30
    push_front(25);          // 25 30
    push_back(12);           // 25 30 12
    printf("%d\n", back());  // 12
    push_back(62);           // 25 30 12 62
    pop_front();             // 30 12 62
    printf("%d\n", front()); // 30
    pop_front();             // 12 62
    printf("%d\n", back());  // 62
}

int main(void)
{
    test();
}