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

const string name_minh = "pairup";
const int maxN = 2e5 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

pair<int, int> arr[maxN];
void solve(){
    int n;
    cin >> n; 

    foru(i, 1, n) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr + 1, arr + n + 1);
  
    int l = 1, r = n, sum = 0, ans = 0; 

    while(l <= r){ 
        ans = max(ans, arr[l].first + arr[r].first);
        int min_val = min(arr[l].second, arr[r].second);
        arr[l].second -= min_val; 
        arr[r].second -= min_val;

        if(arr[l].second <= 0){
            l++;
        }
        if(arr[r].second <= 0){
            r--;
        }
        // cout << arr[l].second << " " << arr[r].second << " " << l << " " << r << endl;
        
    }
    cout << ans << endl;

    return;
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
    // freopen((name_minh + "3.txt").c_str(), "w", stdout);
    // #endif

    while(t--) {
        solve();
    }
}
