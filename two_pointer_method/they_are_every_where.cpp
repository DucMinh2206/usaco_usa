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

// Algorithm Explanation:
// The 'leftmost' array stores the maximum number of diamonds we can store if the leftmost index is 'l'.
// The 'maxleft' array stores the maximum number of diamonds we can store if we consider the leftmost index to be 'l'
// (it doesn't necessarily mean we have to use the leftmost index 'l', we can use the leftmost index l + 1, l + 2, ...).
// For each index 'i' from 1 to 'n', we compute 'leftmost[i]' plus the remaining part that the leftmost index doesn't cover.

int leftmost[maxN], maxleft[maxN], arr[maxN];
void solve(){
    int n, k;
    cin >> n >> k;

    foru(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int r = 1;
    foru(l, 1, n){

        while(arr[r] - arr[l] <= k && r <= n){
            r++;
        }
        leftmost[l] = r - l;
    }
    ford(i, n, 1){
        maxleft[i] = max(leftmost[i], maxleft[i + 1]);
    }
    int ans = 0;
    foru(i, 1, n){
        int val = leftmost[i] + maxleft[leftmost[i] + i];
        ans = max(val, ans);
    }
    cout << ans << endl;

}

signed  main() {
    IOS
    int t = 1;
    #ifndef MINHDEPTRAI
    freopen((name_minh + ".in").c_str(), "r", stdin );
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif

    // #ifdef MINHDEPTRAI
    // freopen((name_minh + ".txt").c_str(), "r", stdin );
    // freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif

    while(t--) {
        solve();
    }
}
