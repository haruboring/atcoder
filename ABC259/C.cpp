#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    int T_size = T.size(), S_size = S.size();
    int S_index = 0;
    rep(i, T_size) {
        if (S_index > S_size) {
            cout << "No" << endl;
            return 0;
        }
        if (T[i] == S[S_index]) {
            S_index++;
        } else {
            if (S_index >= 1) {
                if (S[S_index - 2] == S[S_index - 1] && S[S_index - 1] == T[i]) {
                    continue;
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}