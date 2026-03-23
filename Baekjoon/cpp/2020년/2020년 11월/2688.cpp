#include <iostream>
#include <vector>
using namespace std;

long long int arr[65][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0 ; i<=9 ; i++) {
		arr[1][i] = 1;
	}
	for(int i=2 ; i<=64 ; i++) {
		for(int j=0 ; j<=9 ; j++) {
			long long int tmp = 0;
			for(int k=0 ; k<=j ; k++) {
				tmp += arr[i-1][k];
			}
			arr[i][j] = tmp;
		}
	}

	int t;
	cin >> t;
	while(t--) {
		long long int n, res = 0;
		cin >> n;
		for(int i=0 ; i<=9 ; i++) {
			res += arr[n][i];
		}
		cout << res << "\n";
	}
}