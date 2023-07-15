
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

const string name_minh = "race";
const int maxN = 1e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int x[1005];

void solve(){
    int n, q;
    cin >> n >> q;

    foru(i, 1, q) {
        cin >> x[i];
    }

    foru(i, 1, q){
        int pre_ans = inf, current, back_up, current_ans = 0;
        foru(j, 1, n){
            current = j * (j + 1) / 2;

            if(j <= x[i]){
                current_ans = j + (n - current) / j + (((n - current) % j != 0));
            }
            else{
                int sp_down = (j * (j - 1)) / 2 - (x[i] * (x[i] - 1)) / 2;
                int remain = n - current - sp_down; 
                // cout << remain << " main " << j << " " << x[i] << endl;
                if(remain < 0){
                    break;
                }
                else{
                     //cout << j << " main " << remain << endl;
                    current_ans = j + (remain / j) + ((remain % j != 0)) + j - x[i];
                }
            }

            // cout << current_ans << " " << j << endl;
            if(current_ans > pre_ans) break;

            pre_ans = current_ans;
        }

        cout << pre_ans << endl;
    }
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}
