
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
const int maxN = 100 + 5;
const int mod = 1e6 + 7;
const long long inf = 1e17;
int cnt[maxN];
multiset<int> barn_one, barn_two;
multiset<int> :: iterator it, it_two;
set<int> ans;
void back_tracking(int cnt, int sum){
     //cout << cnt << " " << sum << endl;
    if(cnt == 4){
        ans.insert(sum);
        return;
    }

    if(cnt % 2 == 0){
        vector<int> values(barn_one.begin(), barn_one.end());
        for(int val : values){
            //cout << cnt << " one -> two " << val << " " << barn_one.size()<< endl;
            sum -= val;
            barn_two.insert(val);
            barn_one.erase(barn_one.find(val));
            cnt++;
             back_tracking(cnt, sum);

            sum += val;
            barn_two.erase(barn_two.find(val));
            barn_one.insert(val);
            cnt--;
        }
    }
    else{
        vector<int> values(barn_two.begin(), barn_two.end());
        for(int val_two : values){
            sum += val_two;

            //cout << cnt << " two -> one " << val_two << " " << barn_two.size()<< endl;
            barn_one.insert(val_two);
            barn_two.erase(barn_two.find(val_two));
            cnt++;
            back_tracking(cnt, sum);

            sum -= val_two;
            barn_two.insert(val_two);
            barn_one.erase(barn_one.find(val_two));
            cnt--;
        }
    
    }
}
signed main(){
      freopen("backforth.in", "r", stdin);
      freopen("backforth.out", "w", stdout);
    // input
    IOS
    foru(i, 1, 10){
        int val;
        cin >> val;
        cnt[val]++;
        if(cnt[val] <= 2) barn_one.insert(val);
    }
    fill(cnt, cnt + maxN, 0);
    foru(i, 1, 10){
        int val;
        cin >> val;
        cnt[val]++;
        if(cnt[val] <= 2) barn_two.insert(val);
    }
    
    back_tracking(0, 1000);
    cout << ans.size();

   
}
