// A idea is very simple
// If we got 1 -> a % 7 == x, and 1 -> a == 1 -> b + (b + 1 -> a)
// If we got 1 -> b % 7 == x, so (b + 1 -> a) % 7 == 0.

// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
#ifdef MINHDEPTRAI

 
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
#define __gcd(a, b) gcd(a, b)
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

const string name_minh = "div7";
const int maxN = 1e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n;
int prefix_sum[maxN];
vector<int> du[10];
void solve(){
   cin >> n; 
   int ans = 0;
   foru(i, 1, n){
        int val;
        cin >> val;
        prefix_sum[i] = (prefix_sum[i - 1] + val) % 7;
        if(val % 7 == 0) ans = 1;
        du[prefix_sum[i]].push_back(i);
   }
   foru(i, 0, 6){
        if(du[i].size() <= 1) continue;

        ans = max(ans, du[i][du[i].size() - 1] -  du[i][0]);
   }

   cout << ans;
}

signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
     freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif

    solve();

  
}