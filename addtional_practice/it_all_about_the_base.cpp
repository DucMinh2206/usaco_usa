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
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
using ld = long double;

const string name_minh = "whatbase";
const int maxN = 2e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
map<int, int> number, before;
void solve(){
    int a, b;
    cin >> a >> b; 
    number = before;
    string c = to_string(a), d = to_string(b);

    foru(i, 10, 20000){
        int val = 0;

        foru(j, 0, 2){
            val += (c[j] - '0') * pow(i, (2 - j));
        }
        number[val] = i;
    }

    foru(i, 10, 15000){
        int val = 0;

        foru(j, 0, 2){
            val += (d[j] - '0') * pow(i, (2 - j));
        }

        if(number.count(val) == 1){
            cout << number[val] << " " << i << endl;
            return;
        }
    }
}
signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}