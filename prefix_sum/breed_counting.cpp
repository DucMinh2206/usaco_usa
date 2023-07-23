
// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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
using ld = long double;

const string name_minh = "bcount";
const int maxN = 1e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n, q;
int cnt[4][maxN], prefix_sum[4][maxN];
void solve(){
    cin >> n >> q;
    foru(i, 1, n){
        int val;
        cin >> val;
        cnt[val][i]++;
    }
    foru(i, 1, n){ 
        foru(j, 1, 3){
            prefix_sum[j][i] = prefix_sum[j][i - 1] + cnt[j][i];
        }
    }

    foru(i, 1, q){
        int a, b;
        cin >> a >> b;
        foru(j, 1, 3){
            cout << prefix_sum[j][b] - prefix_sum[j][a - 1]; 
            if(j != 3) cout << " ";
        }
        if(i != q) cout << endl;
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