
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
const string name_minh = "angry";
const int maxN = 1e3 + 5;
const int mod = 1000000007;
const long long inf = 1e17;
int n, arr[maxN];
signed main(){
    IOS
    #ifndef MINHDEPTRAI 
    ifstream cin(name_minh + ".in");
    ofstream cout(name_minh + ".out");
    #endif
    cin >> n;

    foru(i, 1, n){
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    int ans = 0;
    foru(i, 1, n){
        bool under = true, up = true;
        int curr_l = i, curr_r = i, cnt = 0;

        while(under || up){
            cnt++;
            // cout << dis_one << " " << dis_two << " " << i << " " << cnt << endl;
            int max_pos = -inf, min_pos = -inf;
            for(int l = max(1ll, curr_l - cnt); l <= curr_l && under; l++){
                if(arr[curr_l] - arr[l] > 0 && arr[curr_l] - arr[l] <= cnt){
                    //cout << curr_l << " l " << l << " " << i << endl;
                    min_pos = l;
                    curr_l = l;

                    break;
                }
            }

            for(int r = min(curr_r + cnt, n); r >= curr_r && up; r--){
                if(arr[r] - arr[curr_r] > 0 && arr[r] - arr[curr_r] <= cnt){
                    max_pos = r;
                    curr_r = r;

                    //cout << curr_r << " r " << r << " " << i << endl;
                    break;
                }
            }

            if(min_pos == -inf) under = false;
            if(max_pos == -inf) up = false;
            // cout << curr_l << " " << curr_
        }

        //cout << curr_r << " " << curr_l << " " << arr[i] << endl;
        ans = max(ans, curr_r - curr_l + 1);
        //cout << r - l - 1 << " " << i << endl;
    }

    cout << ans;
}
