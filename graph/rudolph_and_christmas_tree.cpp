
// #define MINHDEPTRAI 1
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

const string name_minh = "planting";
const int maxN = 2e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;

int arr[maxN];
void solve(){
    ld n, d, h;
    cin >> n >> d >> h;

    foru(i, 1, n){
        cin >> arr[i];
    }
    ld sum = (ld)(n * d * h) / 2;

    foru(i, 2, n){
        if(arr[i] - arr[i - 1] < h){
            ld diff = arr[i] - arr[i - 1];
            ld h_inter = h - diff;
            ld d_inter = d - diff * (ld)(d / h);
            sum -= (ld)(h_inter * d_inter) / 2;
        }
    }

    cout << fixed << setprecision(7) << sum << endl;
}
signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    // freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}