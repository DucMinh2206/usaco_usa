// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const string name_minh = "art";
#define int long long
const int maxN = 1e2 + 5;
const int mod = 998244353;
const long long inf = 1e17;
char fake[maxN][maxN];
int grid[maxN][maxN];
bool exist[maxN];
int n;
int max_x[10], max_y[10], min_x[10], min_y[10], ans[maxN];

signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif
    cin >> n;

    foru(i, 1, n){
        foru(j, 1, n){
            cin >> fake[i][j];
            grid[i][j] = fake[i][j] - '0';
        }
    }

    foru(i, 1, 9){
        max_x[i] = max_y[i] = 0;
        min_x[i] = min_y[i] = inf;
        //cout << max_x[i] << " " << max_y[i] << endl;
    }

    foru(i, 1, n){
        foru(j, 1, n){
            int cell = grid[i][j];
            if(cell == 0) continue;
            max_x[cell] = max(i, max_x[cell]);
            max_y[cell] = max(j, max_y[cell]);
            min_x[cell] = min(i, min_x[cell]);
            min_y[cell] = min(j, min_y[cell]);
            exist[grid[i][j]] = true;
        }
    }
    
    foru(k, 1, 9){
        if(exist[k]) ans[k] = 1;
    }

    foru(k, 1, 9){
        if(exist[k]){
            foru(i, min_x[k], max_x[k]){
                foru(j, min_y[k], max_y[k]){

                    if(grid[i][j] != k){
                        ans[grid[i][j]] = -1;
                    }

                }
            }

        }
    }


    int sum = 0;
    foru(i, 1, 9){
        sum += (ans[i] == 1);
    }

    cout << sum;

} 