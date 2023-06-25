// Special case if n == 1 then a first cow is a second cow because we only have one cow.
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
const string name_minh = "notlast";
const int maxN = 1e3 + 5;
const int mod = 1000000007;
const long long inf = 1e17;

map<int, vector<string>> cows;
map<string, int> current;
string a;
int val;
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif

    int n;
    cin >> n;

    foru(i, 1, n){

        cin >> a  >> val;
        current[a] += val; 
    }
    
    map<string, int> :: iterator it;
    map<int, vector<string>> :: iterator it_2;
    for(it = current.begin(); it != current.end(); it++){
        cows[it -> second].push_back(it -> first);
    }
    int cnt = 0;
    for(it_2 = cows.begin(); it_2 != cows.end(); it_2++){
        cnt++;
        if(cnt == 2){
            if(it_2 -> second.size() >= 2){
                cout << "Tie" << endl;
            }
            else cout << it_2 -> second[0] << endl;
            return 0;
        }
    }

    if(cnt == 1){
        if(n == 1) cout << a << endl;
        else cout << "Tie" << endl;
    }
    return 0;
}
