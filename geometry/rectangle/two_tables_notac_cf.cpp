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

 int W, H, w, h, x1, y_1, x2, y2;
vector<pair<int, int>> special;

bool check_intersection(int x_one, int y_one, int x_two, int y_two, int x_three, int y_three, int x_four, int y_four){
    if(x_one >= x_four || x_two <= x_three || y_one >= y_four || y_two <= y_three ){
        return false;
    }
    else return true;
}
void solve(){
    cin >> W >> H;
    cin >> x1 >> y_1 >> x2 >> y2;
    cin >> w >> h;
    
    int x, y, x_two, y_two;
    long double ans = inf;

    special.clear();
    special.push_back(mp(0, 0));
    special.push_back(mp(W, 0));
    special.push_back(mp(0, H));
    special.push_back(mp(W, H));

    foru(i, 0, 3){
        int x3 = special[i].first, y3 = special[i].second, x4, y4;

        if(x3 == 0) x4 = x3 + w;

        else if(x3 == W) x4 = x3 - w;

        if(y3 == 0) y4 = y3 + h;

        else if(y3 == H) y4 = y3 - h;

        // cout << x3 << " check " << y3 << " " << x4 << " " << y4 << endl;
        x = min(x3, x4);
        y = min(y3, y4);
        x_two = max(x3, x4);
        y_two = max(y3, y4);

        if(!check_intersection(x1, y_1, x2, y2, x, y, x_two, y_two)){
            cout << fixed << setprecision(6) << ans << endl;
            return;
        }
        else{
            int remain_x, remain_y;

            if(x3 == 0 && y3 == 0){
                remain_x = W - x2;
                remain_y = H - y2;
            }

            if(x3 == W && y3 == H){
               remain_x = W - x1;
               remain_y = H - y_1;
            }

            if(x3 == 0 && y3 == H){
                remain_x = W - x2;
                remain_y = H - y_1;
            }

            if(x3 == W && y3 == 0){
                remain_x = W - x1;
                remain_y = H - y2;
            }


            ld x_inter = min(x2, x_two) - max(x1, x);
            ld y_inter = min(y2, y_two) - max(y_1, y);

            //  cout << x4 << " " << y4 << endl;
              //cout << ans << " " << remain_x << " " << remain_y << " " << x_inter << " " << y_inter << endl;
            if(remain_x > x_inter){
                ans = min(ans, x_inter);
            }
            if(remain_y >= y_inter){
                ans = min(ans, y_inter);
            }

        }
    }

    if(ans == inf){
        cout << -1 << endl;
    }
    else cout << fixed << setprecision(6) << ans << endl;
}
signed main(){
    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
