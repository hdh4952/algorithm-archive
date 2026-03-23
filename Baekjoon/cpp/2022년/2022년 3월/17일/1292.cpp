#include <bits/stdc++.h>
using namespace std;

int a, b, cnt, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    for(int i=1 ; i<=10000 ; i++) {
        for(int j=1 ; j<=i ; j++) {
            cnt++;
            if(a <= cnt && cnt <= b) ans += i;
            if(cnt == b) {
                cout << ans;
                return 0;
            }
        }
    }
}

