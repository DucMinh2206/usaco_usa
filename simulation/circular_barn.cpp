//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include "bits/stdc++.h"
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j, a, b) for(int j = a; j >= b; --j)
#define mp make_pair
#define endl '\n'
#define ll long long
// #define int ll
const int maxN = 105;
const int mod = 1e9 + 7;
int arr[maxN], n;

signed main(){
    IOS
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> n;

    foru(j, 1, n){
        cin >> arr[j];
    }
    int ans = mod;
    foru(i, 1, n){
        int sum = 0;
        foru(j, 1, n){
            if(i == j)continue;
            if(i < j){
                sum += (j - i) * arr[j];
            }
            else sum += (n - i + j) * arr[j];
        }
        ans = min(ans, sum);
    }
    cout << ans;
    
}
