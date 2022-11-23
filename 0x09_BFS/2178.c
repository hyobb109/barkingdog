// 미로 탐색
#include <stdio.h>

int board[105][105];
int dist[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int q[10000][2];

int main()
{
    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &board[i][j]);
            dist[i][j] = -1; // 거리 -1로 초기화
        }
    }

    int head = 0;
    int tail = 0;

    // (0, 0) 큐에 담고 거리 board에 넣음
    q[0][0] = 0;
    q[0][1] = 0;
    tail++;
    dist[0][0] = 0;

    while (head != tail)
    {
        // 큐 맨 앞 좌표 옮기고 pop
        int X = q[head][0];
        int Y = q[head][1];
        head++;
        // printf("(%d, %d), dist = %d\n", X, Y, dist[X][Y]);
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != 1)
                continue;
            // 큐에 담고 (0, 0)으로부터 거리 계산
            q[tail][0] = nx;
            q[tail][1] = ny;
            tail++;
            dist[nx][ny] = dist[X][Y] + 1;
        }
    }
    printf("%d\n", dist[n - 1][m - 1] + 1);
}