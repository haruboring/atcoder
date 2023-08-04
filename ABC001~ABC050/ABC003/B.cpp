#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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