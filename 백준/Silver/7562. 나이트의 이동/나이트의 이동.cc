#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

#define X first
#define Y second

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int board[302][302];
int dist[302][302];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;
		memset(board, 0, sizeof(board));
		memset(dist, 0, sizeof(dist));
		queue<pair<int, int>> Q;
		Q.push({ startX, startY });
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (dist[nx][ny] != 0 || (nx == startX && ny == startY)) continue;
				Q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
		cout << dist[endX][endY] << "\n";
	}
}