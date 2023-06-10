//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>
using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define int long long
#define mp(a, b) make_pair(a, b)
#define endl '\n'

const int maxN = 55;
const int inf = 1e17;

signed main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int a, b, c, d;
    int e, f, g, h;

    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;

    int side = max(max(d, h) - min(b, f), max(c, g) - min(a, e));
    cout << side * side;
}
