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
