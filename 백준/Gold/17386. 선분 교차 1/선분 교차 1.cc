#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;

  friend istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

// Vector(p1 -> p2) to p3
int ccw(Point p1, Point p2, Point p3) {
  p1.x -= p2.x;
  p1.y -= p2.y;
  p3.x -= p2.x;
  p3.y -= p2.y;

  long long t = p1.x * p3.y - p3.x * p1.y;
  if (t > 0)
    return 1;
  else if (t < 0)
    return -1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Point p1, p2, p3, p4;
  cin >> p1 >> p2 >> p3 >> p4;
  if (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0
      && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0)
    cout << 1;
  else
    cout << 0;
}