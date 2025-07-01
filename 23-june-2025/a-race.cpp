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
║               [https://codeforces.com/contest/2112/problem/A]            ║                                           
╚══════════════════════════════════════════════════════════════════════════╝
*/

// #include "stdc++.h"
#include <bits/stdc++.h>
using namespace std;

// Macros for competitive programming
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

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
  int a, x, y;
  cin >> a >> x >> y;

  int bDiff = abs(x-y);
  int aDiff1 = abs(a-x);
  int aDiff2 = abs(a-y);

  if(bDiff <= aDiff1 || bDiff <= aDiff2){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  fast
    
  int t;
  cin >> t;

  while(t--) {
      solve();
  }

  return 0;
}
