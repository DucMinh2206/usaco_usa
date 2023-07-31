// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// The idea for this problem is instead of considering from beggin to end we traverse from end to beggin 
// to calculate suffix to remove 10 ^ (j - i + 1).

// I forget to mode so it get WA

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
 
const string name_minh = "input";
const int maxN = 2e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
int suffix[maxN];
int binpow(int a, int mu){
    int res = 1;
    while(mu > 0){
        if(mu & 1) res = (res * a) % 2019;

        mu = mu >> 1;
        a = (a * a) % 2019;
    }
    return res;
}
map<int, int> val;
void solve(){
    string s;
    cin >> s;

    int n = s.size(), ans = 0;
    s = " " + s;
    ford(i, n, 1){
        suffix[i] = (suffix[i + 1]  + (s[i] - '0') * binpow(10, n - i)) % 2019;
        auto it = val.find(suffix[i]);
        if(it != val.end()){
            ans += it -> second;
        }
        if(!(suffix[i])) ans++;

        val[suffix[i]]++;
    }
    cout << ans << endl;
}
 
signed  main() {
    IOS
 
    // #ifdef MINHDEPTRAI 
    // freopen((name_minh + ".txt").c_str(), "r", stdin);
    //  freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif
    int t = 1;
    while(t--){
        solve();
    }
  
}
