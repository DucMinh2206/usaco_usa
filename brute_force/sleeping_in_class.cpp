
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

const int maxN = 1000 + 5;
const long long inf = 1e17;
int arr[maxN];
map<int, int> cnt;
void prime_factor(int val){
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
        int check = arr[1];
        bool ans = false;
        // check condition full equal
        foru(i, 1, n){
            if(check != arr[i]) break;

            if(i == n){
                check = true;
                break;
            }
        }
        if(check == true){
            cout << "0";
            continue;
        }

        map<int, int>:: iterator it;
        int ans = 0;
        bool check_ans = false;
        for(it = cnt.begin(); it != cnt.end(); it++){
            int val = it -> first;
            if(sum / val > n) continue;

            int current = 0, counting = 0;
            foru(i, 1, n){
                current = arr[i];
                if(current > sum / val) continue;
                if(current == sum / val){
                    continue;
                }

                foru(j, i + 1, n){
                    current += arr[j];
                    if(current == sum / val){
                        i = j + 1;
                        counting++;
                        break;
                    }
                }
            }
            

        }

    }
    // end
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() / 1000 << "ms";
    #endif
}
