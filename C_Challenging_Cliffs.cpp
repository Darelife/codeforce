#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define la(i, a, n) for (int i = a; i < n; i++)      // loop around
#define rla(i, n) for (int i = n; i >= 0; i--)       // reverse loop around
#define ela(i, a, n) for (int i = a; i <= n; i++)    // Equal Loop Around
#define lasqr(i, n) for (int i = 1; i * i <= n; i++) // loop around square root
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vi;

const int inf = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &i : a)
    cin >> i;

  sort(allEle(a));
  vi diff(n - 1);
  for (int i = 0; i < n - 1; i++) {
    diff[i] = a[i + 1] - a[i];
  }
  int minDiff = *min_element(allEle(diff));
  int minDiffIndex = min_element(allEle(diff)) - diff.begin();
  int startH = a[minDiffIndex];
  int endH = a[minDiffIndex + 1];

  cout << startH << " ";
  for (int i = minDiffIndex + 2; i < n; i++) {
    // if (i == minDiffIndex || i == minDiffIndex + 1)
    //   continue;
    cout << a[i] << " ";
  }
  for (int i = 0; i < minDiffIndex; i++) {
    cout << a[i] << " ";
  }
  cout << endH << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}