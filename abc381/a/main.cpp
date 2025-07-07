#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }

    rep(i, N / 2) {
        if (S[i] != '1') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (S[N / 2] != '/') {
        cout << "No" << endl;
        return 0;
    }
    repp(i, N / 2 + 1, N) {
        if (S[i] != '2') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
