//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 1000 + 5;
const long long inf = 1e17;
pair<int, int> coor[maxN];

int check(int x, int y, int z){
    int x1 = coor[x].first;
    int y1 = coor[x].second;

    int x2 = coor[y].first;
    int y2 = coor[y].second;

    int x3 = coor[z].first;
    int y3 = coor[z].second;

    if(x1 == x2 && y1 == y3) return (y2 - y1) * (x3 - x1);

    if(x1 == x3 && y1 == y2) return (y3 - y1) * (x2 - x1);

    if(x2 == x1 && y2 == y3) return (y2 - y1) * (x3 - x2);

    if(x2 == x3 && y2 == y1)  return (y3 - y2) * (x2 - x1);

    if(x3 == x1 && y3 == y2) return (y3 - y1) * (x3 - x2);

    if(x3 == x2 && y3 == y1) return (y3 - y2) * (x3 - x1);

    return -1;
}
signed main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;
    foru(i, 1, n){
        cin >> coor[i].first >> coor[i].second;
    }
    sort(coor + 1, coor + n + 1);
    int ans = 0;

    foru(i, 1, n){
        foru(j, i + 1, n){
            foru(k, j + 1, n){
                int val = check(i, j, k);
               // cout << val << " " << i << " " << j << " " << k << endl;
                if(val > 0){
                    // cout << coor[i].first << " " << coor[i].second << " " << coor[j].first << " " << coor[j].second << " " << coor[k].first << " " << coor[k].second << endl;
                    // cout << val << endl;
                    ans = max(ans, val);
                }

            }
        }
    }

    cout << ans;
}
