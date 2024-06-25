#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define la(i, n) for (int i = 0; i < n; i++)  // loop around
#define ela(i, n) for (int i = 0; i < n; i++) // Equal Loop Around
#define pba push_back
#define pfa push_front
#define popb pop_back
#define popf pop_front
#define gla(i, a, n) for (int i = a; i < n; i++) // general loop around
#define empb emplace_back
#define empf emplace_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()
#define sq(x) ((x) * (x))
#define lasqr(i, n) for (int i = 0; i * i < n; i++) // loop around square root
#define mpair make_pair
#define mtuple make_tuple

typedef vector<int> vint;
typedef vector<ll> vill;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;

static void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int nu, de;
  // if ((double)a / b <= (double)c / d) {
  // if (a * d <= b * c) {
  // }
  // } else {
  //   n = a * d - b * c;
  //   de = a * d;
  // }

  if (a * d > b * c) {
    nu = a * d - b * c;
    de = a * d;
  } else {
    nu = b * c - a * d;
    de = b * c;
  }
  // cout << nu << " " << de << endl; // Just realized that nu & de -> nude
  int hcf = gcd(nu, de);
  nu = nu / hcf;
  de = de / hcf;
  cout << nu << "/" << de << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}