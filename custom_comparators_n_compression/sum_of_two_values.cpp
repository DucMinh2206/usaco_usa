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

const string name_minh = "IMPOSSIBLE";
const int maxN = 2e5 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

int num[maxN];
map<int, vector<int>> pos;
// we can sort the array and then calculate the sum of two values by two pointer, if sum > val and sum < val

// my mistake is l and r is different and two numbers not segment.
void solve(){
    int n, val;
    cin >> n >> val;

    foru(i , 1, n){
        cin >> num[i];
        pos[num[i]].push_back(i);
    }

    sort(num + 1, num + n + 1);
    int l = 1, r = n, sum = 0;

    while(l < r) {
        sum = num[l] + num[r];

        if(sum > val){
            sum -= num[r--];
            sum += num[r];
        }

        if(sum < val){
            sum -= num[l++];
            sum += num[l];
        }
        if(sum == val && l != r){
            if(num[l] == num[r]){
                cout << pos[num[l]][0] << " " << pos[num[l]][1] << endl;
            }
            else cout << pos[num[l]][0] << " " << pos[num[r]][0] << endl;

            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return;
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
