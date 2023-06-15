
#ifdef MINHDEPTRAI
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <chrono>
using namespace std ::chrono;
#else 
#include <bits/stdc++.h>
#endif

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define IOS ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'

#define int long long
const int maxN = 10 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e17;
char grid[20][maxN][maxN], cp_grid[20][maxN][maxN];
int n, k, min_row[maxN], min_column[maxN], counting[maxN];
void find_min(){
    foru(i, 1, k){
        min_column[i] = n;
        min_row[i] = n;
    }
    // find min column
    foru(p, 1, k){
        foru(i, 1, n){
            foru(j, 1, n){
               if(grid[p][i][j] == '#'){
                    min_column[p] = i;
                     break;
               }
            }
        }
    }
    // find min row
     foru(p, 1, k){
        foru(i, 1, n){
            foru(j, 1, n){
                if(grid[p][j][i] == '#'){
                    min_column[p] = j;
                    break;
                }
            }
        }
    }
}

void shift_full_up(int idx){
    if(min_row[idx] == 1) return ;

    int diff = min_row[idx] - 1;

    foru(i, 1, n){
        foru(j, 1, n){
            int new_x = i + diff;

            if(new_x > n){
                grid[idx][i][j] = '.';
            }
            else grid[idx][i][j] = cp_grid[idx][new_x][j];
        }
    } 
}

void shift_full_left(int idx){
    if(min_column[idx] == 1) return ;

    int diff = min_column[idx] - 1;

    foru(i, 1, n){
        foru(j, 1, n){
            int new_y = j + diff;

            if(new_y > n){
                grid[idx][i][j] = '.';
            }
            else grid[idx][i][j] = cp_grid[idx][i][new_y];
        }
    } 
}

bool check(int a, int b){
    foru(i, 1, n){
        foru(j, 1, n){
            if(grid[0][i][j] == '.') continue;

            if((grid[a][i][j] == grid[0][i][j] || grid[b][i][j] == grid[0][i][j]) && (grid[a][i][j] != grid[b][i][j])){
                continue;
            }
            else return false;
        }
    }

    return true;
}

bool shift_right(int a){
    
    foru(i, 1, n){
        foru(j, 1, n){
            if(j == n && grid[a][i][j] == '#') return false;

            int y_before = j - 1;
            if(y_before < 1) grid[a][i][j] = '.';
            else grid[a][i][j] = cp_grid[a][i][y_before];
        }
    }
    return true;
}
bool shift_down(int a){
    
    foru(i, 1, n){
        foru(j, 1, n){
            if(i == n && grid[a][i][j] == '#') return false;

            int x_before = j - 1;
            if(x_before < 1) grid[a][i][j] = '.';
            else grid[a][x_before][j] = cp_grid[a][i][j];
        }
    }
    return true;
}

bool shift_left(int a){
    
    foru(i, 1, n){
        foru(j, 1, n){
            if(j == 1 && grid[a][i][j] == '#') return false;

            int y_before = j + 1;

            if(y_before > n) grid[a][i][j] = '.';
            else grid[a][i][j] = cp_grid[a][i][y_before];
        }
    }
    return true;
}
void check_ans(int a, int b){
    if(check(a, b)){
        cout << a << " " << b;
        exit(0);
    }
}

signed main(){
    //   freopen("ming.inp", "r", stdin);
    //   freopen("ming.out", "w", stdout);
    // input
    IOS
    cin >> n >> k;
    foru(p, 0, k){
        foru(i, 1, n){
            foru(j, 1, n){
                cin >> grid[p][i][j];
                cp_grid[p][i][j] = grid[p][i][j];

                if(grid[p][i][j] == '#') counting[p]++;
            }
        }
    }
    vector<pair<int, int>> consider;
    foru(i, 1, n){
        foru(j, i + 1, n){
            if(counting[i] + counting[j] == counting[0]){
                consider.push_back(mp(i, j));
            }
        }
    }

    for(int i = 0; i < (int) consider.size(); i++){
        int idx_fi = consider[i].first;
        int idx_se = consider[i].second;
        shift_full_left(idx_fi);
        shift_full_left(idx_se);
        shift_full_up(idx_fi);
        shift_full_up(idx_se);

        int cnt_one = 0, cnt_two = 0;
        bool check_one = false, check_two = false;
        while(true){
            while(true){   
                // shift left

                if(cnt_one % 2 == 0){
                    while(shift_left(idx_fi)){
                        check_ans(idx_fi, idx_se);
                    }
                    cnt_one++;
                }
                else{
                    while(shift_right(idx_fi)){
                        check_ans(idx_fi, idx_se);
                    }
                    cnt_one++;
                }
                if(!shift_down(idx_fi)){
                    
                }
            }

            check_ans(idx_fi, idx_se);

            if(cnt_one % 2 == 0){
                while(shift_left(idx_fi)){
                    check_ans(idx_fi, idx_se);
                }
                cnt_one++;
            }
            else{
                while(shift_right(idx_fi)){
                    check_ans(idx_fi, idx_se);
                }
                cnt_one++;
            }
            if(!shift_down(idx_fi)){
                break;
            }

        }

        
    }





    // end
    #ifdef MINHDEPTRAI
    auto start =  high_resolution_clock::now();
    #endif
    // running






    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << exacution.count() << "ms";
    #endif
}
