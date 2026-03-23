#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, k, res = 0;
	queue<int> p, h;
	cin >> n >> k;

	for(int i=0 ; i<n ; i++) {
		char c;
		cin >> c;
		if(!p.empty() && p.front()+k < i) p.pop();
		if(!h.empty() && h.front()+k < i) h.pop();
		if(c == 'P') {
			if(!h.empty()) {
				h.pop();
				res++;
			}else p.push(i);
		}else if(c == 'H') {
			if(!p.empty()) {
				p.pop();
				res++;
			}else {
				h.push(i);
			}
		}
	}
	cout << res;
}