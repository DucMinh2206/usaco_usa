//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define ld long double

const int maxN = 5e4 + 5;
const long long inf = 1e17;
#define int long long
int coins[3], dp[maxN], W;

signed main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    cin >> coins[1] >> coins[2] >> W;

    foru(i, 0, W){
        foru(j, 1, 2){
            if(i >= coins[j]) dp[i] = max(dp[i - coins[j]] + coins[j], dp[i]);
        } 
    }
    cout << dp[W];

}
