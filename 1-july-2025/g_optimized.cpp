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
║               [OPTIMIZED VERSION]                                        ║                                           
╚══════════════════════════════════════════════════════════════════════════╝
*/

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

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int query_idx = 0; query_idx < q; ++query_idx) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      ll x;
      cin >> i >> x;
      a[i - 1] = x;
    } else {
      ll k;
      cin >> k;

      ll g = gcd(k, m);

      if (g == 1) {
        cout << "YES\n";
        continue;
      }

      ll min_needed = 0;
      bool possible = true;

      for (int i = 0; i < n; ++i) {
        ll target_rem = a[i] % g;
        ll current_rem = min_needed % g;
        
        if (current_rem <= target_rem) {
          min_needed += (target_rem - current_rem);
        } else {
          min_needed += (target_rem - current_rem + g);
        }
        
        if (min_needed >= m) {
          possible = false;
          break;
        }
      }

      cout << (possible ? "YES" : "NO") << '\n';
    }
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