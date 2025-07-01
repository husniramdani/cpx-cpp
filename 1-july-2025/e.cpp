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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> freq(n + 2, 0);
    for(int x : a) {
        if(x <= n) freq[x]++;
    }
    
    vector<pair<int, int>> ranges;
    
    int prefix_extra = 0;
    int suffix_total = 0;
    for(int i = 0; i <= n; i++) {
        suffix_total += freq[i];
    }
    
    for(int m = 0; m <= n + 1; m++) {
        if(m > 0 && freq[m-1] == 0) break;
        
        if(m > 0) {
            prefix_extra += max(0, freq[m-1] - 1);
            suffix_total -= freq[m-1];
        }
        
        int must_remove = freq[m];
        int flexible = prefix_extra + suffix_total - freq[m];
        
        int min_k = must_remove;
        int max_k = min(n, must_remove + flexible);
        
        if(min_k <= max_k) {
            ranges.push_back({min_k, max_k});
        }
    }
    
    vector<int> result(n + 1, 0);
    vector<int> diff(n + 2, 0);
    
    for(auto& range : ranges) {
        diff[range.first]++;
        diff[range.second + 1]--;
    }
    
    int current = 0;
    for(int k = 0; k <= n; k++) {
        current += diff[k];
        result[k] = current;
    }
    
    for(int i = 0; i <= n; i++) {
        cout << result[i];
        if(i < n) cout << " ";
    }
    cout << "\n";
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
