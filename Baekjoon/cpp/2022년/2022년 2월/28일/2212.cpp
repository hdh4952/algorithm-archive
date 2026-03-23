#include <bits/stdc++.h>
#define INF 2000010
using namespace std;

int n, k, ans;
bool arr[2000001];
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;

    for(int i=0 ; i<n ; i++) {
        int N;
        cin >> N;
        arr[N+1000000] = true;
    }
    for(int i=0 ; i<=2000000 ; i++) if(arr[i]) v.push_back({i, i});
    while(v.size() > k) {
        int gap = INF;
        int idx = 0;
        for(int i=0 ; i<v.size()-1 ; i++) {
            int cmp = v[i+1].first - v[i].second;
            if(cmp < gap) {
                idx = i;
                gap = cmp;
            }
        }
        v.insert(v.begin()+idx+2, {v[idx].first, v[idx+1].second});
        v.erase(v.begin()+idx, v.begin()+idx+2);
    }
    for(int i=0 ; i<v.size() ; i++) ans += v[i].second - v[i].first;
    cout << ans;
}