
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
#define IOS ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)
#define endl '\n'

const int maxN = 100  + 5;
const long long inf = 1e9;

vector<pair<int, int>> human[maxN];
set<int> cnt[maxN];
multiset<int> bad_milk;
bool drinked[maxN][maxN];

signed main(){
    IOS
    // freopen("badmilk.in", "r", stdin);
    // freopen("badmilk.out", "w", stdout);

    // input
    int n, m, s, d;
    cin >> n >> m >> d >> s;
    foru(j, 1, d){
        int a, b, c;
        cin >> a >> b >> c;

        human[a].push_back(mp(b, c));
        cnt[b].insert(a);
    }
    foru(i, 1, s){
        int a, b;
        cin >> a >> b;

        for(int j = 0; j < human[a].size(); j++){
            if(human[a][j].second < b && !drinked[a][human[a][j].first]){
                bad_milk.insert(human[a][j].first);
                drinked[a][human[a][j].first] = true;

            }
        }
    }
  


    int ans = 0;
    foru(i, 1, m){
        if(bad_milk.count(i) == s){
            ans = max(ans, (int)cnt[i].size());
        }
    }
    cout << ans;



    // end
    #ifdef MINHDEPTRAI
    auto start =  high_resolution_clock::now();
    #endif
    // running
    

    return 0;
    // end_running.
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << exacution.count() << "ms";
    #endif
}
