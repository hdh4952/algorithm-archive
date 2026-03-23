#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

vector<bool> isPrime(1e6 + 1, true);

void init() {
    isPrime[0] = isPrime[1] = false;
    REP(i, 2, 1e6) {
        for(int j=i+i ; j<=1e6 ; j+=i) {
            isPrime[j] = false;
        }
    }
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    int N; cin >> N;
    ll answer = 1, A;
    REP(i, 1, N) {
        cin >> A;
        if(isPrime[A]) answer = lcm(answer, A);
    }

    if(answer == 1) cout << "-1";
    else cout << answer;
}