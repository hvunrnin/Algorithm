#include <iostream>
#include <algorithm>
using namespace std;

char star[3100][6200];

void printStar(int x, int y, int n) {
	//기본 별찍기
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
	}
	else {
		printStar(x, y, n / 2);
		printStar(x + n / 2, y - n / 2, n / 2);
		printStar(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
        fill(star[i], star[i] + 2 * N - 1, ' ');
    }

	printStar(0, N - 1, N);//x좌표, y좌표, N값
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}
