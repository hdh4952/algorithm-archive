#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, F;
    while(cin >> M >> F) {
        if(!M && !F) break;
        cout << M + F << "\n";
    }
}