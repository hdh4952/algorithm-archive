#include <bits/stdc++.h>
using namespace std;

int n, m, res;
vector<int> v;

void f(int a);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	f(0);
}

void f(int a) {
	if(a == m) {
		for(auto i : v) cout << i << " ";
		cout << "\n";
		return;
	}
	for(int i=1 ; i<=n ; i++) {
		if(v.size() == 0) {
			v.push_back(i);
			f(a+1);
			v.pop_back();
		}else {
			v.push_back(i);
			f(a+1);
			v.pop_back();
		}
	}
}