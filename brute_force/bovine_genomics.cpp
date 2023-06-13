
#ifdef MINHDEPTRAI
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <chrono>
using namespace std ::chrono;
#else 
#include <bits/stdc++.h>
#endif

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 100 + 5;
const long long inf = 1e17;
char normal[maxN][maxN], spoty[maxN][maxN];
signed main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    // input
    int n, m;
    cin >> n >> m;
    foru(i, 1, n){
        foru(j, 1, m){
            cin >> spoty[i][j];
        }
    }

    foru(i, 1, n){
        foru(j, 1, m){
            cin >> normal[i][j];
        }
    }

    // end
    #ifdef MINHDEPTRAI
    auto start =   high_resolution_clock::now();
    #endif
    // running
    int ans = 0;
    foru(i, 1, m){
        bool check = false;

        for(int j = 1; j <= n && !check; j++){
            for(int k = 1; k <= n && !check; k++){
                if(spoty[j][i] == normal[k][i]){
                    check = true;
                    break;
                }
            }
        }

        if(!check) ans++;
    }
    cout << ans << endl;


    // end
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() << "ms";
    #endif

}
