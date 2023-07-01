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
const string name_minh = "herding";
#define int long long
const int maxN = 1e3 + 5;
const int mod = 998244353;
const long long inf = 1e17;
int arr[maxN];
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif
    foru(i, 1, 3) cin >> arr[i];
    sort(arr + 1, arr + 3);

    if(arr[1] + 1 == arr[2] && arr[1] + 2 == arr[3]){
        cout << 0 << endl;
        cout << 0;
        return 0;
    }
    else{
        int dis_one = arr[2] - arr[1], dis_two = arr[3] - arr[2], min_ans, max_ans;
        if(dis_one == 2 || dis_two == 2){
            min_ans = 1;
        }
        else min_ans = 2;

        max_ans = max(dis_one - 1, dis_two - 1);

        cout << min_ans << endl;
        cout << max_ans << endl;
    }
}
