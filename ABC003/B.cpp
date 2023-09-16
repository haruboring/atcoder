#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;
    if (S.size() != T.size()) {
        cout << "You will lose" << endl;
    } else {
        bool correct = true;
        set<char> ok = {'@', 'a', 't', 'c', 'o', 'd', 'e', 'r'};
        rep(i, S.size()) {
            if (S[i] == '@') {
                if (ok.count(T[i]) == false) {
                    correct = false;
                }
            }
            else if (T[i] == '@') {
                if (ok.count(S[i]) == false) {
                    correct = false;
                }
            }
            else if(S[i] != T[i]){
                correct = false;
            }
        }
        if (correct) {
            cout << "You can win" << endl;
        } else {
            cout << "You will lose" << endl;
        }
    }
}