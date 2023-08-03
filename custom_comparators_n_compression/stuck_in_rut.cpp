// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
#ifdef MINHDEPTRAI


#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
using namespace std::chrono;
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
using ld = long double;

const string name_minh = "input";
const int maxN = 1e4 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
vector<pii> east, north;
vector<pair< pair<int, int>, pair<int, int> > > meet;
map<pii, int> pos;
pii current[maxN];

int value[maxN], counting[maxN], par[maxN];

// this problem have a idea that is very same to bronze version with idea is 
// we can see all x and y is different, so only N is stopped by E and otherwise.
// so we can caculate all the stopped, and sort by their time.
// after that we traverse all the stopped and see if it can happen and update answer.

void solve(){
    int n;
    cin >> n;
    foru(i, 1, n){
        char a;
        int b, c;
        cin >> a >> b >> c;
        if(a == 'E') east.push_back(mp(b, c));
        else if(a == 'N') north.push_back(mp(b, c));
        pos[mp(b, c)] = i;
        par[i] = i;
    }

    for(pair<int, int> nth: north){
        for(pair<int, int> est: east){

            int diff_x = nth.first - est.first;
            int diff_y = est.second - nth.second;

            if(diff_x == diff_y){
                continue;
            }
            else if(diff_x < diff_y && diff_x > 0){
                meet.push_back(mp( mp(diff_y,  diff_x),  mp(pos[nth], pos[est])) );
            }
            else if(diff_y < diff_x && diff_y > 0){
                meet.push_back(mp(mp(diff_x, diff_y), mp(pos[est], pos[nth])));
            }
        }
    }

    sort(meet.begin(), meet.end());

    for(auto x: meet){
        int val = x.first.first;
        int idx_one = x.second.first;
        int idx_two = x.second.second;
        if(!value[idx_one] && !value[idx_two]){
            value[idx_one] = val;
            par[idx_one] = par[idx_two];
        }
        else if(!value[idx_one] && value[idx_two]){
            if(value[idx_two] >= x.first.second) {
                value[idx_one] = val; 
                par[idx_one] = idx_two;
            }
        }
    }

    foru(i, 1, n){

        if(i == par[i]) continue;

        int x = i;
        while(x != par[x]){
            counting[par[x]]++;
            x = par[x];
        }
    }
    foru(i, 1, n){
     
        cout << counting[i] << endl;
    }
}

signed  main() {
    IOS
    int t = 1;
    // #ifdef MINHDEPTRAI
    // freopen((name_minh + ".txt").c_str(), "r", stdin );
    // freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif
    
    while(t--) {
        solve();
    }
}
