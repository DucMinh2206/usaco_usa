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
using ld = long double;

const string name_minh = "input";
const int maxN = 1e5 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

int num[maxN];

// I learned about this problem from marvinthang.
// Idea: If we split the array into at least 3 parts, such as
//  a4 a1 a2 a3 a4 a1
// then we must use at least one completely sum of all arrays.
// Therefore, intitially, if we need to use a complete sum => we update val, and after that we use two-pointer method 
//to solve shortest segment problem.
void solve(){
    int n, val, sum = 0;
    cin >> n >> val;

    foru(i, 1, n){
        cin >> num[i];
        sum += num[i];
        num[i + n] = num[i];
    } 
    int ans = val / sum * n, pos = 0, l = 1;

    val = val % sum;
    sum = 0;
    int curr = inf;
    foru(r, 1, n * 2){
        sum += num[r];
        while(sum - num[l] >= val && l <= r){
            sum -= num[l];
            l++;
        }

        if(sum >= val && r - l + 1 < curr){
            curr = r - l + 1;
            pos = (l - 1) % n + 1;
        } 
    }

    ans += curr;
    cout << pos << " " << ans << endl;
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
    // freopen((name_minh + "3.txt").c_str(), "w", stdout);
    // #endif

    while(t--) {
        solve();
    }
}
