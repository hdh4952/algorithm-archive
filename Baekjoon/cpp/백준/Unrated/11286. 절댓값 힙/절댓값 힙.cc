#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, x;
  cin >> N;

  priority_queue<int> minus;
  priority_queue<int, vector<int>, greater<>> plus;

  while(N--) {
    cin >> x;
    if(x) {
      if(x > 0) plus.push(x);
      else minus.push(x);
    } else {
      if(minus.empty() && plus.empty()) cout << "0\n";
      else if(minus.empty()) {
        cout << plus.top() << "\n";
        plus.pop();
      } else if(plus.empty()) {
        cout << minus.top() << "\n";
        minus.pop();
      } else {
        if(plus.top() < -minus.top()) {
          cout << plus.top() << "\n";
          plus.pop();
        } else {
          cout << minus.top() << "\n";
          minus.pop();
        }
      }
    }
  }
}