#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char arr[20];
bool vis[26];
vector<char> tmp;

void f(int n) {
    if(n == L) {
        int vowel = 0, consonant = 0;
        for(auto i : tmp) {
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ) vowel++;
            else consonant++;
        }
        if(vowel && consonant >= 2) {
            for(auto i : tmp) {
                cout << i;
            }
            cout << "\n";
        }
        return;
    }

    for(int i=0 ; i<C ; i++) {
        if(tmp.empty()) {
            tmp.push_back(arr[i]);
            vis[arr[i] - 'a'] = true;
            f(n+1);
            tmp.pop_back();
            vis[arr[i] - 'a'] = false;
        } else {
            if(vis[arr[i] - 'a'] == false && tmp.back() < arr[i]) {
                tmp.push_back(arr[i]);
                vis[arr[i] - 'a'] = true;
                f(n+1);
                tmp.pop_back();
                vis[arr[i] - 'a'] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+C);

    f(0);
}