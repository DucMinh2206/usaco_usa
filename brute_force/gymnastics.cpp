//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 1000 + 5;
const long long inf = 1e17;
int n, k, pos[100][100];
signed main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> k >> n;

    foru(i, 1, k){
        foru(j, 1, n){
            int val;
            cin >> val;
            pos[i][val] = j;
        }
    }

    int ans = 0;
    foru(i, 1, n){
        foru(j, i + 1, n){

            foru(t, 1, k){
                if(pos[t][i] > pos[t][j]){
                    break;
                }
               if(t == k) ans++;
            }
        }
    }

    foru(i, 1, n){
        foru(j, i + 1, n){

            foru(t, 1, k){
                if(pos[t][i] < pos[t][j]){
                    break;
                }
                if(t == k) ans++;
            }
        }
    }

    cout << ans;
}
