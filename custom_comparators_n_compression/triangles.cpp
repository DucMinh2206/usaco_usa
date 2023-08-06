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

const string name_minh = "triangles";
const int maxN = 2e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
map<int, vector<int>> x, y;
map<int, vector<int>> prefix_sum_x, prefix_sum_y;
pii num[maxN];

// NEWWWWWW.
// when you want to sort an vector in a map, you have to use & when traverse.
// because if you do not use that, it create a copy and you work on it instead of working on actual container.
// -----

// my original idea is 
// if you see on coordinate of 3 points of triangles, for example
// 1 4 
// 1 2
// 3 2
// there is always one point that have x = other, y = other (but it is different from point that have x equal) (1)
// so I came up with the idea that I want to store vector[x], vector[y] that all points have coordinate x or y.
// so I traverse all from 1 -> n, I just try if it is the exactly point what I am looking for and using some maths(1) .

// Details (math).
// for example your point that consider is (1, 2), and there is some points in vector_x[1], vector_y[2];
// when you have |a - 1| * |x - 2| + |b - 1| * |x - 2| +  |b - 1| * |y - 2| + | a - 1| * |y - 2|
// first I write it shorter like (| a - 1| + |b - 1|) * (|x - 2| + |y - 2| )
// each () we can calculate in O(1) using prefix_sum.

// for instance, if we want calculate |a - 1| (a < 1), we can calculate by |1 - a| 
// (a >= 1) we can calculate directly.
// so we can sort vector and some numbers in left (< 1 (for example)) |1 * the number of integers < 1 - sum|
// and for some numbers > 1 |sum - 1 * the number of intergers|

void solve(){
    int n;
    cin >> n;

    foru(i, 1, n){
        cin >> num[i].first >> num[i].second;
         x[num[i].first].push_back(num[i].second);
        y[num[i].second].push_back(num[i].first);
    }

    for(auto &it: x){
        int val = 0;
        sort(x[it.first].begin(), x[it.first].end());
        for(int v: it.second){
            val += v;
            prefix_sum_x[it.first].push_back(val);
        }
    }
    

    for(auto &it: y){
        int val = 0;
        sort(y[it.first].begin(), y[it.first].end());

        for(int v: it.second){
            val += v;
            prefix_sum_y[it.first].push_back(val);
        }
    }

    int sum = 0;
    foru(i, 1, n){
        int a = x[num[i].first].size(), b = y[num[i].second].size(), val = 0, val_two = 0;

        if(a <= 1 || b <= 1) continue;

        // for x
        auto it = lower_bound(x[num[i].first].begin(), x[num[i].first].end(), num[i].second);
        int idx = it - x[num[i].first].begin();
        if(idx >= 1){
            val = (idx * num[i].second - prefix_sum_x[num[i].first][idx - 1] ) ;
        }
        if(idx < a - 1){
            val += (prefix_sum_x[num[i].first][a - 1] - prefix_sum_x[num[i].first][idx]) - (num[i].second * (a - idx - 1));
        }

        // for y
        it = lower_bound(y[num[i].second].begin(), y[num[i].second].end(), num[i].first);
        idx = it - y[num[i].second].begin();
        if(idx >= 1){
            val_two = idx * num[i].first - prefix_sum_y[num[i].second][idx - 1];
        }
        if(idx < b - 1){
            val_two += (prefix_sum_y[num[i].second][b - 1] - prefix_sum_y[num[i].second][idx]) - (num[i].first * (b - idx - 1));
        }

        // add answer 
        val = abs(val) % mod;
        val_two = abs(val_two) % mod;

        val = (val * val_two) % mod;
        sum = (sum + val) % mod;
    }

    cout << sum << endl;
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
