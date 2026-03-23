#include <bits/stdc++.h>
using namespace std;

int m, n;
int prime[10001];
int ans1, ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for(int i=2 ; i<=n ; i++) prime[i] = i;
    for(int i=2 ; i<=n ; i++)
        for(int j=i+i ; j<=n ; j+=i) prime[j] = 0;

    for(int i=m ; i<=n ; i++) {
        if(prime[i] && !ans1) ans1 = i;
        if(prime[i]) ans2 += i;
    }

    if(!ans1) cout << "-1";
    else cout << ans2 << "\n" << ans1;
}
