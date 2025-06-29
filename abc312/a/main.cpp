#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    string T = " ACE、BDF、CEG、DFA、EGB、FAC、GBD の";
    rep(i, T.size()-2){
        if (S==T.substr(i, 3)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
