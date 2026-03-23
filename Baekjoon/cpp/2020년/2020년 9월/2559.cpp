#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k, idx = 0, tmp = 0;
	vector<int> v;

	cin >> n >> k;

	for(int i=0 ; i<n ; i++) {
		cin >> arr[i];
		tmp += arr[i];
		if(i-idx+1 == k) {
			v.push_back(tmp);
			tmp -= arr[idx];
			idx++;
		}
	}
	sort(v.begin(), v.end());
	cout << v[v.size()-1];
}