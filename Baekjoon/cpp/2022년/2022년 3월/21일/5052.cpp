#include <bits/stdc++.h>
using namespace std;

void solve();
bool cmp(string s1, string s2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}

void solve() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0 ; i<n ; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0 ; i<n-1 ; i++) {
        for(int k=i+1 ; k<n ; k++) {
            if(v[i].size() != v[k].size()) {
                for(int j=0 ; j<v[i].size() ; j++) {
                    if(v[i][j] != v[k][j]) break;
                    if(j == v[i].size()-1) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES\n";
}

bool cmp(string s1, string s2) {
    if(s1.size() != s2.size()) return s1.size() < s2.size();
    return s1 < s2;
}