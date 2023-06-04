//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include "bits/stdc++.h"
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j, a, b) for(int j = a; j >= b; --j)
#define mp make_pair
#define endl '\n'
#define ll long long
// #define int ll
const int maxN = 2005;
const int mod = 1e9 + 7;
int grid[maxN][maxN], step[maxN], n, Time;
char direction[maxN]; 
set<int> ans;
int check(int x, int y){
    if(grid[x][y] >= 1){
       return Time - grid[x][y];
    }
    else return -1;
}
void process(int x, int y, int &vl){
    int val = check(x, y);
    if(check(x, y) >= 0) ans.insert(val);
    grid[x][y] = Time; 
    Time++, vl--;
}

int solve(){

    int x = 1001, y = 1001;

    foru(j, 1, n){
        int value = step[j];
       if(direction[j] == 'N'){
            while(value >= 1){
                x--;
                process(x, y, value);
            }
        }
        
        if(direction[j] == 'E'){
            while(value >= 1){
                y++;
                process(x, y, value);
            }
        }
        
        if(direction[j] == 'S'){
            while(value >= 1){
                x++;
                process(x, y, value);
            }
        }

        if(direction[j] == 'W'){
            while(value >= 1){
                y--;
                process(x, y, value);
            }
        }
        
    }
    if(ans.empty()) return -1;
    else return *ans.begin(); 
}
signed main(){
    IOS
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    cin >> n;
    foru(j, 1, n){
        cin >> direction[j] >> step[j];
    }
    cout << solve();
}
