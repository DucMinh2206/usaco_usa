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
const string name_minh = "milkorder";
#define int long long
const int maxN = 1e3 + 5;
const int mod = 998244353;
const long long inf = 1e17;
int n, m, k;
int order[maxN], ans[maxN], pos[maxN];
bool check_status(){
    int o_idx = 1;
    for(int i = 1; i <= n && o_idx <= m; i++){
        //cout << i << endl;
        //cout << i << " " << pos[order[o_idx]] << " " << o_idx << " " << order[o_idx] << endl;
        if(pos[order[o_idx]] != -1){

            if(i > pos[order[o_idx]]) return false;

            i = pos[order[o_idx]];
            o_idx++;
        }
        else{
            while(ans[i] != -1 && i <= n){
                i++;
                //cout << i << endl;
            }
            if(i > n) return false;
            //cout << i << " run to " << endl;
            o_idx++;
        }
    }
    return true;
}

signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif

    
    cin >> n >> m >> k;
    foru(i, 1, n){
        ans[i] = -1;
        pos[i] = -1;
    }

    foru(i, 1, m) cin >> order[i];

    foru(i, 1, k){
        int a, b;
        cin >> a >> b;
        ans[b] = a;
        pos[a] = b;

        if(a == 1){
            cout << b;
            return 0;
        }
    }


    foru(i, 1, n){
        if(ans[i] == -1){
            //cout << i << " consider " << endl;
            ans[i] = 1;
            pos[1] = i;

            if(check_status()){
                cout << i;
                return 0;
            }

            ans[i] = -1;
            pos[1] = -1;
        }
    }
   
}
