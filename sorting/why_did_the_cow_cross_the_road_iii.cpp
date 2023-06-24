
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
const string name_minh = "cowqueue";
const int maxN = 1e3 + 5;
const int mod = 1000000007;
const long long inf = 1e17;
int n;
pair<int, int> num[maxN];
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;

    return a.first < b.first;
}

signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif

    cin >> n;
    foru(i, 1, n){
        cin >> num[i].first >> num[i].second;
    }
    sort(num + 1, num + 1 + n, cmp);

    int timee = 0;

    foru(i, 1, n){
        if(timee <= num[i].first){
            timee = num[i].first;
        }
        timee += num[i].second;
    }

    cout << timee;
}
