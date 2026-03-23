#include <iostream>
using namespace std;

int n, m, cheese, pre, cnt;
int arr[100][100];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};

void f(int x, int y) {
	arr[x][y] = -1;
	for(int dir=0 ; dir<4 ; dir++) {
		int nx = x+px[dir], ny = y+py[dir];
		if(nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
		if(arr[nx][ny] > 0) arr[nx][ny]++;
		else if(arr[nx][ny] == 0) f(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			cin >> arr[i][j];
			if(arr[i][j]) cheese++;
		}
	}

	while(cheese != 0) {
		pre = cheese;
		cheese = 0;
		f(0, 0);
		for(int i=0 ; i<n ; i++) {
			for(int j=0 ; j<m ; j++) {
				if(arr[i][j] == 1) cheese++;
				else arr[i][j] = 0;
			}
		}
		cnt++;
		if(cheese == 0) break;
	}
	cout << cnt << "\n" << pre;
}