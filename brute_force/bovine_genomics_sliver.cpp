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

const int maxN = 500 + 5;
const int maxM = 50 + 5;

const long long inf = 1e17;
char normal[maxN][maxM], spoty[maxN][maxM];
string current_no[maxN], current_spo[maxN];

void plus_no(string &ss, int a, int b, int c, int p){
    ss = "";
    ss += normal[p][a];
    ss += normal[p][b];
    ss += normal[p][c];
}

void plus_spo(string &ss, int a, int b, int c, int p){
    ss = "";
    ss += spoty[p][a];
    ss += spoty[p][b];
    ss += spoty[p][c];
}

signed main(){
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // input

    int n, m;
    cin >> n >> m;
    foru(i, 1, n){
        foru(j, 1, m){
            cin >> spoty[i][j];
        }
    }

    foru(i, 1, n){
        foru(j, 1, m){
            cin >> normal[i][j];
        }
    }

    // end
    #ifdef MINHDEPTRAI
    auto start =   high_resolution_clock::now();
    #endif

    // running
    int ans = 0;
    foru(i, 1, m){
        foru(j, i + 1, m){
            foru(k, j + 1, m){
                bool check = false;
                set<string> curr_fi, curr_se, curr_megre;
                foru(p, 1, n){
                    plus_no(current_no[p], i, j, k, p);
                    curr_fi.insert(current_no[p]);
                }

                foru(p, 1, n){
                    plus_spo(current_spo[p], i, j, k, p);
                    curr_se.insert(current_spo[p]);
                }
                // merge time
                curr_megre = curr_fi;
                for(string s: curr_se) curr_megre.insert(s);

                if(curr_megre.size() == curr_fi.size() + curr_se.size()){
                    ans++;
                }

            }
        }
    }
    cout << ans;
    // end
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() / 1000 << "ms";
    #endif
    
}



// CACH 2
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

const int maxN = 500 + 5;
const int maxM = 50 + 5;

const long long inf = 1e17;
char normal[maxN][maxM], spoty[maxN][maxM];
string current_no[maxN], current_spo[maxN];

void plus_no(string &ss, int a, int b, int c, int p){
    ss = "";
    ss += normal[p][a];
    ss += normal[p][b];
    ss += normal[p][c];
}

void plus_spo(string &ss, int a, int b, int c, int p){
    ss = "";
    ss += spoty[p][a];
    ss += spoty[p][b];
    ss += spoty[p][c];
}

signed main(){
    IOS
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    // input

    int n, m;
    cin >> n >> m;
    foru(i, 1, n){
        foru(j, 1, m){
            cin >> spoty[i][j];
        }
    }

    foru(i, 1, n){
        foru(j, 1, m){
            cin >> normal[i][j];
        }
    }

    // end
    #ifdef MINHDEPTRAI
    auto start =  high_resolution_clock::now();
    #endif

    // running
    int ans = 0;
    foru(i, 1, m){
        foru(j, i + 1, m){
            foru(k, j + 1, m){
                bool check = false;
                map<string, int> cnt;
                foru(p, 1, n){
                    plus_no(current_no[p], i, j, k, p);
                    cnt[current_no[p]]++;
                }

                foru(p, 1, n){
                    plus_spo(current_spo[p], i, j, k, p);
                    if(cnt[current_spo[p]] >= 1){
                        check = true;
                        break;
                    }
                }

                if(!check) ans++;

            }
        }
    }
    cout << ans;
    // end
    #ifdef MINHDEPTRAI
    auto end = high_resolution_clock::now();
    auto exacution = duration_cast<microseconds> (end - start);
    cout << "  "<< exacution.count() / 1000 << "ms";
    #endif
    
}