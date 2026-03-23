#include <bits/stdc++.h>
using namespace std;

vector<int> A, cal, tmp;
bool vis[10];
long long int maxValue = -10000000000, minValue = 10000000000;
int n;

void f(int a);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;

	for(int i=0 ; i<n ; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	for(int i=0 ; i<4 ; i++) {
		int a;
		cin >> a;
		for(int j=0 ; j<a ; j++) {
			cal.push_back(i);
		}
	}
	f(0);
	cout << maxValue << "\n" << minValue;
}

void f(int a) {
	if(a == n-1) {
		long long int sum = A[0];
		for(int i=1 ; i<A.size() ; i++) {
			switch(tmp[i-1]) {
				case 0:
					sum += A[i];
					break;
				case 1:
					sum -= A[i];
					break;
				case 2:
					sum *= A[i];
					break;
				case 3:
					sum /= A[i];
					break;
			}
		}
		if(sum > maxValue) maxValue = sum;
		if(sum < minValue) minValue = sum;
		return;
	}
	for(int i=0 ; i<cal.size() ; i++) {
		if(tmp.empty()) {
			tmp.push_back(cal[i]);
			vis[i] = true;
			f(a+1);
			tmp.pop_back();
			vis[i] = false;
		}else {
			if(vis[i]) continue;
			tmp.push_back(cal[i]);
			vis[i] = true;
			f(a+1);
			tmp.pop_back();
			vis[i] = false;
		}
	}
}