
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
const int maxN = 1e3 + 5;
const int mod = 1000000007;
const long long inf = 1e17;
int n, arr[maxN];
multiset<int> number;
int remaining(multiset<int> a){
    int cnt = 1, sum = 0;
    for(int num : a){
        if(cnt == 0) sum += num;
        else sum -= num;

        cnt++;
        cnt %= 2;
    }
    return sum;
}
signed main(){

    cin >> n;
    n *= 2;
    foru(i, 1, n){
        cin >> arr[i];
        number.insert(arr[i]);
    }

    int ans = inf;
    foru(i, 1, n){
        foru(j, i + 1, n){
           int num_one = arr[i], num_two = arr[j];
           number.erase(number.find(arr[i]));
           number.erase(number.find(arr[j]));
           //cout << remaining(number) << " " << i << " " << j << endl;
           ans = min(ans, remaining(number));
           //cout << remaining(number) << " " << i << " " << j << endl;

           number.insert(num_one), number.insert(num_two);
        }
    }

    cout << ans;
}
