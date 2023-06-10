//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"  
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
#define foru(i, a, b) for(int i = a; i <= b; ++i)
#define ford(i, a, b) for(int i = a; i >= b; --i)
#define mp(a, b) make_pair(a, b)
vector<pair<int, pair<string, int>>> current;
bool cmp(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b){
    return a.first < b.first;
}

map<string, int> cnt;
string arr[5] = {"Mildred", "Elsie", "Bessie"}; 
int sum, max_val = 7, cnt_max_val = 3;
signed main(){
   int n;
   cin >> n;
   freopen("measurement.in", "r", stdin);
   freopen("measurement.out", "w", stdout);

   foru(i, 1, n){
      int x, val;
      string s;
      char dau;

      cin >> x >> s >> dau >> val;
      current.push_back(mp(x, mp(s, val)));
   }
   sort(current.begin(), current.end(), cmp);

   foru(i, 0, 2) cnt[arr[i]] = 7;
   
   for(pair<int, pair<string, int>> num : current){
        string ss = num.second.first;
        int add = num.second.second;
        if(add > 0){
            if(cnt[ss] == max_val){
                cnt[ss] += add;
                // max_val
                max_val = cnt[ss];
                cnt_max_val = 1;

                // ans
                sum++;
            }
            else{
                cnt[ss] += add;

                if(cnt[ss] >= max_val){
                    cnt_max_val = (cnt[ss] == max_val)  ? ++cnt_max_val : 1;

                    max_val = cnt[ss];
                    sum++;
                }
            }
        }
        else{
            if(cnt[ss] == max_val){
                if(cnt_max_val > 1){
                    cnt[ss] -= add;
                    cnt_max_val--;

                    sum++;
                }
                else if(cnt_max_val == 1){
                    cnt[ss] -= add;
                    
                    max_val = 0, cnt_max_val = 0;
                    foru(i, 0, 2){
                        if(cnt[arr[i]] > max_val){
                            max_val = cnt[arr[i]];
                            cnt_max_val = 1;
                        }
                        if(cnt[arr[i]] == max_val) cnt_max_val++;
                    }
                }
            }
        }
   }

   cout << sum;

}
