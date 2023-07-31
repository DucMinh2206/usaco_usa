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

const string name_minh = "art";
const int maxN = 4e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;

int n;
vector<int> arr; 
int diff[maxN];
int prefix_sum[maxN]; 

int compress_idx(int val) {

    return lower_bound(arr.begin(), arr.end(), val) - arr.begin();
}

pii update[maxN];

void solve() {
    cin >> n;
    foru(i, 1, n) {
        int a, b;
        cin >> a >> b;
        arr.push_back(a);
        arr.push_back(b);
        update[i] = mp(a, b);
    }

    sort(arr.begin(), arr.end()); 
    arr.erase((arr.begin(), arr.end()), arr.end()); 

    foru(i, 1, n) {
        // the diff function is related to the change of the customers in one time.
        // arrival ++ , leaving--
         
        diff[compress_idx(update[i].first) + 1]++;
        diff[compress_idx(update[i].second) + 1]--;
    }

    int ans = -inf;
    int x = arr.size() - 1;
    foru(i, 1, x) {
            // the prefix sum is actually the number of person in one point of time depend on diff array.
            // so the answer is the maximum of all prefix sum.

        prefix_sum[i] = prefix_sum[i - 1] + diff[i];
        ans = max(prefix_sum[i], ans);
      
    }
    cout << ans << endl; 
}

signed  main() {
    IOS
    int t = 1;
    while(t--) {
        solve();
    }
}
