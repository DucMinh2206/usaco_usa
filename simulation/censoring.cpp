//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include "bits/stdc++.h"
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j, a, b) for(int j = a; j >= b; --j)
#define mp make_pair
#define endl '\n'
#define ll long long
// #define int ll
const int maxN = 2005;
const int mod = 1e9 + 7;

signed main(){
    IOS
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    cin >> S;

    cin >> T;
    int pos = 0;
    while(true){
        size_t found = S.find(T, pos);

        if(found != string :: npos){
            S.erase(found, T.size());

            pos = found;
            if(pos - (int)T.size() >= 0){
                pos -= T.size();
            }
            else pos = 0;
        }
        else break;
    }

    cout << S << endl;
}
