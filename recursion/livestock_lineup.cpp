#ifdef MINHDEPTRAI
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <chrono>
#define __gcd(a, b) gcd(a, b)
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

#define ll long long 
const int maxN = 20 + 5;
const int mod = 1e6 + 7;
const long long inf = 1e17;
vector<string> g[maxN];
string cows[9] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, int> change;
bool used[maxN];
bool check_ans(vector<string> current){

    for(int j = 0; j < current.size(); j++){
        int number = change[current[j]];
        if(g[number].size() == 0) continue;

        if(j == 0 || j == 7){
            if(g[number].size() > 1){
                return false;
            }
            if(j == 0) if(current[j + 1] != g[number][0]) return false;
            if(j == 7) if(current[j - 1] != g[number][0]) return false;
        }
        else{
            if(g[number].size() > 2) return false;

            int cnt = 0;
            for(int i = 0; i < g[number].size(); i++){
                if(g[number][i] == current[j + 1] || g[number][i] == current[j - 1]){
                    cnt++;
                }
            }
            if(cnt != g[number].size()) return false;
        }
    }
    return true;
}
bool check = false;
vector<string> ans_cp, now;
void back_tracking(vector<string> ans){
    if(check) return;

    if(ans.size() == 8){

        if(check_ans(ans)){
            ans_cp = ans;
            check = true;
        }
        return;
    }

    foru(j, 0, 7){
        if(!used[j]){
            ans.push_back(cows[j]);
            used[j] = true;
            back_tracking(ans);

            used[j] = false;
            ans.pop_back();
        }
    }
}
signed main(){
      freopen("lineup.in", "r", stdin);
      freopen("lineup.out", "w", stdout);
    // input
    IOS
    int n;
    cin >> n;
    int cnt = 0;
    sort(cows, cows + 7);
    foru(i, 0, 7) change[cows[i]] = i + 1;

    foru(i, 1, n){
        string ss[5];

        string a, b;
        cin >> a;
        foru(i, 1, 4) cin >> ss[i];
        cin >> b;
        g[change[a]].push_back(b);
        g[change[b]].push_back(a);
    }
    
     back_tracking(now);
    foru(i, 0, ans_cp.size() - 1) cout << ans_cp[i] << endl;
    return 0;
}
