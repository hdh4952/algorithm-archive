#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

void f();

int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) f();
}

void f() {
	char arr[1001][1001];
	queue<pair<int, int> > Q, F; // 상근이의 위치, 불의 위치
	bool visitQ[1001][1001] = {0,}, visitF[1001][1001] = {0,};
	int w, h;

	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '@') {
				Q.push({i, j});
				visitQ[i][j] = true;
			}
			if (arr[i][j] == '*') {
				F.push({i, j});
				visitF[i][j] = true;
			}
		}
	}
	int cnt = 0;

	while (!Q.empty()) {
		int size = F.size();
		for (int u = 0; u < size; u++) {
			int x = F.front().X, y = F.front().Y;
			F.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + px[dir], ny = y + py[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(visitF[nx][ny]) continue;
				visitF[nx][ny] = true;
				if(arr[nx][ny] != '#') {
					arr[nx][ny] = 'F';
					F.push({nx, ny});
				}
			}
		}
		size = Q.size();
		for (int u = 0; u < size; u++) {
			int x = Q.front().X, y = Q.front().Y;
			Q.pop();
			if(x == 0 || x == h-1 || y == 0 || y == w-1) {
				cout << cnt+1 << "\n";
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + px[dir], ny = y + py[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(visitQ[nx][ny]) continue;
				visitQ[nx][ny] = true;
				if(arr[nx][ny] == '.') {
					arr[nx][ny] = '@';
					Q.push({nx, ny});
				}
			}
		}
		cnt++;
	}
	cout << "IMPOSSIBLE" << "\n";
}