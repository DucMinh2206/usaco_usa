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
 
const string name_minh = "art";
const int maxN = 4e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
int n, q;
vector<int> num;
pair<pii, int> update[maxN];
pii queries[maxN]; 

int val[maxN], range[maxN], diff[maxN], prefix_sum[maxN];
int compress_idx(int vl){
       return lower_bound(num.begin(), num.end(), vl) - num.begin();
}

void solve(){
     cin >> n >> q;
     foru(i, 1, n) {
            int a, b, c;
            cin >> a >> b >> c;

            update[i] = mp(mp(a, b), c);
            num.push_back(a);
            num.push_back(b);
     }

     foru(i, 1, q){
            int a, b;
            cin >> a >> b;
             queries[i] = mp(a, b);
            num.push_back(a);
            num.push_back(b);
     }
     // we make a vector into a set to get the index of lower bound in above function.
     sort(num.begin(), num.end());
     num.erase(unique(num.begin(), num.end()) , num.end());

     int x = (int)num.size() - 1; 
     foru(i, 1, n){
            int vl = update[i].second;
            diff[compress_idx(update[i].first.first) + 1] += vl;
            diff[compress_idx(update[i].first.second) + 1] -= vl;

            // diff: the differences between range[i + 1] and range[i]
     }
     foru(i, 1, x){
            val[i]  = val[i - 1] + diff[i];
            // the calculate the prefix sum to calculate value of range[i] (from num[i] -> num[i + 1] - 1);
     }

     foru(i, 0, x - 1){
            range[i + 1] = num[i + 1] - num[i];
            // note that num is 0 index vector, so range[i] from num[i] -> num[i + 1] - 1;
            // we caculate the length of range[i]  from (num[i] -> num[i + 1] - 1)
     }
     foru(i, 1, x) {
            prefix_sum[i] = val[i] * range[i] + prefix_sum[i - 1];
            // we caculcate the prefix_sum for quering in O(1).
     }
     foru(i, 1, q){
            cout << prefix_sum[compress_idx(queries[i].second) ]  - prefix_sum[compress_idx(queries[i].first)] << endl;
            // it is right because
            // for example
            // 0 -> 3 -> 6 -> 9, we want to calculate 3 -> 8
            // so what is we doing is 0 -> 2 + 3 -> 5 + 5 -> 8 - 0 -> 2 = 3 -> 8 (that why we not addding one into compress_idx).
     }
     
}
signed  main() {
      IOS 
//     #ifndef MINHDEPTRAI 
//     freopen((name_minh + ".in").c_str(), "r", stdin);
//      freopen((name_minh + ".out").c_str(), "w", stdout);
//     #endif

    int t = 1;
    while(t--){
      solve();
    }
  
}