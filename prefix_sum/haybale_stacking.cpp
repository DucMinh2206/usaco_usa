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

const string name_minh = "stacking";
const int maxN = 1e6 + 5;
const int maxK =  3e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;


int n, arr[maxN], diff_array[maxN], k;
void solve(){
   cin >> n >> k;
   foru(i, 1, k) {
        int a, b;
        cin >> a >> b;
        diff_array[a]++;
        diff_array[b + 1]--;
   }
   foru(i, 1, n){
        arr[i] = diff_array[i] + arr[i - 1];
   }
  
   sort(arr + 1, arr + n + 1);
   n = n / 2 + (n % 2 != 0);
   cout << arr[n];

}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    //  freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif
    int t = 1;
    while(t--){
        solve();
    }
  
}