
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
const int maxN = 3e5 + 5;
const int mod = 1000000007;
const long long inf = 1e17;

vector<int> number[maxN];

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        foru(j, 1, m) number[j].push_back(inf);

        foru(i, 1, n){
            foru(j, 1, m){
                int val;
                cin >> val;
               number[j].push_back(val); 
            }
        }

         if(n == 1){
            cout << 0 << endl;
            foru(i, 1, m) number[i].clear();
            continue;
        }
       

        foru(i, 1, m) sort(number[i].begin(), number[i].end(), greater<int>());

        // foru(i, 1, n){
        //     foru(j, 1, m){
        //         cout << number[j][i] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        foru(i, 1, m){
            int cnt = n - 1;
            foru(j, 1, n / 2){
                ans += number[i][j] * cnt - number[i][n - j + 1] * cnt;
                cnt -= 2;

                //cout << number[i][j] << " " << number[i][n - j + 1] << " " << i << endl;
            }
        }

        foru(i, 1, m) number[i].clear();
        cout << ans << endl;

    }
}
