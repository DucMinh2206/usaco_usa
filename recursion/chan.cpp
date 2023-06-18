#define MINHDEPTRAI 1
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
unordered_set<int> ans;
void back_tracking(int cnt, int sum){
    if(cnt == 4){
        ans.insert(sum);
        return;
    }

    if(cnt % 2 == 0){
        for(auto it = barn_one.begin(); it != barn_one.end();){
            int val = *it;
            cout << cnt << " one -> two " << val << endl;
            sum -= val;
            barn_two.insert(val);
            barn_one.erase(it);
            cnt++;
            back_tracking(cnt, sum);

            sum += val;
            barn_two.erase(barn_two.find(val));
            barn_one.insert(val);
            cnt--;
            sum += val;
        }
    }
    else{
        
         for(auto it_two = barn_two.begin(); it != barn_two.end();){
            int val_two = *it_two;
            cout << cnt << " two -> one " << val_two << endl;
            sum += val_two;
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
    //   freopen("lineup.in", "r", stdin);
    //   freopen("lineup.out", "w", stdout);
    // input
    IOS
   std::set<int> barn_one = {1, 2, 3, 4, 5};
    int sum = 0;

    //back_tracking(0, 1000);
    //cout << ans.size();

   
}
