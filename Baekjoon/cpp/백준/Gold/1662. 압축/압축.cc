#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int solve(string s) {
    int ans = 0, pre = 0;
    stack<int> st;
    REP(i, 0, s.size() - 1) {
        if(s[i] == '(') {
            ans--;
            ans += pre * solve(s.substr(i+1, s.size() - i));
            pre = 0;
            st.push(0);
            int j = i;
            while(!st.empty()) {
                j++;
                if(s[j] == '(') st.push(0);
                else if(s[j] == ')') st.pop();
            }
            i = j;
        } else if(s[i] == ')') {
            return ans;
        } else {
            ans++;
            pre = s[i] - '0';
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    cout << solve(s);
}