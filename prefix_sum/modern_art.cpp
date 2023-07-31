// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"

// My idea is very easy.
// For each color if from upper left corner point -> lower right corner point have some another color -> 
// that another color have can't be colored first
// So my solution is brute force

// but I have one special case when it have only color, so that color can't be first.

#ifdef MINHDEPTRAI
 
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
using namespace std ::chrono;
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
using ld = long double;
 
const string name_minh = "art";
const int maxN = 1e3 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
pair< pii, pii> par[maxN * maxN];

int grid[maxN][maxN], prefix_sum[maxN][maxN], ans[maxN * maxN], cnt;
void solve(){
      int n;
      cin >> n;
      foru(i, 1, n * n){
            par[i] = mp(mp(inf, inf), mp(-inf, -inf));
      }
      foru(i, 1, n) {
            foru(j, 1, n){
                  cin >> grid[i][j];
                  int val = grid[i][j];
                  par[val] = mp(mp(min(i, par[val].first.first), min(j, par[val].first.second)), mp(max(i, par[val].second.first), max(j, par[val].second.second)));
            }
      }

      int sum = 0;
      foru(p, 1, n * n){
            if(par[p] != mp(mp(inf, inf), mp(-inf, -inf))){

                  foru(i, par[p].first.first, par[p].second.first){
                        foru(j, par[p].first.second, par[p].second.second){
                              if(grid[i][j] != p) ans[grid[i][j]] = 1;
                        }
                  }
                  cnt++;
            }
      }

       foru(p, 1, n * n) if(!ans[p]) sum++;
      if(cnt == 1){
            cout << n * n - 1 << endl;
      }
      else cout << sum << endl;
}
signed  main() {
      IOS 
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
     freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
  
}