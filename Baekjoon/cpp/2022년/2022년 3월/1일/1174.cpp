#include <bits/stdc++.h>
using namespace std;

int n, ans = -1;
vector<int> tmp;

void f(int len, int cnt) {
    if(len == cnt) {
        if(--n == 0) for(int i=0 ; i<tmp.size() ; i++) cout << tmp[i];
        return;
    }

    for(int i=0 ; i<=9 ; i++) {
        if(!cnt && i==0) continue;
        if(tmp.empty()) tmp.push_back(i);
        else {
            if(tmp.back() > i) tmp.push_back(i);
            else continue;
        }
        f(len, cnt+1);
        tmp.pop_back();
        if(n <= 0) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    if(n <= 10) {
        cout << n-1;
        return 0;
    }
    n -= 10;
    for(int len=2 ; len<=10 ; len++) {
        f(len, 0);
        if(n <= 0) return 0;
    }
    cout << ans;
}
