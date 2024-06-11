#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int board[102][102][102];
int dist[102][102][102];
queue <tuple<int, int, int>> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tmp;
				cin >> tmp;
				board[k][j][i] = tmp;
				if (tmp == 1) Q.push({ k,j,i });
				if (tmp == 0) dist[k][j][i] = -1;
			}
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz]>=0 || board[nx][ny][nz] == -1) continue;
			Q.push({ nx,ny,nz });
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[k][j][i] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[k][j][i]);
			}
		}
	}
	cout << ans;
}