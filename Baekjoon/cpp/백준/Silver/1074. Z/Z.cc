#include <iostream>
#include <cmath>
using namespace std;

int cnt;

void f(int r, int c, int n) {
	if(n == 1) {
		if(r == 0 && c == 1) cnt++;
		if(r == 1 && c == 0) cnt += 2;
		if(r == 1 && c == 1) cnt += 3;
		return;
	}
	if(r < pow(2, n-1) && c < pow(2, n-1)) {
		f(r, c, n-1);
		return;
	}
	if(r < pow(2, n-1) && c >= pow(2, n-1)) {
		cnt += pow(pow(2, n-1), 2);
		f(r, c-pow(2, n-1), n-1);
		return;
	}
	if(r >= pow(2, n-1) && c < pow(2, n-1)) {
		cnt += 2*pow(pow(2, n-1), 2);
		f(r-pow(2, n-1), c, n-1);
		return;
	}
	if(r >= pow(2, n-1) && c >= pow(2, n-1)) {
		cnt += 3*pow(pow(2, n-1), 2);
		f(r-pow(2, n-1), c-pow(2, n-1), n-1);
		return;
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, r, c;
	
	cin >> N >> r >> c;
	f(r, c, N);
	cout << cnt;
}