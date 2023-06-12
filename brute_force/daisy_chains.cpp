//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define ld long double

const int maxN = 100 + 5;
const long long inf = 1e17;
#define ld long double
int n;
ld arr[maxN];
signed main(){
    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);
    cin >> n;

    foru(i, 1, n) cin >> arr[i];
    int ans = 0;
    foru(i, 1, n){
        ld sum = arr[i];
        foru(j, i + 1, n){
            sum += arr[j];
            ld val = sum / (j - i + 1);

            foru(k, i, j){
                if(val == arr[k]){
                    ans++;
                    break;
                }   
            }

        }
    }
    cout << ans + n;

}
