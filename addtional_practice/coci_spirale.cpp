// my mistake is wrong limit huhu

// and, Because I do the problem by consider some ranges like +1 -1 +2 -2 +3 -3, so I have to compare value to get the earliest value.

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
using ld = long double;

const string name_minh = "input";
const int maxN = 50 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
pair<int, int> current[maxK], previous[maxK]; // val | n = 0, m = 1 
int loai[maxK];
int grid[maxN][maxN];
int n, m, k;
bool check(int x, int y, int timee){

    if(x == 1 && y == 3){
        //cout << " what fuck "<< grid[x][y] << endl;
    }

    if(x >= 1 && x <= n && y >= 1 && y <= m){
        if(grid[x][y] != 0){

            if(timee < grid[x][y]) grid[x][y] = timee;
            //cout << grid[x][y] << " co roi " << endl;
            return false;
        }
        else{
            // cout << x << " " << y << endl;
             return true;
        }
    }
     return false;
}

void solve(){
    cin >> n >> m >> k;
    foru(i, 1, n){
        foru(j, 1, m){
            grid[i][j] = 0;
            
        }
    }
    foru(i, 1, k){
        cin >> current[i].first >> current[i].second >> loai[i];
        previous[i] = mp(-1, 0);
    }

    int cnt = n * m;

    int step = 1, cnt_step = 0;

    foru(i, 1, k){
        cnt_step = 0;
        
        int pre = current[i].first;
        current[i].first += previous[i].first;
        // cout << i << endl;
        // cout << pre << " " << current[i].first << " " << current[i].second << endl;
        ford(j, pre, current[i].first){
            // cout << j << " check " << current[i].second << endl;
            if(check(j, current[i].second, step + cnt_step)){

                // if(j == 1 && current[i].second == 3){
                    // cout << i << " what fuck 2 " << step + cnt_step << endl;
                // }

                grid[j][current[i].second] = step + cnt_step;
                cnt--;
            }
            cnt_step++;
        }
       
    }

    step = 2;
    while(cnt > 0){
        int pre_step = step;

        foru(i, 1, k){
            step = pre_step, cnt_step = 0;

            pair<int, int> before = current[i];

            if(loai[i] == 0){
                if(previous[i].second == 0){
                    current[i].second = current[i].second - previous[i].first;
                    previous[i] = mp(-previous[i].first, 1);

                }
                else{
                    current[i].first += previous[i].first;

                    if(previous[i].first < 0) {
                        current[i].first --;
                        previous[i].first --;
                    }
                    else{
                        previous[i].first ++;
                        current[i].first ++;
                    }

                    previous[i] = mp(previous[i].first, 0); 
                } 
            }
            else{
                if(previous[i].second == 0){
                    current[i].second += previous[i].first;
                    previous[i] = mp(previous[i].first, 1);

                }
                else{
                    current[i].first += -previous[i].first;
                    
                    if(previous[i].first < 0) {
                        current[i].first++;
                        previous[i].first = -previous[i].first + 1;
                    }
                    else{
                         current[i].first--;
                         previous[i].first = -previous[i].first - 1;
                    }

                    previous[i] = mp(previous[i].first, 0);
                }

            }

            //cout << cnt << endl;
            //cout << current[i].first << " " << current[i].second << endl;
           // cout << step << " " << cnt_step << endl;

            if(previous[i].second == 0){
                if(previous[i].first < 0){
                    ford(j, before.first, current[i].first){
                       if(check(j, current[i].second, step + cnt_step)) {
                            grid[j][current[i].second] = step + cnt_step;                            
                            cnt--;
                       }

                       cnt_step++;
                    }
                }
                else{
                    foru(j, before.first, current[i].first){

                        //cout << j << " hehe " << current[i].second << " " << step << " " << cnt_step << endl;
                        if(check(j, current[i].second, step + cnt_step)){
                            grid[j][current[i].second] = step + cnt_step;
                            cnt--;
                        }
                        cnt_step++;
                    }

                }
            }
            else{
                if(previous[i].first < 0){
                    ford(j, before.second, current[i].second){
                       if(check(current[i].first, j, step + cnt_step)){ 
                            grid[current[i].first][j] = step + cnt_step;                            
                            cnt--;
                       }
                        cnt_step++;
                    }
                }

                else{
                    foru(j, before.second, current[i].second){
                        //cout << current[i].first << " hehe " << j << " " << step << " " << cnt_step << endl;
                       if(check(current[i].first, j, step + cnt_step)){ 
                            grid[current[i].first][j] = step + cnt_step;                            
                            cnt--;
                       }
                       
                        cnt_step++;
                    }

                }

            }
        
        }

        //cout << step << " step " << cnt_step << endl;
        step += cnt_step - 1;
    }
    
    foru(i, 1, n){
        foru(j, 1, m){
            cout << grid[i][j]; 
            if(j != m) cout << " ";
        }
       cout << endl;
    }


}

signed  main() {
    IOS

    #ifdef MINHDEPTRAI 
    freopen((name_minh + ".txt").c_str(), "r", stdin);
     freopen((name_minh + "2.txt").c_str(), "w", stdout);
    #endif
    solve();

  
}