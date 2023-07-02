// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#define MINHDEPTRAI 1
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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long 
const string name_minh = "citystate";
const int maxN = 1e3 + 500;
const int mod = 1000003;
const long long inf = 1e17;
int n, m;
int grid[maxN][maxN], prefix_sum[maxN][maxN];
struct rectangle{
    int x, y, x_max, y_max;
};
vector<rectangle> storing;
bool check_black(int x1, int y1, int x2, int y2){
    int val = prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] - prefix_sum[x1 - 1][y2] + prefix_sum[x1 - 1][y1 - 1];

    if(val == (x2 - x1 + 1) * (y2 - y1 + 1)){
        storing.push_back({x1, y1, x2, y2});
        return true;
    }
    return false;
}

bool check_nice(int x1, int y1, int x2, int y2){
    int pre_x1 = x1, pre_y1 = y1, pre_x2 = x2, pre_y2 = y2;

    // giam

    ford(i, x1 - 1, 1){
        if(!check_black(i, y1, x2, y2)){
            return true;
        }
    }

    ford(i, y1 - 1, 1){
        if(!check_black(x1, i, x2, y2)) return true;
    }

    for(int x = 1; x1 - x >= 1 && y1 - x >= 1; ++x){
        if(!check_black(x1 - x, y1 - x, x2, y2)) return true;
    }
    foru(i, x2 + 1, n){
        if(!check_black(x1, y1, i, y2)) return true;
    }
    foru(i, y2 + 1, m){
        if(!check_black(x1, y1, x2, i)) return true;
    }
    for(int x = 1; x1 + x <= n && y1 + x <= m; ++x){
        if(!check_black(x1, y1, x2 + x, y2 + x)) return true;
    }
    return false;
}
signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // ifstream cin("input.txt");
    // ofstream cout("output1.txt");
    // #endif
    int T;
    cin >> T;

    while(T--){
        cin >> n >> m;

        foru(i, 1, n){
            foru(j, 1, m){
                char x;
                cin >> x;
                 grid[i][j] = x - '0';
            }
        }

        foru(i, 1, n){
            foru(j, 1, m){
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + grid[i][j];
             //   cout << prefix_sum[i][j] << " ";
            }
            // cout << endl;
        }
        
        foru(i, 1, n){
            foru(j, 1, m){
                set<int> check;
                for(int x = 0; x + i <= n && x + j <= m; ++x){
                    if(check_black(i, j, x + i, x + j)){
                        cout << i << " " << j << " " << x << endl; 
                        check.insert(x);
                    }
                }

                for(int row = 1; row + i <= n; row++){
                    if(check.find(row) != check.end()) continue;
                    check_black(i, j, i + row, j); 
                }
                for(int column = 1; column + j <= m; column++){
                    if(check.find(column) != check.end()) continue;
                    check_black(i, j, i, j + column);
                }

            }
        }
        vector<rectangle> ans;
        for(int i = 0; i < storing.size(); i++){
            int x1 = storing[i].x;
            int y1 = storing[i].y;
            int x2 = storing[i].x_max;
            int y2 = storing[i].y_max;

            if(check_nice(x1, y1, x2, y2)) ans.push_back({x1, y1, x2, y2});
        }

        // for(rectangle some : ans){
        //     cout << some.x << " " << some.y << " " << some.x_max << " " << some.y_max << endl;
        // }
    }
   
}