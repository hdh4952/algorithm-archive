#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int answer = 0, x;
    REP(i, 1, 3) {
        cin >> x;
        if(N < x) answer += N;
        else answer += x;
    }

    cout << answer;
}