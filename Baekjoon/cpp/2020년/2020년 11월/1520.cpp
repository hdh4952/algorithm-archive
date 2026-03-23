#include <bits/stdc++.h>

using namespace std;

int n, m, res;
int memo[500][500];
int arr[500][500];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};

int f(int x, int y) {
	if (x == n-1 && y == m-1) return 1;
	if(memo[x][y] >= 0) return memo[x][y];
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + px[dir], ny = y + py[dir];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(arr[x][y] > arr[nx][ny]) cnt += f(nx, ny);
	}
	return memo[x][y] = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(memo, -1, sizeof(memo));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	res = f(0, 0);

	cout << res;

/*
	cout <<"\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << memo[i][j] << " ";
		}
		cout << "\n";
	}
 */
}