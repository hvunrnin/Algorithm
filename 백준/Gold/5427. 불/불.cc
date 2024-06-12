#include <iostream>
#include <queue>
#include <algorithm> // fill 사용

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[1002];
int dist1[1002][1002]; // 불의 확산 시간
int dist2[1002][1002]; // 상근이의 이동 시간
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int w, h;
        cin >> w >> h;
        for (int j = 0; j < h; j++) {
            fill(dist1[j], dist1[j] + w, -1);
            fill(dist2[j], dist2[j] + w, -1);
        }
        for (int j = 0; j < h; j++) {
            cin >> board[j];
            for (int k = 0; k < w; k++) {
                if (board[j][k] == '*') {
                    dist1[j][k] = 0;
                    Q1.push({ j, k });
                }
                if (board[j][k] == '@') {
                    dist2[j][k] = 0;
                    Q2.push({ j, k });
                }
            }
        }

        // 불의 BFS
        while (!Q1.empty()) {
            auto cur = Q1.front();
            Q1.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
                Q1.push({ nx, ny });
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            }
        }

        int cnt = 3000;
        // 상근이의 BFS
        while (!Q2.empty()) {
            auto cur = Q2.front();
            Q2.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cnt = dist2[cur.X][cur.Y] + 1;
                    Q2 = queue<pair<int, int>>(); // 큐를 비워서 종료
                    break;
                }
                if (board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
                if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
                Q2.push({ nx, ny });
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            }
        }

        if (cnt == 3000) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << cnt << "\n";
        }

        // 큐를 비웁니다.
        Q1 = queue<pair<int, int>>();
        Q2 = queue<pair<int, int>>();
    }
    return 0;
}
