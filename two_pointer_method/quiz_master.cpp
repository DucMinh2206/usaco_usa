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

const string name_minh = "input";
const int maxN = 5e5 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

// Cramer's rule: D = a1 * b2 - b1 * a2, Dx = c1 * b2 - b1 * c2, Dy = a1 * c2 - c1 * a2.
// Two-point formula: (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1);
// Distance from a line to a point: |ax0 + by0 + c| / sqrt(a^2 + b^2);
// Angle between two vectors: |a1 * a2 + b1 * b2| / (sqrt(a1^2 + b1^2) * sqrt(a2^2 + b2^2));
// Area of a polygon with n vertices: |x1 * y2 - x2 * y1 + x2 * y3 - y3 * x2 + ... + xn * y1 - x1 * yn| / 2 (integer);
// Coefficients of a straight line: x0, y0, n(a, b) => a(x - x0) + b(y - y0) = 0;


// My idea for this problem is to use factors to calculate the number of a[i] % T == 0.
// Then, I employ the two-pointer method.

// Time complexity is O(n * factor(small) + m(reset cnt));
int n, m;
int arr[maxN], cnt[maxN];
vector<int> factor[maxN];
void preprocess(){

    foru(i, 1, 1e5){
        for(int j = i; j <= 1e5; j+= i){
            factor[j].push_back(i);
        }
    }
}
void undo(int &i, int &sum){
    for(int &v: factor[i]){
        if(v > m) return;

        cnt[v]--;
        if(v <= m && cnt[v] == 0){
            sum--;
        }
    }
}
void ad(int &i, int &sum){
    for(int &v: factor[i]){
        if(v > m) return;
        
        cnt[v]++;
        if(v <= m && cnt[v] == 1) sum++;
    }
}
bool good(int &sum){
    return (sum == m);
}
void solve(){
    cin >> n >> m;
    foru(i, 1, m) cnt[i] = 0;

    foru(i, 1, n) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);

    int l = 1, sum = 0, ans = inf;
    foru(r, 1, n){
        ad(arr[r], sum);

        while(good(sum) && l < r){
            undo(arr[l], sum);
            l++;

            if(!good(sum)){
                l--;
                ad(arr[l], sum);
                break;
            }
        }
        // cout << arr[r] << " " << arr[l] << endl;
        if(good(sum)){
            ans = min(ans, arr[r] - arr[l]);
        }
    }

    if(ans == inf){
        cout << -1 << endl;
    }
    else cout << ans << endl;
}

signed  main() {
    IOS
    preprocess();
    int t;
    cin >> t;
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
