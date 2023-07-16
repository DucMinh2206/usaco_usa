
// #define MINHDEPTRAI 1
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
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'

const string name_minh = "lineup";
const int maxN = 1e5 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
vector<string> changed;
map<string, int> cows;
map<int, string> number;
vector<int> g[maxN];
bool visited[maxN];

void preprocess(){
    changed.push_back("Beatrice");
    changed.push_back("Bessie");
    changed.push_back("Sue");
    changed.push_back("Belinda");
    changed.push_back("Betsy");
    changed.push_back("Blue");
    changed.push_back("Buttercup");
    changed.push_back("Bella");
    sort(changed.begin(), changed.end());
    int cnt = 0;
    for(string x: changed){
        cnt++;
        cows[x] = cnt;
        number[cnt] = x;
        // cout << x << " " << cnt << endl;
    }
}


void solve(){
    preprocess();
    int n;
    cin >> n;

    foru(i, 1, n){
        string trash, cow1, cow2;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
        // cout << cows[cow1] << " " << cows[cow2] << endl;
        g[cows[cow1]].push_back(cows[cow2]);
        g[cows[cow2]].push_back(cows[cow1]);
    }
    vector<string> ans;

    foru(i, 1, 7){
        if(!visited[i] && g[i].size() <= 1){
            ans.push_back(number[i]);
            visited[i] = true;
            if(g[i].size() >= 1){
                int current = g[i][0], pre = i, curr_now;
                while(g[current].size() == 2){
                    int a = g[current][0];
                    int b = g[current][1];


                    curr_now = (a == pre) ? b : a;

                    ans.push_back(number[current]);
                    visited[current] = true;

                    pre = current;
                    current = curr_now;
                }


                ans.push_back(number[current]);
                visited[current] = true;
            }

        }
    }

    for(string x: ans){
        cout << x << endl;
    }
}

signed  main() {
    IOS
    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}