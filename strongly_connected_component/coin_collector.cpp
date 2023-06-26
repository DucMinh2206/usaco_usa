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
vector<int> g_group[maxN];
int group[maxN], cnt = 0;
int sum_gp[maxN], coins[maxN], dp[maxN];
bool visited[maxN];
void dfs_one(int u){
    visited[u] = true;

    for(int v: g[u]){
        if(visited[v]) continue;

        dfs_one(v);
    }
    order.push_back(u);
}

void dfs_two(int u){
    group[u] = cnt;
    visited[u] = true;

    for(int v: g_rev[u]){
        if(visited[v]) continue;

        dfs_two(v);
    }
}
int DP(int i){
    if(dp[i]) return dp[i];

    dp[i] = sum_gp[i];
    for(int j : g_group[i]){
        //cout << dp[i] << " adj " << DP(j) + << endl;
        dp[i] = max(dp[i], DP(j) + sum_gp[i]);
    }
    //cout << i << " sum " << dp[i] << endl;


    return dp[i];
}

signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    int n, m;
    cin >> n >> m;

    foru(i, 1, n) cin >> coins[i];
 
    foru(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g_rev[b].push_back(a);
    }

    foru(i, 1, n){
        if(visited[i])continue;
        dfs_one(i);
    }
    reverse(order.begin(), order.end());
    memset(visited, false, sizeof(visited));
    for(int u: order){
       if(visited[u]) continue;

       cnt++;
       dfs_two(u);
    }  

    foru(i, 1, n){
        sum_gp[group[i]] += coins[i];
    }

    foru(i, 1, n){
        for(int adj : g[i]){
            if(group[i] == group[adj]) continue;

            g_group[group[i]].push_back(group[adj]);
        }
    }

    int ans = 0;
    foru(i, 1, cnt){
        ans = max(ans, DP(i));
    }
    cout << ans; 


}
