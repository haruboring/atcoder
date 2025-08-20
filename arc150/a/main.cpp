#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return a + b; }
int e() { return 0; }

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        vector<int> one(N), zero(N);
        rep(i, N) {
            if (S[i] == '1') one[i] = 1;
            if (S[i] == '0') zero[i] = 1;
        }

        atcoder::segtree<int, op, e> oneseg(one), zeroseg(zero);
        int one_cnt = oneseg.prod(0, N);

        if (one_cnt > K) {
            cout << "No" << endl;
            continue;
        }

        int cnt = 0;
        for (int i = 0; i < N - K + 1; i++) {
            if (oneseg.prod(i, i + K) != one_cnt) continue;
            if (zeroseg.prod(i, i + K) == 0) cnt++;
        }

        if (cnt == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
