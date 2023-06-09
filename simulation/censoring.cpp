
//BRUTE

#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
#define endl '\n'
#define int ll

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18;
signed main(){
    IOS;
    //  ifstream cin("in.txt");
    //  ofstream cout("4out.txt");
    string s, t;
    cin >> s;
    cin >> t;
    bool check = true;
    int j;
    while(check){
        j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[j]){
                j++;

                if(j == t.size()) {
                    s.erase(s.begin() + i - j + 1, s.begin() + i + 1);
                    break;
                }
            }else{
                j = 0;
                if(s[i] == t[j])j++;
            }
        }
        if(j != t.size()){
            check = false;
        }

    }
    cout << s << endl;
}
