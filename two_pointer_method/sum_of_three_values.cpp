// #define MINHDEPTRAI "Volumes/icebear/source_code/VS_code"
#ifdef MINHDEPTRAI


#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
using namespace std::chrono;
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
#define fi first
#define se second 
using ld = long double;

const string name_minh = "diamond";
const int maxN = 5e4 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

// Crammer D a1 b2, Dx c1 b2, Dy a1 c2.
// Two point x1 y1 x2 y2 x - x1 / x2 - x1 = y - y1 / y2 - y1;
// distance from line to point |ax0 + by0 + c| / sqrt(a ^ 2 + b ^ 2);
// 2 vector angle -> |a1 * a2 + b1 * b2| / sqrt(a1 * a1 + b1 * b1) + sqrt(a2 * a2 + b2 * b2);
// area of poligon n vertexs: |x1 * y2 - x2 * y1 + x2 * y3 - y3 * x2 + ...+ xn * y1 - x1 * yn| / 2 (full integer)
// coeffiencients of straight line: x0 y0 n(a, b) => a(x - x0) + b(y - y0) = 0;


pii arr[maxN];
// This problem is similar to the 'sum of two values' problem when we fix the third element.

void solve(){
    int n, x;
    cin >> n >> x;

    foru(i, 1, n){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + 1 + n);
    foru(i, 1, n){

        int val = x - arr[i].first;

        int l = 1, r = n, sum;
        while(l < r){
            sum = arr[l].first + arr[r].first;

            if(l != i && r != i && sum == val){
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second;
                return;
            }

            if(sum < val){
                l++;
            }
            else r--;
        }
    }

    cout << "IMPOSSIBLE" << endl; 
}

signed  main() {
    IOS
    int t = 1;
    // #ifndef MINHDEPTRAI
    // freopen((name_minh + ".in").c_str(), "r", stdin );
    // freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif

    // #ifdef MINHDEPTRAI
    // freopen((name_minh + ".txt").c_str(), "r", stdin );
    // freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif

    while(t--) {
        solve();
    }
}
