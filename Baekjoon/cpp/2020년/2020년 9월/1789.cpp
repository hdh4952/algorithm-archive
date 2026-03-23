#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	unsigned long long int tmp = 0, s;

	cin >> s;
	for(int i=1 ; i<=s ; i++) {
		if(tmp + i > s) {
			cout << i-1;
			return 0;
		}else if(tmp + i == s) {
			cout << i;
			return 0;
		}else tmp += i;
	}
}