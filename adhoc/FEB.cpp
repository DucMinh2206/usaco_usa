// #pragma GCC optimize("Ofast")
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
const string name_minh = "hoofball";
#define int long long
const int maxN = 2e5 + 5;
const int mod = 998244353;
const long long inf = 1e17;
string s;
queue<string> current;
int used[maxN];
set<int> ans;
void check_str(string t){
    int sz = t.size();
    int cnt = 0;
    for(int i = 0; i < sz - 1; ++i){
        if(t[i] == t[i + 1]) cnt++;
    }
    if(used[cnt]) return;

    ans.insert(cnt);
}

signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    current.push("");
    int cnt = 1;
    foru(i, 1, n){
        if(s[i] != 'F'){
            while(cnt > 0){
                string x = current.front();
                current.push(x + s[i]);
               // cout << x + s[i] << "  " << x << endl;
                current.pop();
                cnt--;
            }
        }
        else{
            while(cnt > 0){
                string x = current.front();
                current.push(x + 'B');
                current.push(x + 'E');
              //  cout << x + 'B' << " " << x + 'E' << " " << i << endl;
                current.pop();
                cnt--;
            }
        }

        cnt = current.size();
    }
    while(cnt > 0){
        string cur = current.front();
        check_str(cur);
        current.pop();
        cnt--;
    }
    cout << ans.size() << endl;
    for(int x: ans) cout << x << endl;
  

} 