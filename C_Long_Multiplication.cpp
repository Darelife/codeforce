#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;

const int inf = 1e9 + 5;

// int binpow(int a, int b) {
//   int res = 1;
//   while (b > 0) {
//     if (b & 1)
//       res = res * a;
//     a = a * a;
//     b >>= 1;
//   }
//   return res;
// }

void solve() {
  // // 2 integers of the same length to maximise the product of them, and print
  // // the new 2 numbers
  // int a, b;
  // cin >> a >> b;
  // string aa = to_string(a), bb = to_string(b);
  // // the product of 2 numbers is the largest when the numbers are as close as
  // // possible

  // if (a == b) {
  //   cout << a << endl << b << endl;
  //   return;
  // }

  // int n = (int)log10(a) + 1;
  // if (n == 1) {
  //   if (b > a)
  //     swap(a, b);
  //   cout << a << endl << b << endl;
  //   return;
  // }

  // int xx = 0;
  // for (int i = 0; i < (int)log10(a) + 1; i++) {
  //   int al = aa[xx];
  //   int bl = bb[xx];
  //   xx++, n--;
  //   if (bl > al) {
  //     swap(a, b);
  //     break;
  //   } else if (al > bl)
  //     break;
  // }
  // // cout << a << " " << b << " " << n << " " << (int)log10(a) << endl;
  // // the (n-1)th index the first different digit
  // aa = to_string(a), bb = to_string(b);
  // string na = aa, nb = bb;
  // // cout << log10(a) << endl;
  // for (int i = (int)log10(a) + 1 - n;
  //      i < (int)log10(a) + 1 && (int)log10(a) != 0; i++) {
  //   char ca = aa[i], cb = bb[i];
  //   if (ca > cb) {
  //     na[i] = cb;
  //     nb[i] = ca;
  //   } else {
  //     na[i] = ca;
  //     nb[i] = cb;
  //   }
  //   // cout << ca << " " << cb << endl;
  // }
  // cout << na << endl << nb << endl;
  string a, b;
  cin >> a >> b;
  // cout << "-------------------\n";
  int n = a.size();

  int firstLarge = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      swap(a[i], b[i]);
    }
    if (a[i] != b[i]) {
      firstLarge = i;
      break;
    }
  }

  // cout << a << endl << b << endl;

  // cout << firstLarge << endl;
  for (int i = firstLarge + 1; i < n; i++) {
    // cout << a[i] << " " << b[i] << endl;
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
      // break;
    }
  }
  cout << a << endl << b << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}