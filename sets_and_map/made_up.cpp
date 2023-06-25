// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
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
#define int long long 
const string name_minh = "citystate";
const int maxN = 1e5 + 500;
const int mod = 1000003;
const long long inf = 1e17;


int b[maxN], a[maxN], c[maxN];
map<int, int> cnt_fi, cnt_se;
signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // ifstream cin("input.txt");
    // ofstream cout("output1.txt");
    // #endif

    int n;
    cin >> n;

    foru(i, 1, n){
        cin >> a[i];
        cnt_fi[a[i]]++;
    } 
    foru(i, 1, n){
        cin >> b[i];
    }
    foru(i, 1, n){
        cin >> c[i];
        cnt_se[b[c[i]]]++;
    }

    map<int, int> :: iterator it;
    int sum = 0;
    for(it = cnt_fi.begin(); it != cnt_fi.end(); it++){
        sum += it -> second * cnt_se[it -> first];
    }
    cout << sum;
}
