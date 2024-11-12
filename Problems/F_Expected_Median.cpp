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
typedef vector<string> vstr;
#define vcstr(vstr, n) forr(i, n) cin >> vstr[i]
#define vcin(vint, n) forr(i, n) cin >> vint[i]
#define vpin(vint) for (auto x : vint) cout << x << " "; cout << endl;
#define vpstr(vstr) for (auto x : vstr) cout << x << " "; cout << endl;

void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V> void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

int fac[200007];
int MOD = 1e9 + 7;
const int inf = 1e9 + 5;

int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int func(int a, int b) {
  int r = 1;
  while (b > 0) {
    if (b & 1)r = (r * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return r;
}
int nCr(int n, int r)
{
  if (n == r)return 1;
  return (fac[n]) * (func((fac[r] * fac[n - r]) % MOD, MOD - 2)) % MOD;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int count0 = 0, count1 = 0;
  forr(i, n) {
    cin >> a[i];
    if (a[i] == 0) count0++;
    else count1++;
  }
  if (count1 == 0) {
    cout << "0" << endl;
    return;
  }
  int ans = 0;
  reforr(i, k + 1) {
    if (i > count1 || count0 < k - i)continue;
    if (i < k - i)break;
    ans = (ans + ((nCr(count1, i)) * (nCr(count0, k - i)))) % MOD;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  fac[0] = 1;
  for (int i = 1;i < 200005;i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}
