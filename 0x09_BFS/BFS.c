#include <stdio.h>
#include <stdbool.h>

typedef struct pos
{
    int X;
    int Y;
}pos;

// 1이 파란칸, 0이 빨간 칸
int board[502][502] = {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                       {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                       {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool vis[502][502]; // 방문했는지 체크
int q[502][2];
int head = 0;
int tail = 0;
int n = 7; // 행
int m = 10; // 열
// 아래, 오른쪽, 위, 왼쪽 순으로 좌표 이동
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cur[1][2];

void push(int x, int y)
{
    q[tail][0] = x;
    q[tail][1] = y;
    tail++;
}

void pop()
{
    head++;
}

int main()
{
    pos cur;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 색칠 안되거나 이미 방문한 칸 넘김
            if (board[i][j] == 0 || vis[i][j])
                continue;
            vis[i][j] = 1; // 방문 표시
            push(i, j);    // 큐에 추가
        }
        // 큐가 빌 때까지 반복
        while (head != tail)
        {
            // 큐의 head를 cur에 저장하고 pop
            cur.X = q[head][0];
            cur.Y = q[head][1];
            pop();
            printf("(%d, %d)\n", cur.X, cur.Y); // 방문 순서 출력
            // 상하좌우 칸 살펴봄
            for (int dir = 0; dir < 4; dir++)
            {
                // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표 넣음
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 가장자리 체크
                    continue;
                if (vis[nx][ny] || board[nx][ny] != 1) // 이미 방문한 칸, 파란색 아닌 칸 넘김
                    continue;
                vis[nx][ny] = 1;
                push(nx, ny); // 큐에 방문한 칸 넣음
            }
        }
    }
}