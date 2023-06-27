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
const string name_minh = "3";
const int maxN = 5e5 + 5;
const int mod = 1e7 + 3;
const long long inf = 1e17;
const int base = 137;

int idx[maxN], group[maxN];
string s;
vector<pair<int, int>> arr;
signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    string a, b;
    cin >> a;
    b = a;
    s += a;
    s += "$";
    s += b;
    int n = s.size();
    foru(i, 0, n - 1){
        arr.push_back({s[i], i});
    }
    sort(arr.begin(), arr.end());

    foru(i, 0, n - 1) idx[i] = arr[i].second;
    group[idx[0]] = 0;

    foru(i, 1, n - 1){
        if(arr[i].first == arr[i - 1].first){
            group[idx[i]] = group[idx[i - 1]];
        }
        else group[idx[i]] = group[idx[i - 1]] + 1;
    }

    int k = 0;
    while((1 << k) < n){
        vector< pair< pair<int, int>, int>> arr_after;

        foru(i, 0, n - 1) arr_after.push_back(mp(mp(group[i], group[i + (1 << k) % n]), i));
        sort(arr_after.begin(), arr_after.end());
        foru(i, 0, n - 1) idx[i] = arr_after[i].second;

        group[idx[0]] = 0;

        foru(i, 1, n - 1){
            //cout << arr_after[i].first.first << " " << arr_after[i].first.second << " " << arr_after[i].second << " " << k << endl; 
            if(arr_after[i].first.first == arr_after[i - 1].first.first){
                if(arr_after[i].first.second != arr_after[i - 1].first.second) group[idx[i]] = group[idx[i - 1]] + 1;
                else group[idx[i]] = group[idx[i - 1]];
            }
            else group[idx[i]] = group[idx[i - 1]] + 1;
        }

        k++;  
    }
    int ans = 0, current = 0;
    int sz = a.size();
     foru(i, 1, n - 1){
        if(idx[i] == n - 1) continue;
        
        if((idx[i] <= sz - 1 && idx[i - 1] >= sz + 1) || (idx[i] >= sz + 1 && idx[i - 1] <= sz - 1)){
            string c = s.substr(idx[i], n - idx[i]);
            string d = s.substr(idx[i - 1], n - idx[i - 1]);

            if(c.size() > d.size()) swap(c, d);
            current = 0;
            //cout << c << " " << d << endl;
            for(int k = 0; k < c.size(); k++){
                if(c[k] == d[k]) current++;
                else break;
            }
            // cout << c << " " << d << endl;
            // cout << current << " " << idx[i] << " " << idx[i - 1] << endl;
            ans = max(ans, current);
        }
     }
     cout << ans;
    
       
}
// O(m + n + min(m + n) + (m + n) * log2(m + n). 
