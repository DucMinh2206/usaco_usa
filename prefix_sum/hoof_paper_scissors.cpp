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

const string name_minh = "hps";
const int maxN = 1e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n;
int prefix_sum[4][maxN];
int counter[4] = {0, 2, 3, 1};
void solve(){
   cin >> n; 

   foru(i, 1, n){
        char c;
        cin >> c;
        if(c == 'H'){
            prefix_sum[1][i]++;
        }
        else if(c == 'S'){
            prefix_sum[2][i]++;
        }
        else prefix_sum[3][i]++;

        foru(j, 1, 3){
            prefix_sum[j][i] += prefix_sum[j][i - 1];
        }
   }
   int ans = 0;
   foru(i, 1, n){

        foru(j, 1, 3){
            int sum = 0;
            foru(k, 1, 3){
                int range_one = prefix_sum[counter[j]][i], range_two = 0;
                if(i != n) range_two = prefix_sum[counter[k]][n] - prefix_sum[counter[k]][i];
                // cout << i << endl;
                // cout << j << " " << k << " " << range_one << " " << range_two << endl;
                ans = max(ans, range_one + range_two);
            }
        }

   }

   cout << ans;
}

signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
     freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif

    solve();

  
}