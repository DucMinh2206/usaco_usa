//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>
using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define int long long
#define mp(a, b) make_pair(a, b)
#define endl '\n'

const int maxN = 55;
const int inf = 1e17;

signed main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int length = (min(x4, x2) - max(x3, x1));
    int width = (min(y4, y2) - max(y3, y1));
    if(x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1){
        cout << (x2 - x1) * (y2 - y1);
    }
    else{
        // in the middle
        if((y4 < y2 && x3 > y1) || (x4 < x2 && x3 > x1)){
            cout << (x2 - x1) * (y2 - y1);
        }
        else{
            if(y3 <= y1 && y2 <= y4){
              // Condition: FULL HORIZONTAL
                if(x2 >= x3 && x3 >= x1 && x4 >= x2){
                    cout <<  (x2 - x1) * (y2 - y1) - length * width;
                }
                else if(x4 >= x1 && x4 <= x2 && x3 <= x1){
                    cout <<  (x2 - x1) * (y2 - y1) - length * width;
                }
                else  cout <<  (x2 - x1) * (y2 - y1);
            }
            else if(x3 <= x1 && x2 <= x4){
              // Condition: FULL VERTICAL
                if(y1 <= y3 && y3 <= y2 && y4 >= y2){
                    cout <<  (x2 - x1) * (y2 - y1) - length * width;
                }
                else if(y1 <= y4 && y4 <= y2 && y3 <= y1){
                    cout <<  (x2 - x1) * (y2 - y1) - length * width ;
                }
                else cout <<  (x2 - x1) * (y2 - y1);
            }
            else cout <<  (x2 - x1) * (y2 - y1);
        }
    }
}
