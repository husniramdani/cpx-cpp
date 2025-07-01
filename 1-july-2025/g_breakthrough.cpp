/*
╔══════════════════════════════════════════════════════════════════════════╗
║                              SPINDYZEL                                   ║
║                         [BREAKTHROUGH ATTEMPT]                          ║
╚══════════════════════════════════════════════════════════════════════════╝
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

      // Key insight: Count total "deficit" instead of simulating
      ll total_deficit = 0;
      ll cycles_needed = 0;
      ll current_pos = 0;
      
      for (int i = 0; i < n; ++i) {
        ll target = a[i] % g;
        
        if (target >= current_pos) {
          total_deficit += (target - current_pos);
        } else {
          // Need to wrap around
          total_deficit += (target - current_pos + g);
          cycles_needed++;
        }
        current_pos = target;
      }
      
      // Check if we can fit within m
      ll max_full_cycles = (m - 1) / g;
      ll remaining_space = (m - 1) % g;
      
      if (cycles_needed > max_full_cycles || 
          (cycles_needed == max_full_cycles && total_deficit - cycles_needed * g > remaining_space)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
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