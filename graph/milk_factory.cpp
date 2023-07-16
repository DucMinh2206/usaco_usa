
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

const string name_minh = "factory";
const int maxN = 100 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> g[maxN];
int cnt[maxN], n;
void dfs(int u, int pre){

    for(int v: g[u]){
        if(v == pre) continue;

        cnt[v]++;
        dfs(v, u);
    }
}
void solve(){
    cin >> n;

    if(n == 1){
        cout << -1 << endl;
        return;
    }

    foru(i, 1, n - 1){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    foru(i, 1, n){
        dfs(i, -1);
    }

    foru(i, 1, n){
        if(cnt[i] == n - 1){
            cout << i;
            return;
        }
    }

    cout << -1 << endl;
}
signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}