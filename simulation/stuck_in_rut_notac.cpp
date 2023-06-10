#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
//#include <bits/stdc++.h>
using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define int long long
#define mp(a, b) make_pair(a, b)
#define endl '\n'

const int maxN = 55;
const int inf = 1e17;

vector<pair<pair<int, int>, int>> rt, down;
int ans[maxN];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.first == b.first.first) return a.first.second < b.first.second;

    return a.first.first < b.first.first;
}
void check_rt_down(int x1, int y1, int x2, int y2, int idx, int idx_two, int val){
    if(x1 == x2){
        if(y1 < y2){
             ans[idx] = min(ans[idx], y2 - y1);
        }
    }
    else if(x1 > x2 && x1 - x2 < y2 - y1 && ans[idx_two] >= x2 - x1 && ans[idx_two] != val){
        ans[idx] = min(ans[idx], y2 - y1);        
    }
}

void check_down_rt(int x1, int y1, int x2, int y2, int idx, int idx_two, int val){
    if(y1 > y2){
        if(x1 < x2 && x2 - x1 > y1 - y2 && ans[idx_two] >= y1 - y2 && ans[idx_two] != val){
            ans[idx] = min(ans[idx], x2 - x1);

            //cout << x1 << "  " << y1 << " KILL BY RIGHT ONE " << x2 << " " << y2 << " " << ans[idx_two] << endl;  
        }
    }
    else if(y1 == y2){
        if(x1 < x2 ){
            ans[idx] = min(ans[idx], x2 - x1);

            //cout << x1 << "  " << y1 << " KILL BY RIGHT TWO " << x2 << " " << y2 << endl; 
        }
    }
   

}
signed main(){
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int n;
    cin >> n;

    foru(i, 1, n){
        char a;
        int b, c;
        cin >> a >> b >> c;

        if(a == 'N'){
            rt.push_back(mp(mp(b, c), i));
        }
        else if(a == 'E'){
            down.push_back(mp(mp(b, c), i));
        }
    }

    sort(rt.begin(), rt.end(), cmp);
    sort(down.begin(), down.end(), cmp);
    
    foru(i, 1, n) ans[i] = inf;

    for(int i = 0; i + 1 < (int) rt.size(); i++){
        if(rt[i].first.first == rt[i + 1].first.first){
            ans[rt[i].second] = min(ans[rt[i].second], rt[i + 1].first.second - rt[i].first.second); 
        }
    }

    for(int i = 0; i + 1 < (int) down.size(); i++){
        if(down[i].first.second == down[i + 1].first.second){
            ans[down[i].second] = min(ans[down[i].second], down[i + 1].first.first - down[i].first.first); 
        }
    }



    for(int i = 0; i < (int)rt.size(); i++){
        for(int j = 0; j < (int)down.size(); j++){
            pair<pair<int, int>, int> rg = rt[i], dn = down[j];

            check_rt_down(rg.first.first, rg.first.second, dn.first.first, dn.first.second, rg.second, dn.second, inf);
        }
    }

    for(int i = 0; i < (int)rt.size(); i++){
        for(int j = 0; j < (int)down.size(); j++){
            pair<pair<int, int>, int> rg = rt[i], dn = down[j];

             check_down_rt(dn.first.first, dn.first.second, rg.first.first, rg.first.second, dn.second, rg.second, inf);
        }
    }


    for(int i = 0; i < (int)rt.size(); i++){
        for(int j = 0; j < (int)down.size(); j++){
            pair<pair<int, int>, int> rg = rt[i], dn = down[j];

            check_rt_down(rg.first.first, rg.first.second, dn.first.first, dn.first.second, rg.second, dn.second, -1);
        }
    }

    for(int i = 0; i < (int)rt.size(); i++){
        for(int j = 0; j < (int)down.size(); j++){
            pair<pair<int, int>, int> rg = rt[i], dn = down[j];

             check_down_rt(dn.first.first, dn.first.second, rg.first.first, rg.first.second, dn.second, rg.second, -1);
        }
    }


    foru(i, 1, n){
        if(ans[i] == inf){
            cout << "Infinity" << endl;
        }
        else cout << ans[i] << endl;
    }
    return 0;
}
