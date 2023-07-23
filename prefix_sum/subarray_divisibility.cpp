// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
#ifdef MINHDEPTRAI
// The idea is very same to this problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
// But the different is you have a negative value
// We have an definition a % n == x => a - x % n == 0 => a - x + n % n == 0
// If a - x < 0, we can plus n and it is still divisible by n
// So we have prefix sum if there is some postion with the same remainder which is divide by n => we add to the answer
 
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

const string name_minh = "hps";
const int maxN = 2e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n;
int prefix_sum[maxN];
map<int, int> num;
void solve(){
    cin >> n; 
    foru(i, 1, n){
        int val;
        cin >> val;
        prefix_sum[i]  = prefix_sum[i - 1] + val;
   }
   foru(i, 1, n){
        prefix_sum[i] %= n;
        // cout << prefix_sum[i] << endl;
        if(prefix_sum[i] < 0) prefix_sum[i] += n;
        num[prefix_sum[i] ]++;
   }

   int ans = 0;
   for(auto x: num){
    //cout << x.first << " "  << x.second << endl;
        ans += (x.second * (x.second - 1)) / 2;

        int val = x.first % n;
        if(val == 0){
            ans += x.second;
        }
   }
   cout << ans;
}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    //  freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif

    solve();

  
}