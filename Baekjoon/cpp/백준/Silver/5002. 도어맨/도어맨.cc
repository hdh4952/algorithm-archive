#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X; cin >> X;
    string s; cin >> s;
    int keep = 0, m = 0, w = 0;
    for(auto ch : s) {
        if(abs(m - w) < X) {
            if(ch == 'M') m++;
            else w++;
        } else {
            if(m < w && ch == 'M') m++;
            else if(m > w && ch == 'W') w++;
            else {
                if(keep == 0) {
                    if(ch == 'M') keep = 1;
                    else keep = 2;
                } else if(m < w && keep == 1) {
                    keep = 2;
                    m++;
                } else if(m > w && keep == 2) {
                    keep = 1;
                    w++;
                } else {
                    cout << m + w;
                    return 0;
                }
            }
        }
    }

    if(keep == 1 && (m - w) < X || keep == 2 && (w - m) < X) cout << m + w + 1;
    else cout << m + w;
}