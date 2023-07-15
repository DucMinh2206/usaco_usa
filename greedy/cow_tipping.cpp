
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

const string name_minh = "cowtip";
const int maxN = 10 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
char grid[maxN][maxN];
void solve(){
    int n;
    cin >> n;
    int cnt_one = 0, cnt_zero = 0;
    pair<int, int> max_pos;
    foru(i, 1, n){
        foru(j, 1, n){
            cin >> grid[i][j];

            if(grid[i][j] == '1') {
                cnt_one++;
                max_pos = mp(i, j);
            }
            if(grid[i][j] == '0') cnt_zero++;
        }
    }
    int ans = 0; 
    pair<int, int> current;
    while(true){
        if(!cnt_one) break;

       foru(i, 1, max_pos.first){
            foru(j, 1, max_pos.second){
                if(grid[i][j] == '1'){
                    cnt_zero++;
                    cnt_one--;
                    grid[i][j] = '0';
                }
                else{
                    cnt_one++;
                    cnt_zero--;
                    grid[i][j] = '1';
                }
            }
        }
        bool check = false;
        ford(i, n, 1){
            if(check) break;
            ford(j, n, 1){
                if(grid[i][j] == '1'){
                    current = mp(i, j);
                    check = true;
                    break;
                }
            }
        }
        max_pos = current;

        ans++;
    }

    cout << ans;
    return;
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}
