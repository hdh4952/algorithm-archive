#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll k, n = 1, i=0;

ll mul(ll cnt) {
    if(cnt < 0) return 0;
    ll x = 1;
    for(int i=0 ; i<cnt ; i++) x *= 2;
    return x;
}

string f(ll len, ll cnt) {
    if(len == 1) {
        if(cnt == 1) return "4";
        if(cnt == 2) return "7";
    }

    if(mul(len - 1) >= cnt) return "4" + f(len-1, cnt);
    else return "7" + f(len - 1, cnt - (mul(len - 1)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while(k > 2*n) {
        k -= 2*n;
        n *= 2;
        i++;
    }
    cout << f(i+1, k);
}