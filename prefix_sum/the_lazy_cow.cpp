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
 
const string name_minh = "lazy";
const int maxN = 4e2 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;

int prefix_sum[maxN][maxN], grid[maxN][maxN], n, k;

int sum_square(int a, int b, int c, int d){
      return prefix_sum[c][d] + prefix_sum[a - 1][b - 1] - prefix_sum[a - 1][d] - prefix_sum[c][b - 1];
}

int calculate(int i, int j){
    int sum = 0;
    //  --- val --- (two side k)
    pair<int, int> before = mp(i, j);

    sum += sum_square(i, j, i, min(j + k, n));
    sum += sum_square(i, max(j - k, 1ll), i, j);
    sum -= grid[i][j];
//     2 case left right down

//    |||
//    ||
//    |

//    |||
//     ||
//      | 

// we can use prefix sum for this and 
// some special case is i + k > n || i - k < n, so you don't have to distract and plus row for some columns.
// the case up is same

    i = min(before.first + k, n);
    int cnt = 0;
    if(before.first + k > n) cnt = before.first + k - n;
    while(i > before.first && j <= n){
        sum += sum_square(before.first + 1, j, i, j);
        if(cnt > 0) cnt--;
        else i--;
        j++;
    }
    cnt = 0;

    i = min(before.first + k, n);
    j = before.second;
    if(before.first + k > n) cnt = before.first + k - n;

    while(i > before.first && j >= 1){
        sum += sum_square(before.first + 1, j, i, j);
        j--;
        if(cnt > 0) cnt--;
        else i--;
    }

    cnt = 0;
//     2 case left righ up
    i = max(before.first - k, 1ll);
    j = before.second;

    if(before.first - k < 1) cnt = 1 - (before.first - k);
    while(i < before.first && j <= n){
      //   sum += prefix_sum[before.first][j] - prefix_sum[i - 1][j];
            sum += sum_square(i, j, before.first - 1, j);
            if(cnt > 0) cnt--;
            else i++;
        j++;
    }
    cnt = 0;
    i  = max(before.first - k, 1ll);
    j = before.second;

    if(before.first - k < 1) cnt = 1 - (before.first - k);
    while(i < before.first && j >= 1){
      //   sum += prefix_sum[before.first][j] - prefix_sum[i - 1][j];  
            sum += sum_square(i, j, before.first - 1, j);
            j--;
            
            if(cnt > 0)cnt--;
            else i++;
    }

//     overlap 2 pieces

      i = min(before.first + k, n);
      j = before.second;
      sum -= sum_square(before.first + 1, j, i, j);

      i = max(before.first - k, 1ll);
      sum -= sum_square(i, j, before.first - 1, j);

      return sum;
}
void solve(){
    cin >> n >> k;

    foru(i, 1, n){
        foru(j, 1, n){
            cin >> grid[i][j];
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + grid[i][j];
        }
    }

    int ans = 0;
    foru(i, 1, n) {
        foru(j, 1, n){
            ans = max(ans, calculate(i, j)); 
            // cout << calculate(i, j) << " ";
        }
    }

    cout << ans << endl;
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