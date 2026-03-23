#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/13250

vector<double> cnt(1'000'001, 0.);

double p(int N) {
    if(N <= 0) return 0.;
    return cnt[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=1 ; i<=N ; i++) {
        double temp = 0.;
        for(int j=1 ; j<7 ; j++)
            temp += p(i - j);
        cnt[i] = 1. + temp / 6.;
    }

    cout << fixed;
    cout.precision(16);
    cout << p(N);
}