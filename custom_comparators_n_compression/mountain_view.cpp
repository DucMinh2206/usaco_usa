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

const string name_minh = "mountains";
const int maxN = 4e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
pair<int, int> arr[maxN];
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}
int ans[maxN];
void solve(){
    int n;
    cin >> n;

    foru(i, 1, n){
        int a, b;
        cin >> a >> b;
        arr[i] = mp(a, b);
    }
    sort(arr + 1, arr + n + 1, cmp);

    foru(i, 1, n){
        // This is the largest range of triangle cover
        pair<int, int> range = mp(arr[i].first - arr[i].second, arr[i].first + arr[i].second);

        // If you not add this line, you got TLE.
        // Because we only have right triangle (triangle that has eagle 90), so if the large triangle cover small triangle,
        // so all the space that is covered by small triangles are all covered by large triangle.
        if(ans[i]) continue;
        // hehe

        foru(j, i + 1, n){
            if(ans[i] != 0) continue;
            range.first += arr[j].second;
            range.second -= arr[j].second;

            // Here is the range that triangle ith cover on row arr[j].second
            if(arr[j].first <= range.second && arr[j].first >= range.first){
                ans[j] = 1;
            }

            range.first -= arr[j].second;
            range.second += arr[j].second;
        }
    }

    int sum = 0;
    foru(i, 1, n){
        if(!ans[i]) sum++;
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
    
    while(t--) {
        solve();
    }
}
