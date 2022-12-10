#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int size = S.size();
    if (size != 8) {
        cout << "No" << endl;
        return 0;
    }
    if (S[0] >= 'A' && S[0] <= 'Z') {
        if (S[7] >= 'A' && S[7] <= 'Z') {
            S = S.substr(1, 6);
            bool b = true;
            rep(i, 6) {
                if (!(S[i] >= '0' && S[i] <= '9')) {
                    b = false;
                }
            }
            if (b) {
                int st = stoi(S);
                if (st >= 100000 && st <= 999999) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}