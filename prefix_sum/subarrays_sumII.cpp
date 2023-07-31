// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
// map can use key as an negative number (NEW)
// Idea is when we calculate the subarray that from min 1 and max n 
// We have a value 1->n, and we have target value, so we can calculate the substract that make subarray equal x
// We have to find sum a -> n == x (1 <= a && a <= n)
// a -> n = 1 -> n - (1 -> a - 1 ) = x => 1 -> n - x == 1 -> a - 1
// so we only need to calculate the number of prefix that have value ==  (1 -> n) - x;
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

const string name_minh = "maxcross";
const int maxN = 2e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int prefix_sum[maxN];
unordered_map<int, int> num;
void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    num[0]++;
    foru(i, 1, n){
        int val;
        cin >> val;

        prefix_sum[i]  = prefix_sum[i - 1] + val;
        auto it = num.find(prefix_sum[i] - k);

        if(it != num.end()){
            ans += it -> second;
        }

        num[prefix_sum[i]]++;
    }

    cout << ans;


}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    //  freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif

    solve();

  
}