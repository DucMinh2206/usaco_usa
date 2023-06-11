//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define ld long double

const int maxN = 55;
const ld inf = 1e17;
signed main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    int sum_one = 0, sum_two = 0;
    if(x4 <= x5 || x6 <= x3 || y4 <= y5 || y6 <= y3){
        sum_one = 0;
    }
    else{
        sum_one += (min(x4, x6) - max(x5, x3)) * (min(y4, y6) - max(y5, y3));
    }

    if(x2 <= x5 || x6 <= x1 || y2 <= y5 || y6 <= y1){
        sum_two = 0;
    }
    else{
        sum_two += (min(x2, x6) - max(x1, x5)) * (min(y2, y6) - max(y1, y5));
    }
    
    cout << ((x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3)) -  (sum_one + sum_two);


}
