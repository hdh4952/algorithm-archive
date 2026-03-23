#include <bits/stdc++.h>
using namespace std;

void f();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) f();
}

void f() {
	stack<char> s;
	string str;
	cin >> str;
	for(int i=0 ; str[i]!='\0' ; i++) {
		if(str[i] == '(') s.push(str[i]);
		else {
			if(s.empty()) {
				cout << "NO" << "\n";
				return;
			}else s.pop();
		}
	}
	if(!s.empty()) cout << "NO" << "\n";
	else cout << "YES" << "\n";
}