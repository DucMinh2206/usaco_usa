
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

const string name_minh = "outofplace";
const int maxN = 3e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> num, sorted_num;
void solve(){
    int n;
    cin >> n;
    foru(i, 1, n){
        int val;
        cin >> val;
        num.push_back(val);
    }
    sorted_num = num;
    sort(sorted_num.begin(), sorted_num.end());

    int cnt = 0;
    foru(i, 0, n - 1){
        if(sorted_num[i] != num[i]) cnt++;
    } 
    int ans = (cnt > 0) ? cnt - 1 : cnt;
    cout << ans << endl;
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}