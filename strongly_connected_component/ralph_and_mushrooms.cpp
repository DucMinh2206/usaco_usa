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
typedef long long int int2;
const string name_minh = "3";
#define int long long
const int maxN = 1e6 + 5;
const int mod = 1000003;
const long long inf = 1e17;

int n, m, cnt, group[maxN], sum_group[maxN], dp[maxN];
map<int, int> prefix_sub, prefix_dnc;
vector<pair<int, int>> g[maxN], g_rev[maxN], g_group[maxN];
vector<int> order;
bool visited[maxN];

void dfs_one(int u){
    visited[u] = true;

    for(pair<int, int> x: g[u]){
        int v = x.first;
        if(visited[v] == true) continue;

        dfs_one(v);
    }
    order.push_back(u);
}
void dfs_two(int u){
    group[u] = cnt;
    visited[u] = true;

    for(pair<int, int> x: g_rev[u]){
        int v = x.first;
        if(visited[v]) continue;

        dfs_two(v);
    }
}
int binary_search(int val){
    int res = -1, l = 0, r = 1e6 + 8e1;
    

    while(l < r){
        int mid = (l + r) >> 1;
        int vl = (mid * (mid + 1)) / 2;
        //cout << vl << endl;
        if(vl <= val){
            res = mid;
            l = mid + 1;
        }
        else r = mid; 
    }
   // return res;
    return val * (res + 1) - (res * (res + 1) * (res + 2)) / 6;
}

int DP(int i){
    if(dp[i]) return dp[i];

    dp[i] = sum_group[i];

    for(pair<int, int> x: g_group[i]){
        int v = x.first;
        int w = x.second;
        //cout << i << " " << v << endl;
        dp[i] = max(dp[i], DP(v) + w + sum_group[i]);
        //cout << dp[i] << endl;
    }
    return dp[i];
}
signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    cin >> n >> m;
    foru(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(mp(b, c));
        g_rev[b].push_back(mp(a, c));
    }
    int start;
    cin >> start;


    foru(i, 1, n){
        if(visited[i]) continue;
        dfs_one(i);
    }

    memset(visited, false, sizeof(visited));
    reverse(order.begin(), order.end());

    for(int i : order){
        //cout << i << " order " << endl;
        if(visited[i]) continue;

        cnt++;
        dfs_two(i);
    }

    foru(i, 1, n){
        for(pair<int, int> x: g[i]){
            int v = x.first;
            int mush = x.second;
            //cout << i << " " << v << endl;
            if(group[v] == group[i]){
                //cout << binary_search(mush) << " " << mush << endl;
                sum_group[group[v]] += binary_search(mush);
            }
            else {
                g_group[group[i]].push_back(mp(group[v], mush));
            }
           
        }
    }

    cout << DP(group[start]);
}
