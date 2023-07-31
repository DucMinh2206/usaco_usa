// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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

const string name_minh = "stacking";
const int maxN = 2e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;

int n, prefix_gcd[maxN], suffix_gcd[maxN], arr[maxN];

int __gcd(int a, int b){
    
    if(b == 0) return a;
    return __gcd(b, a % b);
}

void solve(){
    cin >> n;

    foru(i, 1, n) cin >> arr[i];

    foru(i, 1, n){
        prefix_gcd[i] = __gcd(prefix_gcd[i - 1], arr[i]);
    }

    ford(i, n, 1){
        suffix_gcd[i] = __gcd(suffix_gcd[i + 1], arr[i]);
    }
    int ans = 0;
    foru(i, 1, n){
        // cout << prefix_gcd[i - 1] << " " << suffix_gcd[i + 1] << endl;
        ans = max(ans, __gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]));
    }

    cout << ans << endl;
    return;
}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    //  freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif
    int t = 1;
    while(t--){
        solve();
    }
  
}