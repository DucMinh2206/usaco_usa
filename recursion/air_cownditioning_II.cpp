
#ifdef MINHDEPTRAI
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <chrono>
#define __gcd(a, b) gcd(a, b)
using namespace std ::chrono;
#else 
#include <bits/stdc++.h>
#endif

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define IOS ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'

#define ll long long 
const int maxN = 20 + 5;
const int mod = 1e6 + 7;
const long long inf = 1e17;
int n, m, s[maxN], t[maxN], c[maxN];
int a[maxN], b[maxN], number, p[maxN], money[maxN];
ll temp[105];
bool used[maxN];

ll sum = inf;
void back_tracking(int cnt, ll moo){
    if(cnt == 0 || moo >= sum){
        sum = min(sum, moo);
        return;
    }

    foru(i, 1, m){
        if(!used[i]){
            
            foru(j, a[i], b[i]){
                if(temp[j] == inf) continue;
                if(temp[j] > 0){
                    if(p[i] >= temp[j]) cnt--;
                }
                temp[j] -= p[i];
            }

            moo += money[i];
            used[i] = true;
            back_tracking(cnt, moo);

            used[i] = false;
            moo -= money[i];
            foru(j, a[i], b[i]){
                if(temp[j] == inf) continue;

                if(temp[j] <= 0){
                    if(temp[j] + p[i] > 0) cnt++;
                }
                temp[j] += p[i];
            }

        }
    }

}
signed main(){
    //   freopen("input.txt", "r", stdin);
    //   freopen("output1.txt", "w", stdout);
    // input
    IOS
    cin >> n >> m;
    fill(temp, temp + 105, inf);

    foru(i, 1, n){
        cin >> s[i] >> t[i] >> c[i];
        number += t[i] - s[i] + 1;

        foru(j, s[i], t[i]){
            temp[j] = c[i];
        }
    }

    foru(i, 1, m){
        cin >> a[i] >> b[i] >> p[i] >> money[i];
    }

    back_tracking(number, 0);
    cout << sum;
}
