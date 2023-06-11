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

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    if(x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3){
        return false;
    }
    else return true;
}
signed main(){
    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);
    int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    bool check_one = check(x1, y1, x2, y2, x3, y3, x4, y4);
    bool check_two = check(x1, y1, x2, y2, x5, y5, x6, y6);

    if(!check_one && !check_two){
        cout << "YES";
        return 0;
    }

    int required = ((x2 - x1) * (y2 - y1));
    if(check_one == false){
        int intersection  = (min(x2, x6) - max(x1, x5)) * (min(y2, y6) - max(y1, y5)); 
        
        if(intersection == required){
            cout << "NO";
            return 0;
        }
        else{
            cout << "YES";
            return 0;
        }
    }
    if(check_two == false){
        int intersection  = (min(x2, x4) - max(x1, x3)) * (min(y4, y2) - max(y1, y3)); 
        
        if(intersection == required){
            cout << "NO";
            return 0;
        }
        else{
            cout << "YES";
            return 0;
        }
    }

    if(check_two && check_one){
        int x1_inter, y1_inter, x2_inter, y2_inter, x3_inter, y3_inter, x4_inter, y4_inter;


        x1_inter = max(x1, x3);
        y1_inter = max(y1, y3);
        x2_inter = min(x2, x4);
        y2_inter = min(y2, y4);


        x3_inter = max(x1, x5);
        y3_inter = max(y1, y5);
        x4_inter = min(x2, x6);
        y4_inter = min(y2, y6);

        int val_one = (x2_inter - x1_inter) * (y2_inter - y1_inter);
        int val_two = (x4_inter - x3_inter) * (y4_inter - y3_inter);

        if(!check(x1_inter, y1_inter, x2_inter, y2_inter, x3_inter, y3_inter, x4_inter, y4_inter)){
            if(val_one + val_two == required){
                cout << "NO";
                return 0;
            }
            else{
                cout << "YES";
                return 0;
            }
        }
        else{
            int intersect = (min(x2_inter, x4_inter) - max(x1_inter, x3_inter)) * ((min(y2_inter, y4_inter) - max(y1_inter, y3_inter)));

            if(val_one + val_two - intersect == required){
                cout << "NO";
                return 0;
            }
            else{
                 cout << "YES";
                 return 0;
            }
        }
    }

    

}
