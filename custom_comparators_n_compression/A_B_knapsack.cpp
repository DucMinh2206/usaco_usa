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
const int maxN = 3e5 + 5;
const int maxK =  1e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int arr[maxN], b[maxN], n, m, s, A, B;
//My idea is very simple:
//When you choose an element with weight A, your goal is to select as many coins as possible.
//Therefore, I sort the array. After that, I iterate from 0 to n. If we choose i items with weight A, the remaining items can be calculated using the prefix sum.

//There is a special case when the remaining items > n; in this case, we have to choose all of them.
void solve(){
    cin >> n >> m >> s >> A >> B;

    foru(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1, greater<int>());

    foru(i, 1, m){
        cin >> b[i];
    }
    sort(b + 1, b + m + 1, greater<int>());

    foru(i, 1, n) arr[i] = arr[i - 1] + arr[i];

    foru(i, 1, m) b[i] = b[i - 1] + b[i];

    int sum = 0, ans = 0;
   
    foru(i, 0, n){
        if(s < i * A) break;

        int remain = (s - i * A) / B;

        if(remain > m) remain = m;
        // cout << remain << " " << i << " " << arr[i] << " " << b[remain] << endl;
        ans = max(ans, arr[i] + b[remain]) ;
    }
    cout << ans << endl;
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
