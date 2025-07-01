/*
╔══════════════════════════════════════════════════════════════════════════╗
║                              SPINDYZEL                                   ║
║                                                                          ║
║                       ⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀ ⢠⠞⠉⠙⠲⡀⠀                           ║
║                  ⠀⠀     ⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀ ⢳⡀⠀ ⡏⠀⠀⠀⠀ ⢷                           ║
║                       ⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀ ⣧⠀⢸⠀⠀⠀⠀⠀ ⡇                           ║
║                       ⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲ ⣿⠀⣸⠀⠀OK⠀ ⡇                           ║
║                       ⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀ ⣿⠀⢹⠀⠀⠀⠀⠀ ⡇                           ║
║                       ⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀ ⡿⠀⠀⡇⠀⠀⠀⠀⡼                            ║
║                       ⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀ ⠀⠘⠤⣄⣠⠞⠀                            ║
║                  ⠀⠀     ⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                            ║
║                       ⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀                            ║
║                       ⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀                            ║
║                       ⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀                            ║
║                       ⣿⣿⣧⣀⣿.........⣀⣰⣏⣘⣆⣀⠀⠀                             ║
║                                                                          ║
║               []                                                         ║                                           
╚══════════════════════════════════════════════════════════════════════════╝
*/

// #include "stdc++.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

struct Query {
    int op, pos;
    ll x;
};

map<ll, int> gcd_map;
ll fmp[300];
const int N = 1e5 + 10;
int ans[300];

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void solve() {
  int n;
  ll m;
  int q;
  cin >> n >> m >> q;
  
  gcd_map.clear();
  
  vector<ll> a(n + 1);
  vector<Query> queries(q + 1);
  
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  int num = 0;
  for (int i = 1; i <= q; i++) {
    auto &[op, pos, x] = queries[i];
    cin >> op;
    if (op == 1) {
      cin >> pos >> x;
    } else {
      cin >> x;
      ll g = gcd(m, x);
      if (!gcd_map.count(g)) {
        gcd_map[g] = ++num;
        fmp[num] = g;
      }
    }
  }
  
  // Precompute violation counts for each GCD
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= num; j++) {
      ll g = fmp[j];
      if (a[i] % g < a[i - 1] % g) {
        ans[j]++;
      }
    }
  }
  
  auto cmp = [&](ll x, ll y, ll k) {
    return x % k <= y % k;
  };
  
  // Process queries
  for (int i = 1; i <= q; i++) {
    auto [op, pos, x] = queries[i];
    if (op == 1) {
      // Update violation counts for all GCDs
      for (int j = 1; j <= num; j++) {
        ll g = fmp[j];
        // Check left neighbor
        if (pos > 1 && cmp(a[pos - 1], a[pos], g) && !cmp(a[pos - 1], x, g)) {
          ans[j]++;
        }
        if (pos > 1 && !cmp(a[pos - 1], a[pos], g) && cmp(a[pos - 1], x, g)) {
          ans[j]--;
        }
        // Check right neighbor
        if (pos < n && cmp(a[pos], a[pos + 1], g) && !cmp(x, a[pos + 1], g)) {
          ans[j]++;
        }
        if (pos < n && !cmp(a[pos], a[pos + 1], g) && cmp(x, a[pos + 1], g)) {
          ans[j]--;
        }
      }
      a[pos] = x;
    } else {
      ll g = gcd(x, m);
      if (ans[gcd_map[g]] < m / g) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  
  // Reset for next test case
  for (int i = 1; i <= num; i++) {
    ans[i] = 0;
    fmp[i] = 0;
  }
}

int main() {
    fast
    
    int t = 1;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}
