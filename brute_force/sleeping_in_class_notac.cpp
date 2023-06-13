
#define MINHDEPTRAI 1
#ifdef MINHDEPTRAI
#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <chrono>
using namespace std ::chrono;
#else 
#include <bits/stdc++.h>
#endif

using namespace std;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define IOS ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp(a, b) make_pair(a, b)

const int maxN = 1e5  + 5;
const long long inf = 1e9;
int arr[maxN];
map<int, int> cnt, before;
void prime_factor(int val){
    if(val <= 1){
        return;
    }

    int before_val = val;
    while(val % 2 == 0){
        val = val / 2;
        cnt[2] = 1;
    }

    foru(j, 3, sqrt(before_val)){
        while(val % 3 == 0){
            val = val / 3;
            cnt[3] = 1;
        }
    }
    if(val > 2){
        cnt[val] = 1;
    }
}
int t;
signed main(){
    IOS
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    // input
   
    // end
    #ifdef MINHDEPTRAI
    auto start =  high_resolution_clock::now();
    #endif
    // running

    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;

        foru(i, 1, n){
            cin >> arr[i];
            sum += arr[i];
        }
        
        prime_factor(sum);
        int sum_check = 0;
        // check condition full equal
        foru(i, 2, n){
            if(arr[i] == arr[1]){
                sum_check++;
            }
        }

        if(sum_check == n - 1){
            cout << 0 << endl;
            continue;
        }
       
        int ans = inf;
        map<int, int>:: iterator it;
        cnt[1] = 1;

        for(it = cnt.begin(); it != cnt.end(); it++){
            cout << it -> first << " " << sum  << endl;
            
            int j = 1, check_ans = 0, curr = 0;

            int need_occurrence = it -> first;
            int need_val = sum / need_occurrence;

            if(need_occurrence > n) continue;

            while(j <= n){
                if(curr < need_val){
                    curr += arr[j];
                }
                if(curr > need_val){
                    break;
                }
                if(curr == need_val){
                    check_ans += curr;
                    curr = 0;
                }
                j++;
            }

            if(check_ans == sum){
                ans = min(n - need_occurrence, ans);
            }
            else continue;
            
        }
        cout << ans << endl;
        cnt = before;

    }
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << exacution.count() << "ms";
    #endif
}
