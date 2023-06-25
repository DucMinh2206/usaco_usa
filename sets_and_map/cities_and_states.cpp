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
const string name_minh = "citystate";
const int maxN = 1e6 + 500;
const int mod = 1000003;
const long long inf = 1e17;

map<string, map<string, int>> cities;
set<pair<string, string>> couple;
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif


    int n;
    cin >> n;

    foru(i, 1, n){
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        //cout << a << " " << b << endl;
        if(a == b) continue;
        cities[a][b]++;
        couple.insert(mp(a, b));
    }
    int ans = 0;
    for(pair<string, string> coup : couple){
        ans += cities[coup.first][coup.second] * cities[coup.second][coup.first];
    }
    ans /= 2;
    cout << ans;
}
