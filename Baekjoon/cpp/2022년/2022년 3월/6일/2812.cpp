#include <bits/stdc++.h>
using namespace std;

int n, k;
string N;
stack<int> s, tmp, ans;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k >> N;
    for(int i=0 ; i<n ; i++) {
        s.push(N[n-i-1] - '0');
    }

    while(!s.empty()) {
        if(k == 0) {
            tmp.push(s.top());
            s.pop();
        }else {
            while(!tmp.empty() && s.top() > tmp.top() && k > 0) {
                tmp.pop();
                k--;
            }
            tmp.push(s.top());
            s.pop();
        }
    }
    while(k--) tmp.pop();
    while(!tmp.empty()) {
        ans.push(tmp.top());
        tmp.pop();
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}