#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int, int>;

#define forr(i, n) for (int i = 0; i < n; i++)
#define reforr(i, n) for (int i = n-1; i >= 0; i--)
#define eqforr(i, a, n) for (int i = a; i <= n; i++)
#define sqforr(i, n) for (int i = 1; i * i <= n; i++)
#define genforr(i, a, b) for (int i = a; i < b; i++)
#define pba push_back
#define popb pop_back
#define popf pop_front
#define allEle(x) (x).begin(), (x).end()
#define allRle(x) (x).rbegin(), (x).rend()

typedef vector<int> vint;
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;


const int inf = 1e9 + 5;

int digitSum(int n) {
  if (n < 10) return n;
  return n % 10 + digitSum(n / 10);
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vint ones(n), zeroes(n);
  ones[0] = (a[0] == '1');
  zeroes[0] = (a[0] == '0');

  for (int i = 1; i < n; ++i) {
    ones[i] = ones[i - 1] + (a[i] == '1');
    zeroes[i] = zeroes[i - 1] + (a[i] == '0');
  }

  if (a == b) {
    cout << "YES\n";
    return;
  }
  int index = n - 1, flag = 1;
  for (int i = n - 1;i >= 0;i--)
    if (a[i] != b[i]) { index = i; break; }
  for (int i = index;i >= 0;i--)
  {
    if (zeroes[index] != ones[index])
    {
      cout << "NO" << endl;return;
    }
    if (a[i] == b[i] && flag == 1)
    {
      index = i;
      flag = 0;
    } else if (a[i] != b[i] && flag == 0)
    {
      flag = 1;
      index = i;
    }


  }
  if (zeroes[index] != ones[index])
  {
    cout << "NO" << endl;return;
  }
  cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}