// ����Լ��� ������?
#include <stdio.h>

void u_bar(int k)
{
    for (int i = 0; i < k; i++)
        printf("____");
}

void chatbot(int k, int n)
{
    if (k == n)
    {
        u_bar(k);
        printf("\"����Լ��� ������?\"\n");
        u_bar(k);
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
        u_bar(k);
        printf("��� �亯�Ͽ���.\n");
        return;
    }
    u_bar(k);
    printf("\"����Լ��� ������?\"\n");
    u_bar(k);
    printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
    u_bar(k);
    printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
    u_bar(k);
    printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
    chatbot(k + 1, n);
    u_bar(k);
    printf("��� �亯�Ͽ���.\n");
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    chatbot(0, n);
}