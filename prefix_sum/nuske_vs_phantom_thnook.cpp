// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"

// TNB : the number of, CC : connected component
// for this problem we have one thing is in tree TNB vertex - TNB edge = 1
// So if we can see here CC is the tree with vertex are blue grid and edge are horizontal and vertical which connect two adjacent grid
// So if we want calculate TNB of CC = TNB of tree = TNB vertex - TNB edge.
// O(N * M + Q).

#ifdef MINHDEPTRAI
 
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
#include <chrono>
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
 
const string name_minh = "lazy";
const int maxN = 4e2 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;
int grid[maxN][maxN];
int vertex[maxN][maxN], edge_ngang[maxN][maxN], edge_doc[maxN][maxN];
string s[maxN];
int sum_square(int i, int j, int c, int d, int arr[][maxN]){
      return arr[c][d] + arr[i - 1][j - 1] - arr[c][j - 1] - arr[i - 1][d];

}
void solve(){
      int n, m, q;
      cin >> n >> m >> q;

      foru(i, 1, n){
            cin >> s[i];
            s[i] = " " + s[i];
      }

      foru(i, 1, n){
            foru(j, 1, m){

                  grid[i][j] = s[i][j] - '0';
                  if(grid[i][j] == 1){
                        if(grid[i - 1][j] == 1) edge_doc[i][j]++;
                        if(grid[i][j - 1] == 1) edge_ngang[i][j]++;
                  }
                  vertex[i][j] = vertex[i - 1][j] + vertex[i][j - 1] + grid[i][j] - vertex[i - 1][j - 1];
                  edge_ngang[i][j] += edge_ngang[i - 1][j] + edge_ngang[i][j - 1] - edge_ngang[i - 1][j - 1];
                  edge_doc[i][j] += edge_doc[i - 1][j] + edge_doc[i][j - 1] - edge_doc[i - 1][j - 1];
            }
      }



      foru(i, 1, q){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int sum = sum_square(a, b, c, d, vertex);
            if(a < c) {
                  sum -= sum_square(a + 1, b, c, d, edge_doc);
            }
            if(b < d){
                  sum -= sum_square(a, b + 1, c, d, edge_ngang);
            }
            cout << sum << endl;
      }
      
}
signed  main() {
      IOS 
//     #ifndef MINHDEPTRAI 
//     freopen((name_minh + ".in").c_str(), "r", stdin);
//      freopen((name_minh + ".out").c_str(), "w", stdout);
//     #endif

    int t = 1;
    while(t--){
        solve();
    }
  
}