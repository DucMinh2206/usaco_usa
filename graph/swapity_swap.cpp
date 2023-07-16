
#define MINHDEPTRAI 1
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

const string name_minh = "swap";
const int maxN = 100 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
struct node{
    int rank, a, b;
};
bool cmp(node &a, node &b){
    if(a.rank == b.rank){
        return (a.a < b.a);
    }
    else return (a.rank > b.rank);
}
bool visited[maxN];
vector<node> component[maxN];
int par[maxN], sz[maxN], val[maxN], ans[maxN];
void init(int n){
    foru(i, 1, n){
        par[i] = i;
        sz[i] = 1;
    } 
}
int find_pa(int x){
    return (x == par[x]) ? x : par[x] = find_pa(par[x]);
}
bool union_ab(int a, int b){
    //cout << a << " hi " << b << endl;
    a = find_pa(a);
    b = find_pa(b);
    //cout << a << " ha " << b << endl;

    if(a == b) return false;

    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
    //cout << a << " " << b << endl;
    for(node &v: component[b]){
        component[a].push_back(v);
    }
    component[b].clear();
    return true;
}
void solve(){
    int k, n;
    cin >> n >> k;
    init(n);
    foru(i, 1, 2) {
        int a, b;
        cin >> a >> b;

        foru(j, 0, (b - a + 1) / 2 - 1){
            //cout << a + j << " haha " << b - j << endl;
            component[find_pa(a + j)].push_back({i % 2, a + j, b - j});
            union_ab(a + j, b - j);
        }
    }

    foru(i, 1, n) val[i] = i;

    foru(i, 1, n){
        if(visited[i]) continue;
        int ancestor = find_pa(i);
        int siz = sz[ancestor];

        // cout << i << " hi  " << siz << endl;
        sort(component[ancestor].begin(), component[ancestor].end(), cmp);

        foru(j, 1, k % siz){

            for(node &v: component[ancestor]){
                swap(val[v.a], val[v.b]);
                // cout << v.a << " merge " << v.b << " " << val[v.a] << " " << val[v.b] << endl;
            }
        }

        for(node &v : component[ancestor]){
            // ans[v.a] = val[v.a];
            // ans[v.b] = val[v.b];
            visited[v.a] = true;
            visited[v.b] = true;
        }
    }
    
    foru(i, 1, n){
        cout << val[i]  << endl;
    }
}
   
signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}