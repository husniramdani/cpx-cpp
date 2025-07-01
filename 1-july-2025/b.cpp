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

void solve() {
    int n, j, k;
    cin >> n >> j >> k;


    vector<int> a(n);
    int player_j_strength = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == j-1) {
            player_j_strength = a[i];
        }
    }

    int c_less = 0;
    int c_equal = 0;
    int c_greater = 0;

    for (int i = 0; i < n; ++i) {
        if (i == j-1) {
            continue;
        }

        if (a[i] < player_j_strength) {
            c_less++;
        } else if (a[i] == player_j_strength) {
            c_equal++;
        } else {
            c_greater++;
        }
    }

    if (k == 1) {
        if (c_greater > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        int elim_from_greater = max(0, c_greater - (k - 1));
        int remaining_eliminations_needed = (n - k) - elim_from_greater;

        if (c_less + c_equal >= remaining_eliminations_needed) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
