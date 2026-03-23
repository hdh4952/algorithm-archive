#include <bits/stdc++.h>
using namespace std;

int res;
void f();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	while(n--) f();
	cout << res;
}

void f() {
	bool check[26] = {0, };
	string str;
	cin >> str;
	for(int i=0; str[i+1] != '\0' ; i++) {
		if(check[str[i]-'a']) return;
		if(str[i] != str[i+1]) {
			check[str[i]-'a'] = true;
			continue;
		}
	}
	if(check[str[str.size()-1]-'a']) return;
	res++;
}