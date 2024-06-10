#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[102];
string board2[102];
int vis[102][102];
int vis2[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		board2[i] = board[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') {
				board2[i][j] = 'R';
			}
		}
	}
	queue<pair<int, int>> Q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) {
				continue;
			}
			Q.push({ i,j });
			vis[i][j] = 1;
			cnt++;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				auto color = board[cur.X][cur.Y];
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx<0 || nx>=n || ny<0 || ny>=n) {
						continue;
					}
					if (vis[nx][ny]||board[nx][ny]!=color) {
						continue;
					}
					Q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
	queue<pair<int, int>> Q2;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis2[i][j]) {
				continue;
			}
			Q2.push({ i,j });
			vis2[i][j] = 1;
			cnt2++;
			while (!Q2.empty()) {
				auto cur = Q2.front();
				Q2.pop();
				auto color = board2[cur.X][cur.Y];
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
						continue;
					}
					if (vis2[nx][ny] || board2[nx][ny] != color) {
						continue;
					}
					Q2.push({ nx,ny });
					vis2[nx][ny] = 1;
				}
			}
		}
	}
	cout << cnt << " " << cnt2;
}