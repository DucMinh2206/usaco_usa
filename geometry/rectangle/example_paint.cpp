//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define ld long double

const int maxN = 55;
const ld inf = 1e17;
int a, b, c, d;
signed main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);

    cin >> a >> b;
    cin >> c >> d;

    if(d < a || b < c){
        cout << (d - c) + (b - a);
    }
    else cout << max(b, d) - min(a, c);

}
