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
    string S, T;
    cin >> S >> T;

    int cnt = 0;
    rep(i, N) {
        if (S[i] == T[i]) {
            cnt++;
            continue;
        }
        if (S[i] == '1' && T[i] == 'l') {
            cnt++;
            continue;
        }
        if (S[i] == 'l' && T[i] == '1') {
            cnt++;
            continue;
        }
        if (S[i] == '0' && T[i] == 'o') {
            cnt++;
            continue;
        }
        if (S[i] == 'o' && T[i] == '0') {
            cnt++;
            continue;
        }
    }
    if (cnt == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}