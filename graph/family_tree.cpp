
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

const string name_minh = "family";
const int maxN = 600 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
map<string, int> number;
vector<int> g[maxN];
int par[maxN];
bool check, visited[maxN];
void dfs(int u, int pre){

    for(int v: g[u]) {
        if(v == pre) continue;

        if(v == 2){
            check = true;
        }
        //cout << u << " " << v << endl;
        dfs(v, u);
    }

}
void solve(){
    int n;
    string cow_one, cow_two;
    cin >> n >> cow_one >> cow_two;
    number[cow_one] = 1, number[cow_two] = 2;
    int cnt = 2;


    foru(i, 1, n){
        string a, b;
        cin >> a >> b;

        if(!number.count(a)){
            number[a] = ++cnt;
        }
        if(!number.count(b)){
            number[b] = ++cnt;
        }

        g[number[a]].push_back(number[b]);
        g[number[b]].push_back(number[a]);
        //  cout << a << " " << b << " " << number[a] << " " << number[b] << endl;
        par[number[b]] = number[a];
        //visited[i] = false;
    }
    foru(i, 1, 500){
        if(par[i] == 0){
            par[i] = -1;
        }
    }

    dfs(1, -1);
    if(check){
        int c = 1, d = 2, cnt_one = 0, cnt_two = 0, wait_one = 0, wait_two = 0;
        while(par[c] != -1 || par[d] != -1){

            if(par[c] != -1){
                c = par[c];
                cnt_one++;
            }

            if(par[d] != -1){
                d = par[d];
                cnt_two++;
            }
           
            
            // cout << c << " " << d << " " << visited[c] << " " << visited[d] << endl;
            //  cout << cnt_one << " " << cnt_two << " " << par[2] << " " << par[1] << endl;

            if(c == 2 || d == 1){
                if(c == 2){
                    cout << cow_two << " is the ";
                    foru(j, 3, cnt_one){
                        cout << "great-";
                    }
                    if(cnt_one >= 2) cout << "grand-";
                    cout << "mother of " << cow_one;
                }
                else if(d == 1){
                     cout << cow_one << " is the ";
                    foru(j, 3, cnt_two){
                        cout << "great-";
                    }
                    if(cnt_two >= 2) cout << "grand-";
                    cout << "mother of " << cow_two;
                }
                return;
            }


            // special case: 
            // wrong code : if((visited[c] && cnt_one == 1)  || (visited[d] && cnt_two == 1))
            // reason:

            //   ...
            //   5
            //   3
            // x   2
            // y
            // z
            //...
            // 1
            // so the distance is not equal 1, 
            //instead of this we can check any of two 1, 2 have distance 1 to common node
            // by check parent
            
            if((visited[c] && par[2] == c)  || (visited[d] && par[1] == d)){
                
                if(par[1] == d){
                        cout << cow_one << " is the ";
                        foru(j, 3, cnt_two){
                            cout << "great-" ;
                        }
                        cout << "aunt of "  << cow_two;
                }
                else if(par[2] == c){
                    cout << cow_two << " is the ";
                    foru(j, 3, cnt_one){
                        cout << "great-";
                    }
                    cout << "aunt of " << cow_one;
                
                }

                return;
            }

            if(c == d){
                if(cnt_one == 1 && cnt_two == 1){
                    cout << "SIBLINGS";
                    return;
                }
                else{
                    cout << "COUSINS";
                }
                return;
            }


            visited[c]  = visited[d] = true;
            
        }
    }
    else cout << "NOT RELATED";

}
signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    solve();
}