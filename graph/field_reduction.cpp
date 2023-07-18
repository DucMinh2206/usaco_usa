
// My idea is calculating the array that we remove 3 point that have x biggest, 3 point that have x smallest, same to y.
// So we have 12 point to consider, and we can calculate in O(logn) if we remove 3 elements in 12 elements instead of O(n).

// #define MINHDEPTRAI 1
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
#define forr(i, l, r) for (int i = (l); i < (r); ++i)
#define IOS cin.tie(0),cout.tie(0)->sync_with_stdio(0);
#define mp(a, b) make_pair(a, b)
#define int long long
typedef pair<int, int>  pii;
typedef pair<pair<int, int>, int> piii;
#define endl '\n'
using ld = long double;

const string name_minh = "reduce";
const int maxN = 5e4 + 5;
const int maxM = 4e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;

pair<pair<int,int>, int> number[maxN], number_two[maxN];
set<pair<int, int>> num;
// sort theo x, y
bool cmp_x(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
    if(a.first.first == b.first.first) return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}


bool cmp_y(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
      if(a.first.second == b.first.second) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}


map<pair<int, int>, int> cnt;
int n;

int cnt_one, cnt_two, middle, ans = inf;

vector<int> consider;
bool used[maxN];
void for_contidition(){
    sort(number + 1, number + 1 + n, cmp_x);

    for(int i = 1; i <= 3; i++){
        if(used[number[i].second]) continue;

        consider.push_back(number[i].second);
        used[number[i].second] = true;
    }

     for(int i = n; i >= n - 3 && i >= 1; i--){
        if(used[number[i].second]) continue;

        consider.push_back(number[i].second);
        used[number[i].second] = true;
    }

 

    sort(number + 1, number + 1 + n, cmp_y);

    for(int i = 1; i <= 3; i++){
        if(used[number[i].second]) continue;

        consider.push_back(number[i].second);
        used[number[i].second] = true;
    }

    for(int i = n; i >= n - 3; i--){
        if(used[number[i].second]) continue;

        consider.push_back(number[i].second);
        used[number[i].second] = true;
    }

}

multiset<pair<int, int>, greater<pii>> num_x, num_y;

void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> number[i].first.first >> number[i].first.second; 
       
        number[i].second = i;
        number_two[i] = number[i];
        cnt[mp(number[i].first.first, number[i].first.second)]++;
        
        num_x.insert(mp(number[i].first.first, number[i].first.second));
        num_y.insert(mp(number[i].first.second, number[i].first.first));
    }

    for_contidition();

    int sz = consider.size() - 1;
    multiset<pair<int, int>> :: iterator max_x, max_y;
    multiset<pair<int, int>> :: reverse_iterator min_x, min_y;

    foru(i, 0, sz - 1){
        foru(j, i + 1, sz - 1){
            foru(k, j + 1, sz - 1){

                pair<int, int> val_i = mp(number_two[consider[i]].first.first, number_two[consider[i]].first.second);
                pair<int, int> val_j = mp(number_two[consider[j]].first.first, number_two[consider[j]].first.second);
                pair<int, int> val_k = mp(number_two[consider[k]].first.first, number_two[consider[k]].first.second);

                cnt[val_i]--;
                cnt[val_j]--;
                cnt[val_k]--;

                num_x.erase(num_x.find(val_i));
                num_x.erase(num_x.find(val_j)); 
                num_x.erase(num_x.find(val_k));

                num_y.erase(num_y.find(mp(val_i.second, val_i.first)));
                num_y.erase(num_y.find(mp(val_j.second, val_j.first)));
                num_y.erase(num_y.find(mp(val_k.second, val_k.first)));

         
                max_x = num_x.begin();
                min_x = num_x.rbegin();
                min_y = num_y.rbegin();
                max_y = num_y.begin();

                ans = min((max_x->first - min_x->first) * (max_y->first - min_y->first), ans);


                num_x.insert(val_i);
                num_x.insert(val_j); 
                num_x.insert(val_k);

                num_y.insert(mp(val_i.second, val_i.first));
                num_y.insert(mp(val_j.second, val_j.first));
                num_y.insert(mp(val_k.second, val_k.first));

                cnt[val_i]++;
                cnt[val_j]++;
                cnt[val_k]++;

            }
        }
    }
  
    cout << ans << endl;
}
signed  main() {
    IOS

    #ifndef MINHDEPTRAI 
    freopen((name_minh + ".in").c_str(), "r", stdin);
    freopen((name_minh + ".out").c_str(), "w", stdout);
    #endif
    
    solve();
}