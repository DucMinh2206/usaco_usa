
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
#define int long long
const string name_minh = "whereami";
const int maxN = 1e3 + 5;
const int mod = 1000000007;
const long long inf = 1e17;
char arr[maxN];
set<string> ans[maxN];
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif
    int n;
    cin >> n;
    string ss;
    cin >> ss;
    ss = " " + ss;
    foru(i, 1, n){
        for(int j = 0; j + i <= n; j++){
            //cout << ss.substr(i, j + 1) << " " << i << " " << j << endl;
            ans[j + 1].insert(ss.substr(i, j + 1));
        }
    }

    // foru(i, 1, n){
    //     for(string x: ans[i]){
    //         cout << x << " " << i << endl;
    //     }
    // }

    foru(i, 1, n){
        if(ans[i].size() == n - i + 1){
            cout << i;
            return 0; 
        }
    }
}
