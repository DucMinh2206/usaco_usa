
// Another solution:
// We know that spiral always can fill a rectangle, so we can brute force until the rectangle is fully filled. 
// That is a idea of solution hihi
//Ice Bear

// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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
using ld = long double;

const string name_minh = "input";
const int maxN = 50 + 5;
const int maxK = maxN * maxN + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> counter_x = {-1, 0, 1, 0};
vector<int> counter_y = {0, -1, 0, 1};
vector<int> normal_x = {-1, 0, 1, 0};
vector<int> normal_y = {0, 1, 0, -1};

int n, m, k, cnt, curr;
int grid[maxN][maxN];
void update(int x, int y){

    //cout << x << " " << y << endl;

    if(x < 1 || x > n || y < 1 || y > m) return;
    cnt++;
    grid[x][y] = min(grid[x][y], curr);
}
void solve(){
    cin >> n >> m >> k;
    foru(i, 1, n){
        foru(j, 1, m){
            grid[i][j] = inf;
        }
    }

    foru(i, 1, k) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> dx, dy;

        if(c == 0){
            dx = normal_x;
            dy = normal_y;
        }
        else{
            dx = counter_x;
            dy = counter_y;
        }
        int idx = 0, j = 1, addd = 2;

        cnt = 0, curr = 1;
        update(a, b);
        curr++;

        while(cnt < n * m){
            if(addd == 0){
                j++;
                addd = 2;
            }

            foru(p, 1, j){
                a += dx[idx];
                b += dy[idx];

                update(a, b);
                curr++;
            }

            idx = (idx + 1) % 4;
            addd--;
        }
    }

    foru(i, 1, n){
        foru(j, 1, m){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


}

signed  main() {
    IOS

    // #ifndef MINHDEPTRAI 
    // freopen((name_minh + ".txt").c_str(), "r", stdin);
    //  freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif

    solve();

  
}