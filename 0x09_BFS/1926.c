// 그림
#include <stdio.h>

int main() {
  int board[502][502];
  int vis[502][502];
  int q[250000][2]; // q 공간을 충분히 할당하지 않아서 틀렸었음
  int head = 0;
  int tail = 0;
  // 상, 하, 좌, 우 좌표 이동
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  int n = 0; // 행
  int m = 0; // 열

  scanf("%d %d", &n, &m);

  // 그림판 입력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", &board[i][j]);
  }

  int cnt = 0; // 그림 수 카운트
  int max = 0; // 그림 최대 면적
  // 좌표 이동 위한 변수 선언
  int x = 0;
  int y = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 이미 방문한 칸이나 색칠 안된 칸 패스
      if (vis[i][j] || board[i][j] == 0)
        continue;
      // 색칠된 칸 표시하고 큐에 넣음
      // printf("nx, ny = (%d, %d)\n", i, j);

      vis[i][j] = 1;
      q[tail][0] = i;
      q[tail][1] = j;
      tail++;
      cnt++; // 그림 수 증가

      int area = 0; // 그림 면적 초기화
      // 큐가 빌 때까지 반복
      while (head != tail) {
        x = q[head][0];
        y = q[head][1];
        head++; // pop
        area++; // pop할 때마다 그림 면적 증가
        // printf("(%d, %d)\n", x, y);
        // 좌표 상하좌우 체크
        for (int dir = 0; dir < 4; dir++) {
          // printf("===check===\n");
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          // 가장자리 체크
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
            // printf("edge\n");
            continue;
          }
          // 이미 방문했거나 색칠 안 된 칸 패스
          if (vis[nx][ny] || board[nx][ny] != 1) {
            // printf("visited or empty\n");
            continue;
          }
          // printf("nx,ny = (%d, %d)\n", nx, ny);
          vis[nx][ny] = 1;
          q[tail][0] = nx;
          q[tail][1] = ny;
          //printf("ny = %d\n", ny);
          //printf("q[%d][0] = %d, q[%d][1] = %d\n", tail, q[tail][0], tail, q[tail][1]);
          tail++;
        }
      }
      if (area > max)
        max = area;
    }
  }
  printf("%d\n", cnt);
  printf("%d\n", max); // 개행 빼먹음.. => 상관 없었다
}