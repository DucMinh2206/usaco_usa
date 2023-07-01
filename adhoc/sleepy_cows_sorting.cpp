// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

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
#define endl '\n'
const string name_minh = "sleepy";
#define int long long
const int maxN = 1e2 + 5;
const int mod = 998244353;
const long long inf = 1e17;
int arr[maxN], pos[maxN];
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif
    
    int n;
    cin >> n;

    foru(i, 1, n){
        cin >> arr[i];
        pos[arr[i]] = i;
        //cout << arr[i] << " " << pos[arr[i]] << " " << i << endl; 
    }

    int ans = 0;
    foru(i, 1, n){
        foru(j, i + 1, n){
        //cout << pos[i] << " " << pos[i - 1] << endl;
            if(pos[j] < pos[i]){
                ans = max(ans, pos[j]);
            }
        }
    }
    cout << ans;
}
