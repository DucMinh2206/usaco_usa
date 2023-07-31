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

const string name_minh = "rental";
const int maxN = 4e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;

int n, m, r, cow[maxN], rent[maxN], prefix_milk[maxN], prefix_money[maxN];
pii milk[maxN];
vector<int> prefix_sum;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return (a.second > b.second);
    else return a.first > b.first;
}

// for this problem because each cow for rent is same, so we want to keep the cow that produce as milk as possible.
// I use prefix_sum for the number of tons of milk for upperbound, the other cow I rent.
void solve() {
    cin >> n >> m >> r;
    foru(i, 1, n){
            cin >> cow[i];
    }
    sort(cow + 1, cow + 1 + n, greater<int>());
    foru(i, 1, n) prefix_milk[i] = prefix_milk[i - 1] + cow[i];

    foru(i, 1, m){
        int a, b;
        cin >> a >> b;
        milk[i] = mp(b, a);
    }
    sort(milk + 1, milk + m + 1, cmp);

    foru(i, 1, r){
        cin >> rent[i];
    }
    sort(rent + 1, rent + 1 + r, greater<int>());
    foru(i ,1, r) rent[i] += rent[i - 1];

    int sum = 0;
    prefix_sum.push_back(-1);

    foru(i, 1, m){
        sum += milk[i].second;
        prefix_money[i] = milk[i].second * milk[i].first + prefix_money[i - 1];
        prefix_sum.push_back(sum);
    }
   

    int val = min(n, r), ans = 0;
    sum = 0; 
    foru(i, 0, val){
        sum = 0;
        sum += rent[i];
        auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), prefix_milk[n - i]);

        if(it == prefix_sum.end()) {
            sum += prefix_money[m];
        }
        else{
            int idx = it - prefix_sum.begin();
            sum += prefix_money[idx - 1] + (prefix_milk[n - i] - prefix_sum[idx - 1]) * milk[idx].first;
        }

        ans = max(ans, sum);
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
