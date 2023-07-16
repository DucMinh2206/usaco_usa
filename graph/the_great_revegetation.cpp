
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

const string name_minh = "revegetate";
const int maxN = 100 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
bool diff[maxN][maxN];
int par[maxN], sz[maxN], color[maxN];
vector<int> component[maxN];
void init(int n){
    foru(i, 1, n){
        par[i] = i;
        sz[i] = 1;
        color[i] = -1;
    }
}
int find_pa(int x){
    return (x == par[x]) ? x : par[x] = find_pa(par[x]);
}

bool union_ab(int a, int b){
    a = find_pa(a);
    b = find_pa(b);

    if(a == b) return false;

    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    for(int x: component[b]){
        component[a].push_back(x);
    }
    return true;
}
bool check(int i, int j){
    
    for(int x: component[i]){
        for(int y: component[j]){
        //    cout << i << " " << j << " " << x << " " << y << endl;
            if(diff[x][y] || diff[y][x]) return false;
        }
    }
    return true;
}
void solve(){
    int n, m;
    cin >> n >> m;
    init(n);
    foru(i, 1, m){
        int a, b;
        cin >> a >> b;

        diff[b][a] = true;
        diff[a][b] = true;
    }
    foru(i, 1, n){
        component[i].push_back(i);
    }

    foru(i, 1, n){
        foru(j, i + 1, n){

            if(diff[i][j] || !check(find_pa(i), find_pa(j))) continue;
            //cout << i << " " << j << endl;
            union_ab(i, j);
            
        }
    }
    int cnt = 1;

    foru(i, 1, n){
        int ancestor = find_pa(i);
        if(color[ancestor] != -1){
           color[i] = color[ancestor];
        }
        else{
            color[ancestor] = cnt;
            color[i] = cnt;
            cnt++;
        }
    }
    foru(i, 1, n) cout << color[i];
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}