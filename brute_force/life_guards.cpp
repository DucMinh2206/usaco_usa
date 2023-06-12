//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 1000 + 5;
const long long inf = 1e17;
pair<int, int> shift[maxN];
int cnt[maxN];
set<int> diff;

signed main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    foru(i, 1, n){
        cin >> shift[i].first >> shift[i].second;
        shift[i].second--;

        foru(k, shift[i].first, shift[i].second){
            cnt[k]++;
            diff.insert(k);
        }
    }    
    int before_ans = diff.size(), ans = 0, current_ans;

    foru(i, 1, n){
        int start = shift[i].first;
        int endding = shift[i].second;

        current_ans = before_ans;

        foru(k, start, endding){
            if(cnt[k] == 1) current_ans--;
        }
        ans = max(current_ans, ans);
    }
    cout << ans << endl;
}
