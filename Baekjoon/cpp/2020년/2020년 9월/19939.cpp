#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;

	if((k*k+k)/2 > n) {
		cout << "-1";
		return 0;
	}

	for(int i=1 ; i<=k ; i++) {
		arr[i] = i;
	}

	n -= (k*k+k)/2;
	while(n >= 0) {
		for(int i=k ; i>0 ; i--) {
			if(n == 0) {
				cout << arr[k]-arr[1];
				return 0;
			}
			arr[i]++;
			n--;
		}
	}
	cout << "-1";
}