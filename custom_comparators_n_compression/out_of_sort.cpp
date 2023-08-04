// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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

const string name_minh = "sort";
const int maxN = 2e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
vector<int> arr, num;
map<int, int> needed;
// you can see that if there is some numbers place in wrong number, it exists some number that is in higher position than in sorted array
// so we can calculate all of operations need to change that into correct position.
// because it has a higher position at now, so that position is for larger number.
// and because each step these number can move to left one 
//( some numbers that have lower position can move >= 1 to right), so that there is can be different move on each step of these numbers.
// so we only calculate the number that has higher position.

void solve(){
    int n;
    cin >> n;
    
    foru(i, 1, n){
        int val;
        cin >> val;
        arr.push_back(val);
    }
    num = arr;
    sort(arr.begin(), arr.end());

    foru(i, 0, (int) arr.size() - 1){
        needed[arr[i]] = i;
    }

    int ans = 0;
    foru(i, 0, (int) arr.size() - 1){
        if(arr[i] != num[i]){
            // cout << num[i] << " " << arr[i] << " " << needed[num[i]] << endl;
            if(i > needed[num[i]]){
                ans = max(ans, i - needed[num[i]]);
            }
        }
    }
    cout << ans + 1 << endl;
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI
    freopen((name_minh + ".in").c_str(), "r", stdin );
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
}
