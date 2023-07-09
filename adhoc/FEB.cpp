// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

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
const string name_minh = "hoofball";
#define int long long
const int maxN = 2e5 + 5;
const int mod = 998244353;
const long long inf = 1e17;
string s;
queue<string> current;
int used[maxN];
set<int> ans;
void check_str(string t){
    int sz = t.size();
    int cnt = 0;
    for(int i = 0; i < sz - 1; ++i){
        if(t[i] == t[i + 1]) cnt++;
    }
    if(used[cnt]) return;

    ans.insert(cnt);
}

signed main(){
    IOS
    // #ifndef MINHDEPTRAI 
    // ifstream cin(name_minh + ".in");
    // ofstream cout(name_minh + ".out");
    // #endif
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    current.push("");
    int cnt = 1;
    foru(i, 1, n){
        if(s[i] != 'F'){
            while(cnt > 0){
                string x = current.front();
                current.push(x + s[i]);
               // cout << x + s[i] << "  " << x << endl;
                current.pop();
                cnt--;
            }
        }
        else{
            while(cnt > 0){
                string x = current.front();
                current.push(x + 'B');
                current.push(x + 'E');
              //  cout << x + 'B' << " " << x + 'E' << " " << i << endl;
                current.pop();
                cnt--;
            }
        }

        cnt = current.size();
    }
    while(cnt > 0){
        string cur = current.front();
        check_str(cur);
        current.pop();
        cnt--;
    }
    cout << ans.size() << endl;
    for(int x: ans) cout << x << endl;
  

} 
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define MINHDEPTRAI 1
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
const string name_minh = "9";
#define int long long
const int maxN =1e5 + 5;
const int mod = 998244353;
const long long inf = 1e17;
// string s;
// vector<pair<string, int>> case_f;
// vector<int> current, remain;

// int cnt = 0, n;
// vector<int> merge(vector<int> a, vector<int> b){
//     // a chan
//     vector <int> ans;
//     int max_num = a[a.size() - 1] + b[b.size() - 1];
//     //out << max_num << endl;
//     if(max_num % 2 == 0){
//         if(a[0] % 2 == 0 && b[0] % 2 == 0){
//             for(int i = 0; i <= max_num; i += 2){
//                 ans.push_back(i);
//             }
//         }
//         else{
//             for(int i = 2; i <= max_num; i += 2){
//                 ans.push_back(i);
//             }
//         }
//     }
//     else{
//         for(int i = 1; i <= max_num; i += 2){
//             ans.push_back(i);
//         }
//     }

//     return ans;
// }

// vector<pair<string, int>> normal, special;
// void consider(vector<int> &current, vector<int> &remain, int start, int ed, int ad){
//     if(remain.empty()){
//         for(int j = start; j <= ed; j += ad){
//             remain.push_back(j);
//         } 
//     }
//     else{
//         for(int j = start; j <= ed; j += ad){
//             current.push_back(j);
//         }
//         remain = merge(remain, current);
//         current.clear();
//     }
//     return;
// }

// vector<int> solve(){
//     vector <int> current, remain;
//     for(pair<string, int> pa : normal){
//         // TH bien
//         int sz = pa.first.size();
//        // cout << pa.first << " " << pa.second << endl;
//         if(pa.second == -1){
//             //consider(current, remain, 0, sz, 1);
//             continue;
//         }
//         else{
//             // TH chan
//             if(pa.first.size() % 2 == 0){
//                 if(pa.second == 0){
//                     consider(current, remain, 0, sz, 2);
//                 }
//                 if(pa.second == 1){
//                    consider(current, remain, 1, sz + 1, 2); 
//                 }
//             }
//             else{
//                 if(pa.second == 0){
//                     consider(current, remain, 1, sz, 2);
//                 }
//                 if(pa.second == 1){
//                     consider(current, remain, 0, sz + 1, 2);
//                 }
//             }
//         }
//     }

//     return remain;
// }

// vector<int> merge_spe(vector<int> a, vector<int> b){
//     int a_sz = a.size(), b_sz =b.size();
//     if(a.empty()) return b;
//     if(b.empty()) return a;

//     int max_num = a[a.size() - 1] + b[b.size() - 1];
//     vector<int> num;

//     int start = 0;
//     if(a[0] % 2 == 1) start = 1;

//     foru(i, start, max_num){
//         num.push_back(i);
//     }

//     return num;
// }

// signed main(){
//     IOS
//     // #ifdef MINHDEPTRAI 
//     // ifstream cin(name_minh + ".in");
//     // ofstream cout(name_minh + ".out");
//     // #endif
//     cin >> n;
//     cin >> s;
//     s = " " + s;

//     string ss = "";
//     int st = 1, cnt = 0;

//     foru(i, 1, n){
//         //cout << cnt << " " << st << endl;
//         if(s[i] == 'F'){
//             if(cnt == 0) st = i;
//             cnt++;
//         }
//         else{

//             if(cnt > 0) {
//                 if(st == 1){
//                     case_f.push_back(mp(s.substr(st, cnt), -1));
//                 }
//                 else{

//                     if(s[st - 1] == s[i]) case_f.push_back(mp(s.substr(st, cnt), 1));
//                     else case_f.push_back(mp(s.substr(st, cnt), 0));
//                 }
//             }
//             cnt = 0;
//         }
//     }

//     if(cnt == n){
//         cout << n << endl;
//         foru(i, 0, 9){
//             cout << i << endl;
//         }
//         return 0;
//     }

//     if(cnt > 0) case_f.push_back(mp(s.substr(st, cnt), -1));

//     // ban dau truoc khi cong vao
//     int ad = 0;
//     foru(i, 1, n - 1){
//         if(s[i] == s[i + 1] && s[i] != 'F'){
//             ad++;
//         }
//     }
    
//     for(pair<string, int> x : case_f){
//         if(x.first.size() == 1 && x.second == 0){
//             ad++;
//             continue;
//         }
//        // cout << x.first << " " << x.second << endl;
//         if(x.second == -1){
//             special.push_back(mp(x.first, x.second));
//         }
//         else normal.push_back(mp(x.first, x.second));
//     }    
//     vector<int> ans = solve();


//     for(pair<string, int> x: special){
//         int sz = x.first.size();
//         vector<int> merged;
//         for(int j = 0; j <= sz; j++){
//             merged.push_back(j);
//         }

//         ans = merge_spe(ans, merged);
//     }

//     cout << ans.size() << endl;
//     for(int x: ans) cout << x + ad << endl;

// }
