#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N+1, 0), B(M+1, 0);
    REP(i, 1, N) cin >> A[i];
    REP(i, 1, M) cin >> B[i];

    int nowBook = 1, nowBox = 1;
    while(nowBook != M + 1) {
      if(B[nowBook] > A[nowBox]) nowBox++;
      else A[nowBox] -= B[nowBook++];
    }

    cout << accumulate(A.begin() + 1, A.end(), 0);
}