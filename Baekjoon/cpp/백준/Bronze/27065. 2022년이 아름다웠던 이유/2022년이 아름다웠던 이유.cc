#include <bits/stdc++.h>
using namespace std;

bool isExcess(int n) {
    int sum = 0;
    for(int i=1 ; i<n ; i++) {
        if(n % i == 0) sum += i;
    }
    if(sum > n) return true;
    return false;
}

void solve() {
    int n; cin >> n;
    if(!isExcess(n)) {
        cout << "BOJ 2022\n";
        return;
    }

    for(int i=1 ; i<n ; i++) {
        if(n % i == 0 && isExcess(i)) {
            cout << "BOJ 2022\n";
            return;
        }
    }

    cout << "Good Bye\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) solve();
}