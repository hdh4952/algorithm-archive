#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

double cal(int N) {
    double answer = 0.0;
    REP(i, 0, N-1) answer += (double)N / (double)(N-i);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    cout.precision(10);
    cout << cal(N);
}