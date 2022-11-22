#include <stdio.h>
#include <stdlib.h>

int board[510][510] = {0, };
int vis[510][510] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct queue {
    int a;
    int b;
} queue;

int main()
{
    int n = 0; 
    int m = 0; 
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &board[i][j]);
    }
    
    queue *q = (queue *)(malloc(sizeof(queue)* (n * m)));

    int cnt = 0; 
    int max = 0;
    int x = 0;
    int y = 0;
    int area = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 1 || board[i][j] == 0)
                continue;
            int head = 0;
            int tail = 0;
            vis[i][j] = 1;
            q[tail].a = i;
            q[tail].b = j;
            tail++;
            cnt++;
            area = 0;
            while (head < tail)
            {
                x = q[head].a;
                y = q[head].b;
                head++; 
                area++; 
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    q[tail].a = nx;
                    q[tail].b = ny;
                    tail++;
                }
            }
            if (area > max)
                max = area;
        }
    }
    free(q);
    printf("%d\n", cnt);
    printf("%d\n", max);
}