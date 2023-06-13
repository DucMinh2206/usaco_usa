

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
map<string, int> cnt; 
int val[maxN];
string ss[maxN][maxN];
signed main(){
    // freopen("guess.in", "r", stdin);
    // freopen("guess.out", "w", stdout);
    // input
    int n;
    cin >> n;
    foru(i, 1, n){
        string s;
        cin >> s;

        cin >> val[i];
        foru(j, 1, val[i]){
            cin >> ss[i][j];
            cnt[ss[i][j]]++;
        }
    }
    // end
    #ifdef MINHDEPTRAI
    auto start =   high_resolution_clock::now();
    #endif
    // running

    int ans = 0;
    foru(i, 1, n){
        foru(j, i + 1, n){
            map<string, int> s;
            int current = 0;

            foru(k, 1, val[i]){
                s[ss[i][k]]++;
            }   
            
            foru(p, 1, val[j]){
                s[ss[j][p]]++;

                if(s[ss[j][p]] == 2) current++;
            }
            
            ans = max(current + 1, ans);
        }
        
    }
    cout << ans;

    // end
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() << "ms";
    #endif

}
// An answer could calculated by the most common of elements of pairs + 1 (because no animals is same).
// Because the common elements of several elements for example like 3 can transform to the common elements of two pairs.
// For example like 1 2 3 we can ask until it has only characteristics of one elements or common of two elements so we can answer the question.
