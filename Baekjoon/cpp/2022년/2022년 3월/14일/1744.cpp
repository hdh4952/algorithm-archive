#include <bits/stdc++.h>
using namespace std;

int n, pCnt, mCnt;
int p[51];
int m[51];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int x;
        cin >> x;
        if(x > 0) {
            p[pCnt] = x;
            pCnt++;
        }else {
            m[mCnt] = x;
            mCnt++;
        }
    }
    sort(p, p+pCnt, greater<>());
    sort(m, m+mCnt);
    for(int i=0 ; i<pCnt ; i++) {
        if(i+1 != pCnt) {
            if(p[i] * p[i+1] > p[i] + p[i+1]) {
                ans += p[i] * p[i+1];
                i++;
            }else ans += p[i];
        }else ans += p[i];
    }
    for(int i=0 ; i<mCnt ; i++) {
        if(i+1 != mCnt) {
            if(m[i] * m[i+1] > m[i] + m[i+1]) {
                ans += m[i] * m[i+1];
                i++;
            }else ans += m[i];
        }else ans += m[i];
    }
    cout << ans;
}

