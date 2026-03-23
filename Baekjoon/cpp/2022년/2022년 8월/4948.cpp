#include <bits/stdc++.h>
using namespace std;

bool isPrime[2 * 123456 + 10];

void f(int n) {
    if(n == 0) return;
    int res = 0;

    for(int i=n+1 ; i<=n * 2 ; i++) res += isPrime[i];
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    for(int i=2 ; i<=2 * 123456 ; i++) isPrime[i] = true;

    for(int i=2 ; i<=2 * 123456 ; i++) {
        for(int j=i+i ; j<= 2 * 123456 ; j+=i) {
            isPrime[j] = false;
        }
    }

    do {
        cin >> n;
        f(n);
    }while(n != 0);
}