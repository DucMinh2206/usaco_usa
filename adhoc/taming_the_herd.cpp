// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// special case: with 0 -1 -1 -1 4 (-1 is in the middle of two non-negative numbers).
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
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'
const string name_minh = "taming";
#define int long long
const int maxN = 1e3 + 5;
const int mod = 998244353;
const long long inf = 1e17;
int arr[maxN], st[maxN];
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
    }
    st[1] = 1;

    int nearest = 1;
    foru(i, 1, n){
        if(arr[i] == -1) continue;

        //cout << st[i - arr[i]] << " " << st[i] << endl;
        if(st[i - arr[i]] == -1 || i - arr[i] <= 0 || arr[i] > i - nearest){
            cout << -1;
            return 0;
        }

        st[i] = -1;
        st[i - arr[i]] = 1;
        for(int fill = (int)arr[i] - 1; fill >= 0; fill--){
            st[i - fill] = -1;
        }

        nearest = i - arr[i];
    }

    int serious = 0, no_se = 0;
    foru(i, 1, n){
        if(st[i] == -1) continue;

        if(st[i] == 1) serious++;
        else if(st[i] == 0) no_se++;
    }

    cout << serious << " " << serious + no_se << endl;
}
