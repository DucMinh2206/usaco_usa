

#ifdef MINH
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#else 
#include <bits/stdc++.h>
#endif

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 1000 + 5;
const long long inf = 1e17;
int pos[2][30], cnt[30];

signed main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s;
    cin >> s;
    s = " " + s;
    for(int j = 1; j < (int) s.size(); j++){
        if(pos[0][s[j] - 'A' + 1] == 0){
            pos[0][s[j] - 'A' + 1] = j;
        }
        else pos[1][s[j] - 'A' + 1] = j;
    }
    int ans = 0;
    foru(i, 1, 26){
        if(pos[0][i] == pos[1][i] + 1) continue;

        foru(j, pos[0][i] + 1, pos[1][i] - 1){
            if(pos[0][s[j] - 'A' + 1] == j && pos[1][s[j] - 'A' + 1] > pos[1][i]){
                ans++;
            }
        }
    }

    cout << ans;
}
