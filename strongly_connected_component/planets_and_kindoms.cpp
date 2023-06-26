// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long 
const string name_minh = "citystate";
const int maxN = 1e5 + 5;
const int mod = 1000003;
const long long inf = 1e17;

vector<int> g[maxN], order, g_rev[maxN];
int kindom[maxN], cnt = 0;
bool visited[maxN];
void dfs(int u){
    visited[u] = true;
    for(int v : g[u]){
        if(visited[v]) continue;

        dfs(v);
    }

    order.push_back(u);
}

set<int> component;
void dfs_two(int u){
    component.insert(u);
    visited[u] = true;
    kindom[u] = cnt;

    for(int v: g_rev[u]){
        if(visited[v]) continue;

        dfs_two(v);
    }
}

signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    int n, m;
    cin >> n >> m;

    foru(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g_rev[b].push_back(a);
    }

    foru(i, 1, n){
        if(!visited[i]){
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());
    foru(i, 1, n) visited[i] = false;

    for(int u : order){
        if(visited[u] == true) continue;

        cnt++;
        dfs_two(u);
    }

    cout << cnt << endl;
    foru(i, 1, n) cout << kindom[i] << " ";

   
    
}
