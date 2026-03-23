#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string str;
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    for(int i=0 ; i<str.size() ; i++) {
        if(i == str.size()-1) {
            ans++;
            continue;
        }else if(str[i] == 'c') {
            if(str[i+1] == '=' || str[i+1] == '-') i++;
        }else if(str[i] == 'd') {
            if(i+2 < str.size() && str[i+1] == 'z' && str[i+2] == '=') i += 2;
            if(str[i+1] == '-') i++;
        }else if((str[i] == 'n' || str[i] == 'l') && str[i+1] == 'j') i++;
        else if((str[i] == 's' || str[i] == 'z') && str[i+1] == '=') i++;
        ans++;
    }
    cout << ans;
}
