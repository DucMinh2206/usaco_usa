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
const int maxN = 100;
const int mod = 1e9 + 7;
int apear_one[maxN], apear_two[maxN], n, cnt[maxN];

signed main(){
    IOS
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    cin >> n;

    foru(i, 1, n){
        string one, two;
        cin >> one;
        cin >> two;

        for(char x: one){
            apear_one[x - 'a' + 1]++;
        }
        for(char y: two){
            apear_two[y - 'a' + 1]++;
        }

        foru(j, 1, 26){
           
            cnt[j] += max(apear_one[j], apear_two[j]);
            
            apear_one[j] = apear_two[j] = 0;
        }
    }

    foru(j, 1, 26){
        cout << cnt[j] << endl;
    }
    
}
