
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
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'

const string name_minh = "race";
const int maxN = 1e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
string str;
void solve(){
    int n, max_pos = 0;
    cin >> n;
    cin >> str;

    str = " " + str;
    foru(i, 1, n){ 
        if(str[i] == 'H' && i % 2 == 0){ 
            max_pos = i;
        }
    }

    int current = -1, ans = 0;
    while(max_pos >= 2){
        if(str[1] == 'G'){
            reverse(str.begin() + 1, str.begin() + 1 + max_pos);
            ans++;
        }
        //     reverse(str.begin() + 1, str.begin() + max_pos + 2);
        //     ans++;
        // }
         cout << str << " " << max_pos << " " << ans << endl;
        max_pos -= 2;
        ford(i, max_pos, 1){
            if(str[i] == 'H' && i % 2 == 0){
               current = i;
               break; 
            }
        }
        max_pos = current;
        current = -1;
    }
    cout << str << endl;
    int cnt = 0;
    foru(i, 1, n){
        if(i % 2 == 0 && str[i] == 'G') cnt++;
    }
    cout << cnt << " " << ans << endl;
}

signed  main() {
    IOS
    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".in").c_str(), "r", stdin);
    // freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif
    solve();
}