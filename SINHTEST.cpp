#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define MINHDEPTRAI "Volumes/icebear/source_code/VS_code"
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

const string name_minh = "IMPOSSIBLE";
const int maxN = 2e5 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

signed main(){
	mt19937 mt{static_cast<std :: mt19937 :: result_type> (
		std::chrono::high_resolution_clock :: now().time_since_epoch().count()
	)};
    
	//ofstream inp("input.txt");

	uniform_int_distribution ran_n{1, 10}, ran_num{1, 15};
	for(int i = 1; i <= 1000; i++){
		ofstream inp("input.txt");

		int n = ran_n(mt), m = ran_n(mt), s = ran_num(mt), A = ran_n(mt), B = ran_n(mt);
		inp << n << " " << m << " " << s << " " << A << " " << B << endl;
		
		foru(i, 1, n){
			inp << ran_num(mt) << " ";
		}

		inp << endl;
		foru(i, 1, m){
			inp << ran_num(mt) << " ";
		}
		inp << endl;

		inp.close();

		system("./main");
		system("./CODE_BRUTE");

		if(system("diff input2.txt input3.txt") != 0){
			cout << "Test " << i << ": Wrong" << endl;
			return 0;
		}
		else cout << "Test " << i << ": Correct" << endl;
	}
	
	return 0;
}
ource_code/VS_code"
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
#define fi first
#define se second 
using ld = long double;

const string name_minh = "input";
const int maxN = 1500 + 5;
const int maxK =  1e4 + 5e3;
const int mod = 1e9 + 7;
const long long inf = 1e18;

// Cramer's rule: D = a1 * b2 - b1 * a2, Dx = c1 * b2 - b1 * c2, Dy = a1 * c2 - c1 * a2.
// Two-point formula: (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1);
// Distance from a line to a point: |ax0 + by0 + c| / sqrt(a^2 + b^2);
// Angle between two vectors: |a1 * a2 + b1 * b2| / (sqrt(a1^2 + b1^2) * sqrt(a2^2 + b2^2));
// Area of a polygon with n vertices: |x1 * y2 - x2 * y1 + x2 * y3 - y3 * x2 + ... + xn * y1 - x1 * yn| / 2 (integer);
// Coefficients of a straight line: x0, y0, n(a, b) => a(x - x0) + b(y - y0) = 0;

int dp[maxN][maxN][30];
string s;
void solve(){
    int n;
    cin >> n;

    cin >> s;
    s = " " + s;

    foru(k, 0, 25){
        foru(i, 1, n){
            foru(j, 1, n){
                if(s[i] == char(k + 'a')){
                    dp[i][j][k] =  dp[i - 1][j][k] + 1;
                }
                else dp[i][j][k] = dp[i - 1][j - 1][k] + 1;
            }
            
        }
    }

    foru(k, 0, 25){
         foru(i, 1, n){
            foru(j, 1, n){
                if(j == 1 && k + 'a' == 'o') cout << i << " " << dp[i][j][k] << endl;
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }

    int q;
    cin >> q;
    foru(i, 1, q){
        int val;
        char c;
        cin >> val >> c;
        cout << dp[n][val][c - 'a'] << endl;
    }
}

signed  main() {
    IOS
    int t = 1;
    // #ifndef MINHDEPTRAI
    // freopen((name_minh + ".in").c_str(), "r", stdin );
    // freopen((name_minh + ".out").c_str(), "w", stdout);
    // #endif

    // #ifdef MINHDEPTRAI
    // freopen((name_minh + ".txt").c_str(), "r", stdin );
    // freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif
    while(t--) {
        solve();
    }
}
