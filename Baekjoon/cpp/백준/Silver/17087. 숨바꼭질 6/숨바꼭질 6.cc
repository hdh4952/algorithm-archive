#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    ll S; cin >> S;
    vector<ll> v(N, 0);
    REP(i, 0, N - 1) cin >> v[i];
    ll answer = abs(v.back() - S);
    v.pop_back();
    for(auto i : v) answer = gcd(answer, abs(i - S));
    cout << answer;
}