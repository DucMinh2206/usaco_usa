
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
const string name_minh = "4";
const int maxN = 1e6 + 500;
const int mod = 1000003;
const long long inf = 1e17;

unordered_set<int> cities[maxN];
set<int> pairs;
int hash_code(string a){
    return (a[0] - 'A' + 1) * 107 + (a[1] - 'A' + 1) * 103  ;
}
bool check = false;
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif

    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");

    int n, cnt = 0;
    cin >> n;

    foru(i, 1, n){
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        //cout << a << " " << b << endl;
        int change = hash_code(a), change_b = hash_code(b);
        
        if(a == b){
            continue;

        }

        cities[change].insert(change_b);
        pairs.insert(change);
    }

    for(int city: pairs){
        for(int val : cities[city]){
            
            if(cities[val].count(city)){
                //cout << val << " " << city << endl;
                cnt++;
            }
        }
    }

    cout << cnt / 2;
}
