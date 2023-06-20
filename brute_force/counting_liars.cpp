
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

#define int long long
const int maxN = 1000 + 5;
const int mod = 998244353;
const long long inf = 1e17;
pair<int, char> cows[maxN];
int prefix_low[maxN], prefix_up[maxN];
signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);
    // input
    IOS
    int n;
    cin >> n;

    foru(i, 1, n){
        cin >> cows[i].second >> cows[i].first;
    }
    sort(cows + 1 , cows + 1 + n);

    foru(i, 2, n){
        prefix_low[i] += prefix_low[i - 1];
        if(cows[i - 1].second == 'L' && cows[i - 1].first < cows[i].first){
            prefix_low[i]++;
        }
    }
    ford(i, n - 1, 1){
        prefix_up[i] += prefix_up [i + 1];
        if(cows[i + 1].second == 'G' && cows[i + 1].first > cows[i].first){
            prefix_up[i]++;
        }
    }
    
    int ans = inf;
    foru(i, 1, n){
        ans = min(ans, prefix_up[i] + prefix_low[i]);
    }
    cout << ans;
}
