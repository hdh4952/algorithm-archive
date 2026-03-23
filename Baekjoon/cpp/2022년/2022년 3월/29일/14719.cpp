#include <bits/stdc++.h>
using namespace std;

int h, w, ans, cmp;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;

    s.push(0);

    for(int i=0 ; i<w ; i++) {
        int x;
        cin >> x;
        if(cmp <= x) {
            while(!s.empty()) {
                ans += cmp - s.top();
                s.pop();
            }
            s.push(x);
            cmp = x;
        }else s.push(x);
    }

    if(!s.empty()) {
        int a = s.top();
        while(!s.empty()) {
            if(a < s.top()) {
                a = s.top();
                s.pop();
            }else {
                ans += a - s.top();
                s.pop();
            }
        }
    }

    cout << ans;
}
