// FIND (the number of) individual cows who can claim victory, (the number of) two-cow teams that could claim victory..
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
const int maxN = 100;
const int mod = 1e9 + 7;
char grid[maxN][maxN];
set<char> check[10];
set<char> one;
set<int> duo;
void plus_ans(set<char> a){
    int sz = a.size();
    if(sz == 1){
       for(char x: a){
          one.insert(x);
       }
    }

    if(sz == 2){
        int ss = 0;
        for(char x: a){
            ss += int(x);
        }
        duo.insert(ss);
    }
}

signed main(){
    IOS
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

   foru(i, 1, 3){
      foru(j, 1, 3){
        cin >> grid[i][j];
      }
   }
   
   foru(j, 1, 3){
       foru(i, 1, 3){
         check[j].insert(grid[i][j]);
       }
   }

   foru(i, 1, 3){
        foru(j, 1, 3){
            check[i + 3].insert(grid[i][j]);
        }
   }
   
   // 2 duong cheo
   int x = 1, y = 1;
   while(x <= 3 && y <= 3){
        check[7].insert(grid[x][y]);
        x++;
        y++;
   }

   x = 1, y = 3;
   while(x <= 3 && y >= 1){
        check[8].insert(grid[x][y]);
        x++;
        y--;
   }

   foru(j, 1, 8) plus_ans(check[j]);


   cout << one.size() << endl;
   cout << duo.size();
}
