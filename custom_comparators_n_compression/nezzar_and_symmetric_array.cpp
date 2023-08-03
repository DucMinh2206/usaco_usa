// #define MINHDEPTRAI "/Volumes/icebear/source_code/VS_code"
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

const string name_minh = "input";
const int maxN = 2e5 + 5;
const int maxK =  3e5 + 5;
const int mod = 2019;
const long long inf = 1e18;

vector<int> d, num;
set<int> arr;
int cnt[maxN];
int compress_idx(int val){
    return lower_bound(d.begin(), d.end(), val) - d.begin();
}
// you can the array d always have n pair which d[value] = d[-value]  
// so if you want to check that for each value in d, their frequency is 2.
// we can use array count but d[i] <= 10 ^ 12, so we have to compress value

// observation: if(arr[i] > arr[j]) (abs(arr[i]) != arr[j]) => d[i] > d[j] (this is so important for my solution).
// so we can calculate the maximum value of array a and after that the second, the third, ... by math

// explanation:

// for example:
// 2
// 8 12 8 12

// in case 12
// a1 + a2 + a3 + a4 = 0 
// for example a_max = a_4
// d[4] = a[4] - a[3] + .. +a[4] - a[1]
// d[4] = 3a[4] - (...);
// and we have a4 = -a1 -a2 -a3
// d[4] = 4a[4]
// => a[4] = d[4] / 4;

// in case 8
// for example the second -largest value at pos 2
// we have array like arr[1] arr[2] -3 3
// arr[2] = 3- arr[2] + arr[2] + 3 + arr[2] - arr[1] = arr[2] - arr[1] = 2 arr[2] + 2 * arr[4]

// so we can have formula : arr[i] = d[i] - 2 * sum / current
// each time current -= 2, and sum += arr[i];


// if you want to use lower bound, you have to sort <
// and you have to traverse from largest_value -> smallest_value, so you have to create two vector

void solve(){
    int n;
    cin >> n;

    d.clear();
    arr.clear();

    bool ans = true;
    n = n * 2;

    foru(i, 1, n){
        int val;
        cin >> val;
        d.push_back(val);
        cnt[i] = 0;
    } 

    num = d;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

   
    for(int v: num) {
        cnt[compress_idx(v) + 1]++;
    }

    num = d;
    sort(num.begin(), num.end(), greater<int>());

    int sum = 0, current = n;
    for(int v: num){

        if(cnt[compress_idx(v) + 1] != 2){
            ans = false;
            break;
        }

        int val = v - sum * 2;
        if(val % current != 0 || (val <= 0)){
            ans = false;
            break;
        }
        else val = val / current;


        sum += val;
        current -= 2;

        arr.insert(val);
    }

    if(arr.size() != n / 2){
        ans = false;
    }

    if(ans){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

  
}

signed  main() {
    IOS
    // int t = 1;
    // #ifdef MINHDEPTRAI
    // freopen((name_minh + ".txt").c_str(), "r", stdin );
    // freopen((name_minh + "2.txt").c_str(), "w", stdout);
    // #endif
    int t;
    cin >> t; 
    while(t--) {
        solve();
    }
}
