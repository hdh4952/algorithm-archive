#include <bits/stdc++.h> // http://wookje.dance/2017/02/20/boj-1300-K%EB%B2%88%EC%A7%B8-%EC%88%98/
#define ll long long int
using namespace std;

int n, ans;
ll k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int l = 1;
    int r = k;
    while(l <= r) {
        ll cnt = 0;
        int m = (l+r)/2;
        for(int i=1 ; i<=n ; i++) cnt += min(m/i, n);
        if(cnt < k) l = m+1;
        else ans = m, r = m-1;
    }

    cout << ans;
}