#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S; cin >> S;
    string answer;
    vector<bool> check('z' - 'a' + 1, false);
    int K; cin >> K;
    char preCh = '.';
    for(auto &ch : S) {
        if('a' <= ch && ch <= 'z') ch += char('A' - 'a');
    }
    int cnt = 0;
    for(auto &ch : S) {
        if(preCh == ch) cnt++;
        else {
            if(preCh != '.' && !check[preCh - 'A']) {
                check[preCh - 'A'] = true;
                if(cnt >= K) answer += "1";
                else answer += "0";
            }
            preCh = ch;
            cnt = 1;
        }
    }
    if(preCh != '.' && !check[preCh - 'A']) {
        check[preCh - 'A'] = true;
        if(cnt >= K) answer += "1";
        else answer += "0";
    }
    cout << answer;
}