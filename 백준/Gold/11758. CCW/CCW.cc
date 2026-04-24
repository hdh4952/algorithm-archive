#include <bits/stdc++.h>
using namespace std;

struct vector2 {
  int x;
  int y;
};

int cross(vector2 p, vector2 q) {
  return p.x * q.y - p.y * q.x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  vector2 p, q;
  p.x = x2 - x1;
  p.y = y2 - y1;
  q.x = x3 - x2;
  q.y = y3 - y2;

  int ret = cross(p, q);
  if (ret == 0) cout << 0;
  else if (ret > 0) cout << 1;
  else cout << -1;

}