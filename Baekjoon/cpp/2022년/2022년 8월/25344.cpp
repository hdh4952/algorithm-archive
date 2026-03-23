#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
ll t1, t2;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> t1;
    for(int i=0 ; i<n-3 ; i++) {
        cin >> t2;
        t1 = lcm(t1, t2);
    }

    cout << t1;
}