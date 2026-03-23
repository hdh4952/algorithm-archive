#include <bits/stdc++.h>
using namespace std;

int g;
vector<int> v, ans;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> g;

    for(int i=1 ; i<=g ; i++) if(g%i == 0) v.push_back(i);
    for(int i=0 ; i<v.size()/2 ; i++) {
        int l = v[i], r = v[v.size()-1-i];
        if((r+l)%2 != 0) continue;
        ans.push_back((r+l)/2);
    }

    if(ans.size() == 0) cout << "-1";
    else {
        sort(ans.begin(), ans.end());
        for(auto i : ans) cout << i << "\n";
    }
}