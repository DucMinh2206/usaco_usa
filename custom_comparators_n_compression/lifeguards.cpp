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

const string name_minh = "lifeguards";
const int maxN = 4e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;

int n;
vector<int> arr; 
int diff[maxN], prefix_sum[maxN], width[maxN], range[maxN], prefix_range[maxN];

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

      // diff: the change of the number of gruards each time, arrival++, leaving--
      foru(i, 1, n) { 
            diff[compress_idx(update[i].first) + 1]++;
            diff[compress_idx(update[i].second) + 1]--;
      }

      int x = arr.size() - 1;
      // for each time, guard covered arr[i] -> arr[i + 1] - 1
      foru(i, 0, x - 1){
            width[i + 1] = arr[i + 1] - arr[i];
      }

      // I calculate the the number of guards each time 
      foru(i, 1, x){
            prefix_sum[i] = diff[i] + prefix_sum[i - 1];
      }

      int sum = 0;

      // total time are covered by guard before updated.
      foru(i, 1, x){
            int vl = (prefix_sum[i] > 0) ? 1 : 0;
            sum += vl * width[i] ;
      }
      // We can see that when we fire one guard, the prefix_sum from range i -> j -= 1.
      // So we only care about the range which only have one guard, and we save the time for query.

      foru(i, 1, x){
            if(prefix_sum[i] == 1){
                  range[i] = width[i];
            }
      }
      // prefix_sum of range that have one guard for query
      foru(i, 1, x){
            prefix_range[i] = prefix_range[i - 1] + range[i];
      }

      int ans = 0;
      foru(i, 1, n){
            // total_guard - time that one_guard cover in that range.
            ans = max(ans, sum - (prefix_range[compress_idx(update[i].second)] - prefix_range[compress_idx(update[i].first)]) );
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
    
    while(t--) {
        solve();
    }
}
