#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

void solve() {
    string p; cin >> p;
    int n; cin >> n;
    string x; cin >> x;
    x = x.substr(1, x.size() - 2);

    vector<int> v;
    int num = 0;
    for(auto ch : x) {
        if(ch == ',') {
            v.push_back(num);
            num = 0;
        } else {
            num = num * 10 + ch - '0';
        }
    }
    if(n) v.push_back(num);

    int left = 0, right = int(v.size() - 1);
    bool isReverse = false, isError = false;
    for(auto ch : p) {
        if(ch == 'D') {
            if(left > right) {
                isError = true;
                break;
            }
            if(!isReverse) left++;
            else right--;
        } else isReverse = !isReverse;
    }

    if(isError) {
        cout << "error\n";
        return;
    }
    cout << "[";
    if(left > right) cout << "]\n";
    else if(!isReverse) {
        for(int i=left ; i<right ; i++) cout << v[i] << ",";
        cout << v[right] << "]\n";
    } else {
        for(int i=right ; i>left ; i--) cout << v[i] << ",";
        cout << v[left] << "]\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--) solve();
}