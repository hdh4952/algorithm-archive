#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[10];
vector<int> v, tmp;

void f(int a);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;

	for(int i=0 ; i<n ; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	f(0);
}

void f(int a) {
	if(a == m) {
		for(auto i : tmp) cout << i << " ";
		cout << "\n";
		return;
	}
	for(int i=0 ; i<v.size() ; i++) {
		if(tmp.empty()) {
			tmp.push_back(v[i]);
			vis[i] = true;
			f(a+1);
			tmp.pop_back();
			vis[i] = false;
		}else {
			if(vis[i]) continue;
			tmp.push_back(v[i]);
			vis[i] = true;
			f(a+1);
			tmp.pop_back();
			vis[i] = false;
		}
	}
}