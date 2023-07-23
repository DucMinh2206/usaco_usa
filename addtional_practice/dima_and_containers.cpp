
// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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

const string name_minh = "input";
const int maxN = 1e5 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;

int n;
vector<string> ans;
vector<pii> num;
string addd[maxN];
vector<string> str_add = {"pushStack", "pushQueue", "pushFront", "pushBack"};
vector<string> str_pop = {"popStack", "popQueue", "popFront"};


void printf_str(int val){
    sort(num.begin(), num.end(), greater<pii>());
    vector<string> ans;
    int beggin = inf, endd = -inf;

    for(int i = 0; i <= (int)num.size() - 1; i++){

        pair<int, int> x = num[i];
        if(i <= 2){
            addd[x.second] = str_add[i];
            ans.push_back(str_pop[i]);
        }
        else addd[x.second] = str_add[3];

        beggin = min(beggin, x.second);
        endd = max(endd, x.second);
    }

    //cout << beggin << " " << endd << endl;
    foru(j, beggin, endd){
        cout << addd[j] << endl;
    }
    if(val != 0){
        cout << ans.size() ;
        for(string x: ans) cout << " " << x;
        cout << endl;
    }

    ans.clear();
    num.clear();
}
void solve(){
    cin >> n;

    
    foru(i, 1, n){
        int val;
        cin >> val;


        if(val != 0){
            num.push_back(mp(val, i));
        }
        else{
            printf_str(1);
        }
    }

    if(!num.empty()) {
        printf_str(0);
    }

}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".txt").c_str(), "r", stdin);
    //  freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif

    solve();

  
}