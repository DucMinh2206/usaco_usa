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

const string name_minh = "citystate";
const int maxN = 2e3 + 500;
const int mod = 1000003;
const long long inf = 1e17;

int arr[maxN], n, k;
unordered_set<int> b, ans, check;
void calculate(int pos, int vl){
    int cnt = 0, pre_val = vl, fi_val;
    check.insert(vl);

    ford(i, pos - 1, 0){
        vl -= arr[i + 1];
        if(i == 0) break;
        // Check if vl is in some elements that we need (b) and not duplicated with some values that we had.
        if(b.find(vl) != b.end() && check.find(vl) == check.end()) cnt++;

        check.insert(vl);
    }
    fi_val = vl;
    vl = pre_val;

    foru(i, pos + 1, n){
        vl += arr[i];
        if(b.find(vl) != b.end() && check.find(vl) == check.end()) cnt++;
        check.insert(vl);
    }
   
    if(cnt >= k - 1) ans.insert(fi_val);
    check.clear();

    return;
}
int val;
signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // ifstream cin("input.txt");
    // ofstream cout("output1.txt");
    // #endif
    cin >> n >> k;

    foru(i, 1, n){
        cin >> arr[i];
    }

    foru(i, 1, k){    
        cin >> val;
        b.insert(val);
    }

    foru(i, 1, n){
        calculate(i, val);         
    }
    cout << ans.size();
}
