
// #define MINHDEPTRAI 1
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

const string name_minh = "planting";
const int maxN = 1e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> g[maxN];
int ans[maxN];
void solve(){
    int n;
    cin >> n;

    foru(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    int max_val = 0;
    // reason:
    //   B
    //A  F   C
    //   D
    // if we choose F is the answer so F, and some nodes arround must be different
    // so the minimum if we choose F (the center) is the number of edges that directly connected with F + 1 (g[F].size( ) + 1 may_be like that);
    // answer = maximum all of that 
    // it is right because we have consider some node that have distances >= 3, the cnt of that nodes are always X + 1 (in case that we use repeated node) (X is the other node).
    //
    
    foru(i, 1, n){
        
        max_val = max(ans[i], max_val);
    }
    cout << max_val + 1;
    return; 
}
signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}