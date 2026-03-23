#include <bits/stdc++.h>
using namespace std;

int arr[4000001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	vector<int> v;
	int n;

	cin >> n;
	for(int i=2 ; i<=n ; i++) {
		arr[i] = i;
	}
	for(int i=2 ; i<=n ; i++) {
		for(int j=i+i ; j<=n ; j+=i) {
			arr[j] = 0;
		}
	}

	for(int i=2 ; i<=n ; i++) {
		if(arr[i]) v.push_back(arr[i]);
	}
	int tmp = 0, cnt = 0, idx = 0;
	for(auto i : v) {
		tmp += i;
		bool flag = false;
		while(tmp >= n) {
			tmp -= v[idx++];
			flag = true;
		}
		if(flag) {
			idx--;
			tmp += v[idx];
		}
		if(tmp == n) cnt++;
	}
	cout << cnt;
}