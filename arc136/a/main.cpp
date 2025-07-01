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

    rep(i, N - 1) {
        if (S[i] == 'B' && S[i + 1] == 'B') {
            S[i] = 'A', S[i + 1] = 'X';
        } else if (S[i] == 'B' && S[i + 1] == 'A') {
            swap(S[i], S[i + 1]);
        }
    }

    rep(i, N) {
        if (S[i] == 'X') continue;
        cout << S[i];
    }

    cout << endl;
}
