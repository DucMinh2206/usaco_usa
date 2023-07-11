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
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
const string name_minh = "breedflip";
#define int long long
const int maxN = 1e5 + 5;
const int inf = 1e18;
void solve(){
    int n;
    cin >> n;

    int chan_sz = 0, le_sz = 0;
    foru(i, 1, n){
        int val;
        cin >> val;
        if(val % 2 == 0) chan_sz++; 
        else le_sz++; 
    }

    int ans = 0, check = true; 
    for(int i = 1; check == true; ++i){
       if(i % 2 == 1){
            if(chan_sz < 1  && le_sz < 2){
                if(chan_sz == 0 && le_sz == 0) cout << ans;
                else cout << ans - 1;

                break;
            }

            if(chan_sz >= 1) chan_sz--;
            else if(le_sz >= 2){
                le_sz -= 2;
            }

            ans++;
        }
        else{
            if(le_sz < 1){
                cout << ans;
                break;
            }

            le_sz --;
            ans++;
        }
    }
}
signed  main() {
    IOS
    // #ifdef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    solve();
}