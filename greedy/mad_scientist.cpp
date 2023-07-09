// #pragma GCC optimize("Ofast,unroll-loops")
// #define MINHDEPTRAI 1
#ifdef MINHDEPTRAI
 
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
#define __gcd(a, b) gcd(a, b)
using namespace std ::chrono;
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
 #define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
const string name_minh = "breedflip";
#define int long long
const int maxN = 1e3 + 5;
const int mod = 1;
char arr[maxN], b[maxN];
void solve(){
    int n;
    cin >> n;

    foru(i, 1, n){
        cin >> arr[i];
    }
    foru(i, 1, n) cin >> b[i];
    bool consecutive = false;
    int ans = 0;
    arr[0] = 'C';
    foru(i, 1, n){
        if(arr[i] != b[i]){
            if(!consecutive){
                ans++;
                consecutive = true;    
            }
        }
        else{
            consecutive = false;
        }
    }

    cout << ans;
}
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}