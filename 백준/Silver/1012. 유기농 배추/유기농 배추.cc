#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[52][52];
bool vis[52][52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T > 0) {
		int m, n, k;
		cin >> m >> n >> k;
		queue<pair<int, int>> Q;
		while (k > 0) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
			k--;
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0 || vis[i][j]) {
					continue;
				}
				cnt++;
				Q.push({ i,j });
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx<0 || nx>=m|| ny<0 || ny>=n){
							continue;
						}
						if (board[nx][ny] == 0 || vis[nx][ny]) {
							continue;
						}
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < m; i++) {
			fill(board[i], board[i] + n, 0);
			fill(vis[i], vis[i] + n, false);
		}
		T--;
	}
}
