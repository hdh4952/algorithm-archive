#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    for(int i=0 ; i<s.size() ; i++) {
        string str;
        for(int j=i ; j<s.size() ; j++) {
            str += s[j];
        }
        v.push_back(str);
    }

    sort(v.begin(), v.end());

    for(auto a : v) cout << a << "\n";
}