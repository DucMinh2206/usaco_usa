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
int n, arr[maxN], k;

signed main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;

    foru(i, 1, n) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int ans = 0;

    foru(i, 1, n){
        foru(j, i, n){
            if(arr[j] - arr[i] <= k){
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans;

}
