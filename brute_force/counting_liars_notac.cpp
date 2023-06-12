

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
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define int long long

const int maxN = 1000 + 5;
const long long inf = 1e17;
pair<char, int> arr[maxN]; 

signed main(){
    freopen("minh.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    foru(j, 1, n){
        cin >> arr[j].first >> arr[j].second;
    }
    #ifdef MINHDEPTRAI
    auto start =   high_resolution_clock::now();
    #endif

     int ans = inf;
    foru(i, 1, n){
        int lie_one = 0, lie_two = 0;
        if(arr[i].first == 'G'){
            foru(j, 1, n){
                if(j != i){
                    if(arr[j].first == 'G'){
                        if(arr[j].second >= arr[i].second) lie_two++;
                    }

                    if(arr[j].first == 'L'){
                        if(arr[j].second < arr[i].first) lie_one++;
                    }

                }
            }
        }
        else{
            foru(j, 1, n){
                if(j != i){
                    if(arr[j].first == 'G'){
                        if(arr[j].second > arr[i].second)lie_one++;
                    }
                    if(arr[j].first == 'L'){
                        if(arr[j].second < arr[i].second)lie_two++;
                    }
                }
            }
        }
        if(lie_one == 0){
            ans = min(ans, lie_two + 1);
        }
        else if(lie_one > lie_two){
            ans = min(ans, lie_two + 1);
        }
        else ans = min(ans, lie_one);
    }
    cout << ans << endl;



    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() << "ms";
    #endif

}
