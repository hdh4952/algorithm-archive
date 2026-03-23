#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

vector<int> primes;
vector<bool> isPrime(1e6 + 1, true);
vector<tuple<int, int, int>> myCase;

void init() {
    isPrime[0] = isPrime[1] = false;
    for(int i=2 ; i<1e6 ; i++) {
        for(int j=i+i ; j<=1e6 ; j+=i) {
            isPrime[j] = false;
        }
    }

    REP(i, 1 , 1e6) {
        if(isPrime[i]) primes.push_back(i);
    }
}

int surface(vector<int> v) {
    return 2 * (v[0]*v[1] + v[1]*v[2] + v[0]*v[2]);
}

void makeCase(int end, int cnt, vector<int> &v,vector<int> &tmp, vector<int> &answer) {
    if(end == cnt) {
        if(surface(tmp) < surface(answer)) answer = tmp;
        return;
    }

    REP(i, 0, 2) {
        tmp[i] *= v[cnt];
        makeCase(end, cnt + 1, v, tmp, answer);
        tmp[i] /= v[cnt];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    int n; cin >> n;
    vector<int> v;
    vector<int> tmp(3, 1), answer(3, 1000);

    for(auto prime : primes) {
        while(n != 1 && n % prime == 0) {
            v.push_back(prime);
            n /= prime;
        }
        if(n == 1) break;
    }

    makeCase(int(v.size()), 0, v, tmp, answer);
    for(auto i : answer) cout << i << " ";
}