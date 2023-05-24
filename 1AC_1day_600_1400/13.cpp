#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin >> S;

    repp(i, A, max(C, D)) {
        if (S[i] == '#' && S[i + 1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (C < D) {
        cout << "Yes" << endl;
        return 0;
    }
    repp(i, B - 1, D) {
        if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
